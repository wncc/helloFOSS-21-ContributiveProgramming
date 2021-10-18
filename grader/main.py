import subprocess
import os
import argparse
import re
from shutil import copyfile


def compile(code):
    try:
        proc = subprocess.run(['g++', '-w', f'{code}', '-o', 'myexec'], stdout=subprocess.PIPE, stderr=subprocess.PIPE,
                              timeout=5)
    except subprocess.TimeoutExpired:
        print("compile time exceeded")
        exit(1)
    output = proc.stdout.decode()
    errors = proc.stderr.decode()
    assert output == '', "compilation error"
    assert errors == '', "compilation error"


def run_compiled(input_file, tle):
    copyfile(input_file, 'input.txt')
    out_file = open(f'out.out', 'w+')
    try:
        subprocess.run(['./myexec'], stdout=out_file, stderr=out_file, timeout=tle)
    except subprocess.TimeoutExpired:
        print("Time limit Exceeded")
        exit(1)
    out_file.close()


def diff_checker(output_file):
    out_file = open(f'out.out')
    test_output = out_file.read()
    expected_output = open(f'{output_file}').read()

    test_output = re.sub(r'\s+', ' ', test_output).strip()
    expected_output = re.sub(r'\s+', ' ', expected_output).strip()
    # considers just spaces between everything while comparing

    if test_output == expected_output:
        print("All test passed")
    else:
        print("failed")
    try:
        os.remove('input.txt')
        os.remove('out.out')
        os.remove('myexec')
    except:
        pass


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='autograder')
    parser.add_argument('code', type=str, help='path to .cpp file')
    parser.add_argument('i', type=str, help='path to input .txt file')
    parser.add_argument('o', type=str, help='path to output .txt file')
    parser.add_argument('tle', type=int, help='time limit for execution', const=1, default=1, nargs='?')
    args = parser.parse_args()
    code = args.code
    input_file = args.i
    output_file = args.o
    tle = args.tle
    assert os.path.splitext(code)[1] == '.cpp', 'not a .cpp file'
    assert os.path.isfile(code), 'invalid code path/directory'
    assert os.path.isfile(input_file), 'invalid input path/directory'
    assert os.path.isfile(output_file), 'invalid output path/directory'

    compile(code)
    run_compiled(input_file, tle)
    diff_checker(output_file)

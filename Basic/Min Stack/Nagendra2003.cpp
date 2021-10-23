#include"MinStack.h"
#include <iostream>
using namespace std;
MinStack::MinStack(){
    arr=new int[MAXSIZE];
    size=0;
}
void MinStack::push(int val){
    if(size>=MAXSIZE){
        cout<<"FULL"<<endl;
    }
    else{
        if(size==0){
            min_elem=val;
            arr[size]=val;
            size++;
        }
        else {
            if(val>=min_elem){
                arr[size]=val;
                size++;
            }
            else{
                arr[size]=2*val-min_elem;  //2*val-min_elem <min_elem
                size++;
                min_elem=val;
            }
        }
    }
}
int MinStack::pop(){
    if(size<=0){
        cout<<"EMPTY"<<endl;
        return 0;
    }
    else{
        int x=arr[size-1];
        size--;
        if(x>=min_elem){cout<<x<<endl;return x;}
        else{
            int val=min_elem;
            min_elem = 2*min_elem - x;
            cout<<val<<endl;
            return val;
        }
    }
}

int MinStack::top(){
    if(size<=0){
        cout<<"EMPTY"<<endl;
        return 0;
    }
    else{
        int x=arr[size-1];
        if(x>min_elem){cout<<x<<endl;return x;}
        else{
            cout<<min_elem<<endl;
            return min_elem;
        }
    }
}
int MinStack::getMin(){
    if(size<=0){
        cout<<"EMPTY"<<endl;
        return 0;
    }
    else{
        cout<<min_elem<<endl;
        return min_elem;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        MinStack *mystack=new MinStack();
        int q;
        cin>>q;
        while(q--){
            int a;
            cin>>a;
            if(a==1){
                int val;
                cin>>val;
                mystack->push(val);
            }
            else if(a==2){
                mystack->pop();
            }
            else if(a==3){
                mystack->top();
            }
            else if(a==4){
                mystack->getMin();
            }
            else{cout<<"input not compatible"<<endl;}
        }
    }
}
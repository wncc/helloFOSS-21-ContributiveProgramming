#include<bits/stdc++.h>
#include"sieve.h"

using namespace std;

//#define ll long long int

int gcd(int a, int b){
    if(a==0) return b;
    if(b==0) return a;
    if(a==b) return a;
    if(a>b) return gcd(a-b, b);
    return gcd(a, b-a);
}

const int MaxSize = 100000000;
vector<int> lp(MaxSize+1);
vector<int> pr;

void sieveEratosthenes(int n){
    for(int i=2; i<n; i++){
        if(lp[i]==0){
            lp[i] = i;
            pr.push_back(i);
        }
    
    for (int j=0; j < (int)pr.size() && pr[j] <= lp[i] && i*pr[j] <= n; ++j) lp[i*pr[j]] = pr[j];    
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> v;
    sieveEratosthenes(n);

    for(int b=0; b<m; b++){
        char s;
        int p;
        cin >> s >> p;

        if(s == '-'){
            cout << "Success" << endl;
            auto temp = find(v.begin(), v.end(), p);
            v.erase(temp);
        }

        else{
            if(count(v.begin(), v.end(), p)!=0){
                cout << "AlreadyOn" << endl;
            }

            else if(count(pr.begin(), pr.end(), p)!=0){
                bool temp = true;
                for(int c=0; c<v.size(); c++){
                    if(v[c]%p==0){
                        cout << "Conflict" << endl;
                        temp = false;
                        break;
                    }
                }
                if(temp){
                    cout << "Success" << endl;
                    v.push_back(p);
                }
            }

            else{
                bool temp1 = true;
                for(int d=0; d<v.size(); d++){
                    if(gcd(p, v[d]) != 1){
                        cout << "Conflict" << endl;
                        temp1 = false;
                        break;
                    }
                }
                if(temp1){
                    cout << "Success" << endl;
                    v.push_back(p);
                }
            }

        }
    }

    return 0;
}
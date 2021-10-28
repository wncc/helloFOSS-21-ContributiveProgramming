#include<bits/stdc++.h>

using namespace std;

//XS, S, M, L, XL, XXL, XXXL

void myfunc(string s[], int n){
    int a[100000], t=0;
    for(int i=0; i<n; i++){
        if(s[i]=="XS") a[i]=1;
        else if(s[i]=="S") a[i]=2;
        else if(s[i]=="M") a[i]=3;
        else if(s[i]=="L") a[i]=4;
        else if(s[i]=="XL") a[i]=5;
        else if(s[i]=="XXL") a[i]=6;
        else a[i]=7;
        }

    do{
    int temp=0;        
    for(int j=0; j<n-1; j++){
        if(a[j]>a[j+1]){
            int temp1 = a[j];
            a[j] = a[j+1];
            a[j+1] = temp1;
            temp++;
            }
        }
        if(temp==0) break; 
        t += temp;       
        temp = 0;
        }while(true);

    cout << t << endl;
    for(int i=0; i<n; i++){
        if(a[i]==1) cout << "XS" << " ";
        else if(a[i]==2) cout << "S" << " ";
        else if(a[i]==3) cout << "M" << " ";
        else if(a[i]==4) cout << "L" << " ";
        else if(a[i]==5) cout << "XL" << " ";
        else if(a[i]==6) cout << "XXL" << " ";
        else cout << "XXXL" << " ";
        }
    cout << endl;    
    return;
    }


int main(){ 
    int t; 

    #ifndef ONLINE_JUDGE
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);
    // Printing the Output to output.txt file
    // freopen("output.txt", "w", stdout);
#endif
        cin >> t;

    while(t>0){
        int n;
        cin >> n;
        string s[100000];
        for(int i=0; i<n; i++){ 
        cin >> s[i];
        }
        myfunc(s, n);
        cout << endl;
        t--;
        }

    return 0;
    }
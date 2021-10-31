#include<bits/stdc++.h>
#include"MinStack.h"

using namespace std;

/* #include "A2DD.h"

A2DD::A2DD(int x,int y)
{
  gx = x;
  gy = y;
}

int A2DD::getSum()
{
  return gx + gy;
} */

MinStack::MinStack(){
    arr= new int[MAXSIZE];
    size=0;
}

int MinStack::getMin(){
  if(size==0) cout << "EMPTY" << endl;
  else cout << min_elem << endl;
  return 0;
}

void MinStack::push(int v){
  if(size==MAXSIZE) cout << "FULL" << endl;
    
  else if(size==0){
    arr[size] = v;
    size++;
    min_elem = v;
  }

  else if(v<min_elem){
    arr[size] = (2*v-min_elem);
    min_elem = v;
    size++;
  }

  else{
    arr[size] = v;
    size++;
  }
}

int MinStack::pop(){
  int temp = arr[size-1];

  if(size==0) {
    cout << "EMPTY" << endl;
  }

  else if(temp<min_elem){
    cout << min_elem << endl;
    min_elem = 2*min_elem-temp;
    size--;
  }

  else{
    cout << temp << endl;
    size--;
  }

  return 0;
}

int MinStack::top(){
  if(size==0) cout << "EMPTY" << endl;
  
  else if(arr[size]<min_elem){
    cout << min_elem << endl;
  }

  else{
    cout << arr[size] << endl;
  }

  return 0;
}



int main(){
  int tc;
  cin >> tc;

  while (tc>0)
  {
    int x;
    cin >> x;

    MinStack* m = new MinStack();

    while(x>0){
      int q;
      cin >> q;
      if(q==1){
        int v;
        cin >> v;
        m -> push(v);
        x--;
      }

      else if(q==2){
        m -> pop();
        x--;
     }

      else if(q==3){
        m -> top();
        x--;
      }

      else{
        m -> getMin();
        x--;
      }
    }
    tc--;
  }
  

    return 0;
}


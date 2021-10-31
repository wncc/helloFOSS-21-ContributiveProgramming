#include<bits/stdc++.h>
using namespace std;

class MinStack {
    stack<pair<int, int>> S;
public:
    void push(int val) {
        S.push({val, S.empty() ? val : min(val, S.top().second)});
    }
    void pop() {S.pop();}
    int top() {return S.top().first;}
    int getMin() {return S.top().second;}
};

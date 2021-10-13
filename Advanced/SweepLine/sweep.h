#include <bits/stdc++.h>

using namespace std;

struct segment{
/*
    All the information required to describe a segment could be stored here!
    A loose list could be : 
    1) Starting Point as pair<int,int>
    2) Ending Point as pair<int,int>
    or you may want to store these in one-point form as well?
    Upto you!
*/
};


class SweepLine{
/*
    You may maintain a list of variables including:
    1) vector/array of segments
    2) vector/array of intersecting points
    3) set/multiset for the sweep line etc.
    You may want to initialize this with a custom comparing function : https://stackoverflow.com/questions/18718379/initializing-multiset-with-custom-comparison-function-in-c
*/    

    public: 
        SweepLine(vector<struct segment> segs);      
        int CalculateMaximumNum();
        // Feel free to declare any other functions!
};
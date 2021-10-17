#include <bits/stdc++.h>
using namespace std;

vector<int> find_lps(const string &s)
{
    int n = s.length();
    vector<int> res(n);
    for (int i=1;i<n;i++)
    {
        int x = res[i-1];
        while (x>0 and s[i]!=s[x])
        {
            x = res[x-1];
        }
        if (s[i]==s[x])
        {
            res[i] = x+1;
        }
        else
        {
            res[i] = x;
        }
    }
    return res;
}


int main()
{
    freopen("input.txt","r",stdin);
    int n;
    string word;
    cin>>n>>word;
    vector<int> lps = find_lps(word);
    string curr;
    for (int t=0;t<n;t++)
    {
        cin>>curr;
        int l = curr.length();
        int i = 0, j = 0;
        vector<int> occurances;

        while (i<l)
        {
            bool foundhere = false;
            if (curr[i]==word[j])
            {
                i++;
                j++;
                if (j==word.length())
                {
                    occurances.push_back(i-j);
                    foundhere = true;
                }
            }
            if (foundhere==false)
            {
                if (i<l and curr[i]!=word[j])
                {
                    if (j>0)
                    {
                        j = lps[j-1];
                    }
                    else i++;
                }
            }

        }

        cout<<occurances.size()<<endl;
        for (auto u:occurances)
        {
            cout<<u<<" ";
        }
        cout<<endl;


    }
}

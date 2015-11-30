#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        long long int ct=count(s.begin(),s.end(),'1');
        //cout<<ct;
        long long ans=ct*(ct-1)/2 +ct;
        cout<<ans<<endl;
    }
    return 0;
}


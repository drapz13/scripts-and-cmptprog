#include <bits/stdc++.h>
using namespace std;
pair<int,int> p[2005];
int main()
{
    int n;
    cin>>n;
    int ct=0;
    for (int i=0;i<n;++i)
    {
        cin>>p[i].first;
        p[i].first+=101.0;
        cin>>p[i].second;
        p[i].second+=101.0;
    }
    for (int i=0;i<n-2;++i)
        for (int j=i+1;j<n-1;++j)
            for (int k=j+1;k<n;++k)
                if ((p[i].first*(p[j].second-p[k].second)+p[j].first*(p[k].second - p[i].second)+p[k].first*(p[i].second-p[j].second))!=0)
                    ct++;
    cout<<ct<<endl;
    return 0;
    }
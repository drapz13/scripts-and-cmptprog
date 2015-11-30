#include <bits/stdc++.h>

using namespace std;
vector<long long int> v;
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int l=s.length();
    int ct=0,lf=0;
    for(int i=0;i<l;i++)
    {
        if(s[i]=='0') lf++;
        else {v.push_back(lf);lf=0;ct++;}
    }
    if(s[l-1]=='0') v.push_back(lf);
    else v.push_back(0);
    /*for(int i=0;i<ct+1;i++)
    {
        cout<<v[i]<<endl;
    }*/
    long long ans=0;
    if(ct<n) cout<<0<<endl;
    else if(n==0)
    {
        for(int i=0;i<ct+1-n;i++)
        {
            ans+=((v[i]+1)*(v[i]))/2LL;
        }
        cout<<ans;
    }
    else
    {
        for(int i=0;i<ct+1-n;i++)
        {
            ans+=((v[i]+1)*(v[i+n]+1));
        }
        cout<<ans;
    }
    return 0;
}
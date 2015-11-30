#include <bits/stdc++.h>
using namespace std;
int c[1000005];
int main()
{
    string s;
    int n;
    cin>>s;
    cin>>n;
    int l=s.length();
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        c[x]++;
        c[l-x+2]--;
    }
    for(int i=1;i<=l;i++)
        c[i+1]+=c[i];

    for(int i=1;i<=l/2;i++)
    {
        if(c[i]%2!=0)
        {
            int y=i-1;
            int x=l-y-1;
            char ch = s[x];
            char p = s[y];
            s[x] = p;
            s[y] = ch;
        }
    }
    cout<<s<<endl;
    return 0;
}
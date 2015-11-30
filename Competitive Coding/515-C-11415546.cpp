#include <bits/stdc++.h>

using namespace std;
int a[10];
int main()
{
    int n;
    memset(a,0,sizeof a);
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='4') {a[2]+=2;a[3]++;}
        else if(s[i]=='6') {a[5]++;a[3]++;}
        else if(s[i]=='8') {a[2]+=3;a[7]++;}
        else if(s[i]=='9') {a[2]++;a[3]+=2;a[7]++;}
        else a[s[i]-48]++;
    }
    for(int i=9;i>=2;i--)
    {
        while(a[i]--) cout<<i;
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
int a[100005];
int main()
{
    string s;
    cin>>s;
    int l=s.length();
    for(int i=0;i<l-1;i++)
    {
        if(s[i]=='A'&&s[i+1]=='B') a[i]=1;
        if(s[i]=='B'&&s[i+1]=='A') a[i]=2;
    }
    for(int i=0;i<l;i++)
    {
        //cout<<i<<a[i]<<endl;
        if(a[i]==1) if(find(a+i+2,a+l,2)-a<l){cout<<"YES";return 0;}
        if(a[i]==2) if(find(a+i+2,a+l,1)-a<l){cout<<"YES";return 0;}
    }
    cout<<"NO";
    return 0;
}
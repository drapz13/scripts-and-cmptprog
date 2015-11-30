#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,s;
    cin>>a>>b>>s;
    int ans=abs(a)+abs(b);
    //cout<<s-ans;
    if(s<ans) cout<<"No\n";
    else if((s-ans)%2==0) cout<<"Yes\n";
    else cout<<"No\n";
    return 0;
}
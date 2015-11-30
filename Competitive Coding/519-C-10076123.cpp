#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    int ans = 0;
    cin>>n>>m;
    while((n-2>=0 && m-1>=0)||(n-1>=0 && m-2>=0))
    {
        if(n>m)
        {
            n-=2;m-=1;
            ans++;
        }
        else
        {
            if(n-1>=0 && m-2>=0)
            {
                n-=1;m-=2;
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

map<string,int> mc;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long double n,ans=1;
        int m;
        cin>>n>>m;
        n--;
        ///C(n-1,m-1)
        while(m)
        {
            //cout<<n-1<<" "<<m-1<<endl;
            ans*=(n)/(m);
            n--;
            m--;
            cout<<n-1<<" "<<m-1<<endl;
        }
        cout<<(long long) ans*2LL<<endl;
    }
    return 0;
}

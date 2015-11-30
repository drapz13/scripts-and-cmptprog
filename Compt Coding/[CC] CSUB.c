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
        int x=n;
        int gcd;
        cin>>gcd;
        n--;
        while(n--)
        {
            int d;
            cin>>d;
            gcd=__gcd(gcd,d);
        }
        if(gcd==1) cout<<x<<endl;
        else cout<<"-1\n";
    }
    return 0;
}

#include <bits/stdc++.h>
#define sflld(n) scanf("%lld",&n)
#define sfulld(n) scanf("%llu",&n)
#define sfd(n) scanf("%d",&n)
#define sfld(n) scanf("%ld",&n)
#define sfs(n) scanf("%s",&n)
#define ll long long
#define ull unsigned long long int
#define pflld(n) printf("%lld\n",n)
#define pfd(n) printf("%d\n",n)
#define pfld(n) printf("%ld\n",n)
#define lt 2*idx
#define rt 2*idx+1
#define f first
#define s second

using namespace std;
int main()
{
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
    int u,v,s,i;
    sfd(s);
    for(i=1;i<=3;i++)
    {
        sfd(u);
        sfd(v);
        if(u==s)
        {
            s=v;
        }
        else if(v==s)
        {
            s=u;
        }
    }
    pfd(s);
    return 0;
}
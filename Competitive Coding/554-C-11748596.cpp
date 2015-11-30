#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(0);
#define __ int t;cin>>t;while(t--)
#define endl '\n'

#define MOD 1000000007
using namespace std;

long long mod_pow(int a,int b)
{
    long long a1=1,a2=a;
    while(b>0)
    {
        if(b%2==1)
        {
            a1*=a2;
            if(a1>MOD) a1%=MOD;
        }
        a2*=a2;
        if(a2>MOD) a2%=MOD;
        b/=2;
    }
    return a1;
}
int fooct(int n,int p)
{
    int i=0;
    while(n>0)
    {
        i+=n/p;
        n=n/p;
    }
    return i;
}
long long int nCr(int n,int r)
{
    long long int ncr=1;
    vector<bool> primes(n+1,1);
    for(int i=2;i<=n;i++)
        if(primes[i])
        {
            for(int j=2*i;j<=n;j+=i) primes[j]=0;
            int f=(fooct(n,i)-fooct(r,i)-fooct(n-r,i));
            ncr=(ncr*mod_pow(i,f))%MOD;
        }
    return ncr;
}
int a[1005];
int main()
{
    _        ///  FAST I/O
    //__       ///  T TEST CASES
    {
        int n;
        cin>>n;
        long long tot=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            tot+=a[i];
        }
        long long ans=1;
        for(int i=n-1;i>=0;i--)
        {
            tot--;
            int ncr=nCr(tot,a[i]-1);
            tot-=(a[i]-1);
            ans*=ncr;
            ans%=MOD;
        }
        cout<<ans<<endl;
    }
    return 0;
}
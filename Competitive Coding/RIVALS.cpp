#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(0);
#define __ int t;cin>>t;while(t--)
#define endl '\n'
const int MOD = 1e9 + 7;
using namespace std;
template <typename T>
T modpow(T base, T exp, T modulus) {
  base %= modulus;
  T result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}
long long f[2000005];
void fact()
{
    f[0]=f[1]=1;
    for(int i=2;i<2000005;i++)
        f[i]=(f[i-1]*i)%MOD;
}

long long int inv_mod(long long int x)
{
    long long i=1,j=x,lim=1e9 +5;
    while(lim)
    {
        if(lim&1)
        {
            i=(i*j)%MOD;
        }
        j=(j*j)%MOD;
        lim>>=1;
    }
    return i;
}

int main()
{
    _        ///  FAST I/O

    fact();
    __       ///  T TEST CASES
    {
        int a,b;
        cin>>a>>b;
        long long div=(inv_mod(f[a])*inv_mod(f[b]))%MOD;
        //cout<< div<<endl;
        long long ans=(f[a+b]*div)%MOD;
        cout<<ans<<endl;
    }
    return 0;
}

/**  NINNI MODE :P  **/

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define _ ios_base::sync_with_stdio(false);cin.tie(0);
#define __ int t;cin>>t;while(t--)
#define endl '\n'

using namespace std;
template <typename T>
T modpow(T base, T exp) {
  //base %= modulus;
  T result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base);
    base = (base * base);
    exp >>= 1;
  }
  return result;
}
int main()
{
    _        ///  FAST I/O
    __       ///  T TEST CASES
    {
        long long n;
        cin>>n;
        int f=0;
        for(long long i=1;modpow(i,3LL)<=n;i++)
        {
            for(long long j=n-modpow(i,3LL);j>0;j--)
            {
                if(modpow(i,3LL)+modpow(j,3LL)==n)
                {
                    f=1;
                    break;
                }
            }
        }
        if(f) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}

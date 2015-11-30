#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define _ ios_base::sync_with_stdio(false);cin.tie(0);
#define __ int t;cin>>t;while(t--)
#define endl '\n'
#define ispow2(n) (n&&(!(n&(n-1))))      ///check if its perfect power of 2
using namespace std;
template <typename T>
T modpow(T base, T exp) {
  /// base %= modulus;
  T result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base); ///  % modulus;
    base = (base * base); ///  % modulus;
    exp >>= 1;
  }
  return result;
}

long long a[10005];
int main()
{
    _        ///  FAST I/O
    // __       ///  T TEST CASES
    {
        int k,n;
        cin>>k>>n;
        for(int i=k-1;i>=0;i--)
        {
            long long x;
            cin>>x;
            a[i]=modpow(x,2LL);
        }
        long long ans=0LL;
        for(int i=0;i<n;i++)
        {
            long long x,y,z;
            cin>>x>>y;
            z=modpow(x,2LL)+modpow(y,2LL);
            int loc=lower_bound(a,a+k,z)-a;
            if(loc>k) ans+=0;
            else ans+=k-loc;
        }
        cout<<ans<<endl;
    }
    return 0;
}

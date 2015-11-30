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

int a[100005];
int main()
{
    _        ///  FAST I/O
    // __       ///  T TEST CASES
    {
        int n;
        int gcd=0;
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i],gcd=__gcd(gcd,a[i]);
        int f=0;
        for(int i=0;i<n;i++)
        {
            a[i]/=gcd;
            while(a[i]%2==0) a[i]/=2;
            while(a[i]%3==0) a[i]/=3;
            if(a[i]!=1) {f=1;break;}
        }
        if(f==0) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}
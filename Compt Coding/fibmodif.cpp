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
long long a[21];
int main()
{
    _        ///  FAST I/O
    __       ///  T TEST CASES
    {
        int n;
        cin>>a[0]>>a[1]>>n;
        for(int i=2;i<n;i++)
        {
            a[i]=modpow(a[i-1],2LL)+a[i-2];
        }
        cout<<a[n-1]<<endl;
    }
    return 0;
}

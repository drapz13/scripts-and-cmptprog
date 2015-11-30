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
  if(exp==0) return 1;
  int b1=modpow(base,exp/2);
  b1=base*b1;
  return b1;
}


int main()
{
    _        ///  FAST I/O
    // __       ///  T TEST CASES
    {
        cout<<modpow(3,3);
    }
    return 0;
}

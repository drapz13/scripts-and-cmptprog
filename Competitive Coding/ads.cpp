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


int main()
{
    _        ///  FAST I/O
    // __       ///  T TEST CASES
    {
        float a[3],b[3],s1=0,s2=0;
        for(int i=0;i<3;i++) cin>>a[i]>>b[i],s1+=a[i],s2+=b[i];
        for(int i=0;i<3;i++)
        {
            cout<<fixed<<setprecision(2)<<s1-2*a[i]<<" ";
            cout<<fixed<<setprecision(2)<<s2-2*b[i]<<endl;
        }
    }
    return 0;
}

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define _ ios_base::sync_with_stdio(false);cin.tie(0);
#define __ int t;cin>>t;while(t--)
#define endl '\n'

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

template <typename T>
T pow(T base, T exp) {
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
    // __       ///  T TEST CASES
    {
        int a1,a2,a3,a4,a5,a6;
        cin>>a1>>a2>>a3>>a4>>a5>>a6;
        long long ans=pow(a1+a2+a3,2);
        ans-=a1*a1;
        ans-=a3*a3;
        ans-=a5*a5;
        cout<<ans<<endl;
    }
    return 0;
}
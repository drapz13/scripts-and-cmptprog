#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(0);
#define __ int t;cin>>t;while(t--)
#define endl '\n'

using namespace std;
const long long int MOD = 1298074214633706835075030044377087;
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

long long power[501];
void pre()
{
    for(long long int i=0;i<=500;i++)
    {
        mod_pow(2LL,i,)
    }
}
int main()
{
    _        ///  FAST I/O
    // __       ///  T TEST CASES
    {

    }
    return 0;
}

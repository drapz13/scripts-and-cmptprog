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


int main()
{
    _        ///  FAST I/O
    __       ///  T TEST CASES
    {
        long long int n;
        cin>>n;
        n+=1;
        if(n&&(!(n&(n-1)))&&n>2)
        {
            cout<<n/2-1<<endl;
        }
        else
        {
            cout<<"-1\n";
        }
    }
    return 0;
}

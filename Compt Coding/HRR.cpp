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
    __       ///  T TEST CASES
    {
        int n;
        cin>>n;
        int a=n%4;
        long long int b=n/4LL;
        if(a==0)
        {
            cout<<-1LL*2LL*b<<" "<<-1LL*2LL*b<<endl;
        }
        else if(a==1)
        {
            cout<<2LL*b+1LL<<" "<<-1LL*2LL*(b)<<endl;
        }
        else if(a==2)
        {
            cout<<2LL*b+1LL<<" "<<2LL*(b+1LL)<<endl;
        }
        else if(a==3)
        {
            cout<<-1LL*2LL*(b+1LL)<<" "<<2LL*(b+1LL)<<endl;
        }
    }
    return 0;
}

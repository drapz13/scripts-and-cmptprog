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
    //__       ///  T TEST CASES
    {
        long long k,a,b;
        cin>>k>>a>>b;
        long long ans=0;
        int flag=0;
        if((a>0 &&  b>0) || (a<0 && b<0)) flag=1;
        else flag=0;
        if(flag==0)
        {
            a=abs(a);
            ans+= b/k;
            ans+=a/k;
            ans+=1; /// 0 case
        }
        else
        {
            if(b<0)
            {
                b=abs(b);
                a=abs(a);
                ans-=(b-1)/k;
                ans+=a/k;
            }
            else
            {
                ans+=b/k;
                ans-=(a-1)/k;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

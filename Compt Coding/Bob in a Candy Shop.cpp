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
int S[]={1,2,5,10,20,50,100};
int nway(int amt, int den){
   //cout << amt << endl;
  if(amt == 0) return 1;
  if(amt < 0) return 0;

  if(den< 0 && amt >= 0)
    return 0;
   return nway(amt, den- 1) +
          nway(amt - S[den], den);
}
int main()
{
    _        ///  FAST I/O
    //__       ///  T TEST CASES
    {
        int n;
        cin>>n;
        int cnt=0;
        cnt=nway(n,6);
        cout<<cnt<<endl;
    }
    return 0;
}

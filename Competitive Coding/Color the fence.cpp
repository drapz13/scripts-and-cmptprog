#include <bits/stdc++.h>
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
    // __       ///  T TEST CASES
    {
        int l;
        cin>>l;
        string s;
        cin>>s;
        int c1=0,c2=0;
        for(int i=0;i<l;i++)
        {
            if(s[i]=='0') c1++;
            else c2++;
        }
        cout<<abs(c2-c1)<<endl;

    }
    return 0;
}

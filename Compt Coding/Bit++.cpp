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
        int n;
        cin>>n;
        int x=0;
        while(n--)
        {
            string s;
            cin>>s;
            int l=s.length();
            if(s[0]=='+'||s[l-1]=='+') x+=1;
            else x-=1;
        }
        cout<<x<<endl;
    }
    return 0;
}

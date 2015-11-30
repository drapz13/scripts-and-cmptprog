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
        string s;
        cin>>s;
        int l=s.length();
        char a[]={'h','e','l','l','o'};
        int j=0;
        for(int i=0;i<l;i++)
        {
            if(s[i]==a[j]) j++;
            if(j==5) break;
        }
        if(j==5) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
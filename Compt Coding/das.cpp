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

int a[26];
int main()
{
    _        ///  FAST I/O
    __       ///  T TEST CASES
    {
        memset(a,0,sizeof(a));
        string s;
        cin>>s;
        int l=s.length();
        for(int i=0;i<l;i++)
        {
            a[s[i]-'a']++;
        }
        int ct=0;
        for(int i=0;i<26;i++)
        {
            if(a[i]) ct++;
        }
        int x=ceil(1.0*l/ct);
        int ans=0;
        cout<<x;
        for(int i=0;i<26;i++) if(a[i]) ans+=abs(a[i]-x);
        cout<<ans/2<<endl;
    }
    return 0;
}

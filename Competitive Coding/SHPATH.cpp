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


set<string> m;
int main()
{
    _        ///  FAST I/O
    //__       ///  T TEST CASES
    {
        string s;
        cin>>s;
        int l=s.size();
        s.resize(l+1);
        //cout<<(int)'a';
        for(int i=97;i<97+26;i++)
        {
            for(int j=0;j<=l;j++)
            {
                string s1=s;
                s1.insert(j,1,(char)i);
                m.insert(s1);
            }
        }
        cout<<m.size();
    }
    return 0;
}

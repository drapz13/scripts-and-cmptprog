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

map<string,int> m;
map<string,int>::iterator it;
int main()
{
    _        ///  FAST I/O
    //__       ///  T TEST CASES
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            m[s]++;
        }
        int maxi=0;
        for(it=m.begin();it!=m.end();++it)
        {
            maxi=max(maxi,it->second);
        }
        cout<<maxi<<endl;
    }
    return 0;
}
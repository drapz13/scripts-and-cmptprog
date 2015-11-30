#include <bits/stdc++.h>
#define pb push_back
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
vector< pair<int,string> > m1;

map<string,int>::iterator it;
int main()
{
    _        ///  FAST I/O
    // __       ///  T TEST CASES
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            m[s]++;
        }
        for(it=m.begin();it!=m.end();++it)
        {
            m1.pb(make_pair(it->second,it->first));
        }
        sort(m1.begin(),m1.end());
        for(int i=m1.size()-1;i>=0;i--)
        {
            cout<<m1[i].second<<" "<<m1[i].first<<endl;
        }
    }
    return 0;
}

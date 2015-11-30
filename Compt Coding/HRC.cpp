#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
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

map<int,int> m;
map<int,int>::iterator it;
int b[1000005];
int main()
{
    _        ///  FAST I/O
    // __       ///  T TEST CASES
    {
        int n,q;
        cin>>n>>q;
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
        }
        while(q--)
        {
            int l,r;

            long long ans=1LL;
            cin>>l>>r;
            l--,r--;
            m.clear();
            for(int i=l;i<=r;i++)
            {
                m[b[i]]++;
            }
            for(it=m.begin();it!=m.end();++it)
            {
                if(it->second==1)
                {
                    ans*=it->first;
                    ans%=3;
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}

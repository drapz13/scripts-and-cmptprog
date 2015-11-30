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

vector<int> v[100005];
int main()
{
    _        ///  FAST I/O
    // __       ///  T TEST CASES
    {
        int n,m;
        cin>>n>>m;
        for(int i=0;i<m;i++)
        {
            int x,y;
            cin>>x>>y;
            v[x].pb(y);
            v[y].pb(x);
        }
    }
    return 0;
}

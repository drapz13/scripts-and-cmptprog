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

pair<int,int> soldiers[100005];
vector<int> con[100005];

bool comp(const vector<int> &v1,const vector<int> &v2)
{

}
int main()
{
    _        ///  FAST I/O
    // __       ///  T TEST CASES
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            con[x].pb(y);
            con[y].pb(x);
        }
        for(int i=0;i<n-1;i++)
        {
            int x,y;
            cin>>x>>y;
            v[x].pb(y);
            v[y].pb(x);
        }
    }
    return 0;
}

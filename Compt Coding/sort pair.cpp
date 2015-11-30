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

pair<int,int> p[100005];
bool greatr(const pair<int,int> &p1,const pair<int,int> &p2)
{
    return (p1.first>p2.first);
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
            p[i]=make_pair(x,y);
        }
        sort(p,p+n,greatr);
        for(int i=0;i<n;i++)
        {
            cout<<p[i].first<<" "<<p[i].second<<endl;
        }
    }
    return 0;
}

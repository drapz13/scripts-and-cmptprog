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

vector< pair<int,int> > v[3005];
set<int> s;
set<int>::iterator it;
set< pair<int,int> > dist;
set< pair<int,int> >::iterator it1;
int fin_dist[3005];
bool vis[3005];
int main()
{
    _        ///  FAST I/O
    // __       ///  T TEST CASES
    {
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            vis[i]=false;
            v[i].clear();
        }
        s.clear();
        dist.clear();
        dist.insert(mp(0,0));
        for(int i=1;i<n;i++)
        {
            dist.insert(mp(INT_MAX,i));
        }
        for(int i=0;i<m;i++)
        {
            int x,y,d;
            cin>>x>>y>>d;
            x--,y--;
            v[x].pb(mp(y,d));
            v[y].pb(mp(x,d));
        }
        s.insert(0);
        it=s.begin();
        while(s.size()!=n)
        {
            for(int i=0;i<v[(*it).size];i++)
            {
                if(fin_dist[*it]+v[(*it)][i].second < )
            }
            it1=dist.begin();
            vis[]
        }
    }
    return 0;
}

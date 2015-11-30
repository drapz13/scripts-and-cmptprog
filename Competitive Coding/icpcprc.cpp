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
bool vis[100005];
vector<int> v[100005];
vector< pair<int,int> > lns;
map< pair<int,int> ,int> m1;
int n,f=0;
void bfs(int s)
{
	queue< pair<int,int> > q;
	q.push(mp(s,0));
	memset(vis,false,sizeof vis);
	vis[s]=true;
	while(!q.empty())
	{
		int x=q.front().first,y=q.front().second;
		q.pop();
		vis[x]=true;
		if(x==n)
		{
            f=1;
			cout<<q.front().second<<endl;
			return;
		}
		for(int i=0;i<v[x].size();i++)
		{
			if(!vis[v[x][i]])
            {
                if(m1.find(mp(x,v[x][i]))!=m1.end())
                {
                    if(m1[mp(x,v[x][i])]>y)
                    q.push(mp(v[x][i],y+1));
                }
            }
			else
			q.push(mp(v[x][i],y+1));
		}
	}
}
int main()
{
    _
    //__
    {
        int m,k;
        cin>>n>>m>>k;
        for(int i=0;i<m;i++)
        {
            int u,w;
            cin>>u>>w;
            v[u].pb(w);
            v[w].pb(u);
            lns.pb(mp(u,w));
        }
        for(int i=0;i<k;i++)
        {
            int u,w;
            cin>>u>>w;
            m1[lns[w-1]]=u;
            m1[mp(lns[w-1].second,lns[w-1].first)]=u;
        }
        bfs(1);
        if(f==0) cout<<"-1\n";
    }
    return 0;
}

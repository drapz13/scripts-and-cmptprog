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

bool vis[3001];
int val[3001][3001];
int dist[3001][3001];

void bfs(int s,vector<int>* v)
{
    memset(vis,false,sizeof vis);
    vis[s]=true;
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        //cout<<x<<endl;
        for(int i=0;i<v[x].size();i++)
        {
            if(!vis[v[x][i]])
            {
                vis[v[x][i]]=true;
                if(val[s][v[x][i]]!=-1) val[s][v[x][i]]=min(val[s][v[x][i]],val[s][x]+val[x][v[x][i]]);
                else val[s][i]=val[s][x]+val[x][i];
                q.push(v[x][i]);
            }
            else
            {
                val[s][v[x][i]]=min(val[s][v[x][i]],val[s][x]+val[x][v[x][i]]);
            }
        }
    }
}
int main()
{
    //freopen("C:\\Users\\DARPAN\\Desktop\\aa.txt","r",stdin);
    //freopen("C:\\Users\\DARPAN\\Desktop\\ab.txt","w",stdout);
    _        ///  FAST I/O
    __       ///  T TEST CASES
    {
        int n,m;
        cin>>n>>m;
        vector<int> v[3001];
        memset(val,-1,sizeof val);
        memset(dist,-1,sizeof dist);
        for(int i=0;i<m;i++)
        {
            int x,y,r;
            cin>>x>>y>>r;
            v[x].pb(y);
            v[y].pb(x);
            val[x][y]=val[y][x]=r;
        }
        int s;
        cin>>s;
        bfs(s,v);
        long double ans=0;
        for(int i=1;i<=n;i++)
        {
            if(i==s) continue;
            if(val[s][i]) cout<<val[s][i]<<" ";
            else cout<<"-1 ";
        }
        cout<<endl;
    }
    return 0;
}

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
int n,m;
int dist[2009][2009],visit[2009][2009];
void bfs(int src,int dest)
{
     queue<pair<int,int> >q;
    q.push(mp(src,dest));

    while(!q.empty())
    {
        pair<int,int> p=q.front();
        q.pop();
        if(p.second>1&&visit[p.first][p.second-1]==0)
        {
            dist[p.first][p.second-1]=min(1+dist[p.first][p.second],dist[p.first][p.second-1]);
            visit[p.first][p.second-1]=1;
            q.push(mp(p.first,p.second-1));
        }
        if(p.first>1&&visit[p.first-1][p.second]==0)
        {
            dist[p.first-1][p.second]=min(1+dist[p.first][p.second],dist[p.first-1][p.second]);
            visit[p.first-1][p.second]=1;
            q.push(mp(p.first-1,p.second));
        }
      if(p.first<n&&visit[p.first+1][p.second]==0)
        {
            dist[p.first+1][p.second]=min(1+dist[p.first][p.second],dist[p.first+1][p.second]);
            visit[p.first+1][p.second]=1;
            q.push(mp(p.first+1,p.second));
        }
         if(p.second<m&&visit[p.first][p.second+1]==0)
        {
            dist[p.first][p.second+1]=min(1+dist[p.first][p.second],dist[p.first][p.second+1]);
            visit[p.first][p.second+1]=1;
            q.push(mp(p.first,p.second+1));
        }
    }
}
int main()
{
    _        ///  FAST I/O
    // __       ///  T TEST CASES
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    {
    int x,y,i,j,src,dest;
    cin>>n>>m;
    int k;
    cin>>k;
    int f=0;
    while(k--)
    {   memset(visit,0,sizeof(visit));
        cin>>src>>dest;
        dist[src][dest]=0;
        visit[src][dest]=1;
        if(f==0)
        {f=1;
    queue<pair<int,int> >q;
    q.push(mp(src,dest));

    while(!q.empty())
    {
        pair<int,int> p=q.front();
        q.pop();
        if(p.second>1&&visit[p.first][p.second-1]==0)
        {
            dist[p.first][p.second-1]=1+dist[p.first][p.second];
            visit[p.first][p.second-1]=1;
            q.push(mp(p.first,p.second-1));
        }
        if(p.first>1&&visit[p.first-1][p.second]==0)
        {
            dist[p.first-1][p.second]=1+dist[p.first][p.second];
            visit[p.first-1][p.second]=1;
            q.push(mp(p.first-1,p.second));
        }
      if(p.first<n&&visit[p.first+1][p.second]==0)
        {
            dist[p.first+1][p.second]=1+dist[p.first][p.second];
            visit[p.first+1][p.second]=1;
            q.push(mp(p.first+1,p.second));
        }
         if(p.second<m&&visit[p.first][p.second+1]==0)
        {
            dist[p.first][p.second+1]=1+dist[p.first][p.second];
            visit[p.first][p.second+1]=1;
            q.push(mp(p.first,p.second+1));
        }
        }
    }
    else
        bfs(src,dest);}
    }
    int maxx=0,i,j,pos1=1,pos2=1;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            //cout<<dist[i][j]<<" ";
            if(maxx<dist[i][j])
                {maxx=dist[i][j];
                 pos1=i;
               pos2=j;}
        }
       // cout<<endl;
    }
    cout<<pos1<<" "<<pos2;
    return 0;
}

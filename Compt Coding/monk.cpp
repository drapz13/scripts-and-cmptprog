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
long long va=0LL;
bool vis[100005];
long long int val[100005];
void dfs(int s,vector<int>* v)
{
    vis[s]=true;
    va+=val[s];
    for(int i=0;i<v[s].size();i++)
    {
        if(!vis[v[s][i]])
        {
            vis[v[s][i]]=true;
            dfs(v[s][i],v);
        }
    }
}

int main()
{
    _        ///  FAST I/O
    // __       ///  T TEST CASES
    {
        int n,m;
        memset(vis,false,sizeof vis);
        cin>>n>>m;
        vector<int> v[n];
        vector<int>::iterator it;

        for(int i=0;i<m;i++)
        {
            int x,y;
            cin>>x>>y;
            v[x].pb(y);
            v[y].pb(x);
        }
        for(int i=0;i<n;i++) cin>>val[i];
        va=0LL;
        long long maxi=0LL;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i]) dfs(i,v);
            maxi=max(maxi,va);
            va=0LL;
        }
        cout<<maxi<<endl;
    }
    return 0;
}

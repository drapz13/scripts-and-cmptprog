#include <bits/stdc++.h>

using namespace std;
int eny[1005];
bool vis[1005];
int ans=0;
void bfs(int s,int n,vector<int> v[])
{
    int i=s,maxv=-1,maxid;
    for(int j=0;j<n;j++)
    {
        if(!vis[j]&&eny[j]>maxv)
        {
            maxv=eny[j];
            maxid=j;
        }
    }
    for(int j=0;j<v[maxid].size();j++)
    {
        int v1=v[maxid][j];
        if(!vis[v1])
        {
            ans+=eny[v1];
        }
    }
    vis[maxid]=1;
}
int main()
{
    int n,m;
    memset(vis,false,sizeof vis);
    cin>>n>>m;
    vector<int> v[n];
    for(int i=0;i<n;i++) cin>>eny[i];
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=0;i<n;i++) bfs(i,n,v);
    cout<<ans;
    return 0;
}
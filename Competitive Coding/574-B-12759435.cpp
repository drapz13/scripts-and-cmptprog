#include<bits/stdc++.h>

#define P pair<int,int>
#define _fast ios_base::sync_with_stdio(false);cin.tie(0);
#define LL long long int
#define s(a) scanf("%d",&a)
#define ss(a) scanf("%s",a)
#define w(t) while(t--)
#define f(i,n) for(i=0;i<n;i++)
#define fd(i,n) for(i=n-1;i>=0;i--)
#define p(a) printf("%d",a)
#define ps(a) printf("%s",a)
#define pc(a) printf("%c",a)
#define ent printf("\n")
#define maxn 100000
#define mod 1000000007
bool comp(const int& a, const int& b)
       {
          return a<b?false:true;//min_heap
       }
using namespace std;
vector<int>adj[4009];
int a[4009][4009];
int val[4009]={0};
int main()
{
    int n,m,i,j,k,u,v;
    s(n);
    s(m);
    f(i,m)
    {
        cin>>u>>v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
        a[u-1][v-1]=1;
        a[v-1][u-1]=1;
    }
    int c=1;
    i=1;
    int sum,f=0,lar=INT_MAX;
    for(i=0;i<n;i++)
    {
        for(j=0;j<adj[i].size();j++)
        {
            for(k=0;k<adj[adj[i][j]].size();k++)
            {   int x=adj[i][j];
                if(adj[x][k]!=i&&a[i][adj[x][k]]==1)
                {
                    f=1;
                    sum=adj[i].size()+adj[x].size()+adj[adj[x][k]].size()-6;
                    lar=min(sum,lar);
                }
            }
        }
    }
    if(f==0)
        printf("-1");
    else
        cout<<lar;
    return 0;
}
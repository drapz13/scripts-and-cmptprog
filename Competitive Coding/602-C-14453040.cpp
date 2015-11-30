#include<bits/stdc++.h>


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
typedef pair<int,int> P;
vector<int>adj1[451];
vector<int>adj2[451];
int dist1[501],dist2[501];
queue<int>q;
int vis[501];
int main()
{
    int n,e,i,j,u,v,f1=-1,f2=-1;
    s(n);
    s(e);
    f(i,e)
    {
        cin>>u>>v;
        adj1[u].push_back(v);
        adj1[v].push_back(u);
    }
    vector<int>::iterator it1,it2;
    for(i=1;i<=n;i++)
    {
        sort(adj1[i].begin(),adj1[i].end());
    }
    for(i=1;i<=n;i++)
    {
        int cnt=1;
        for(j=0;j<adj1[i].size();)
        {
            if(cnt==i)
            {
                cnt++;
                continue;
            }
            if(adj1[i][j]!=cnt)
            {
                adj2[i].push_back(cnt);
                cnt++;
            }
            else
            {   j++;
                cnt++;}
        }
            while(cnt<=n)
            {
                if(cnt!=i)
                adj2[i].push_back(cnt);
                cnt++;
            }
    }
    /*for(j=1;j<=n;j++)
    {for(auto i=adj2[j].begin();i!=adj2[j].end();i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;}*/
    q.push(1);
    vis[1]=1;
    dist1[1]=0;
    while(!q.empty())
    {
       int top=q.front();
       q.pop();
       for(i=0;i<adj1[top].size();i++)
       {
           if(vis[adj1[top][i]]==0)
           {
               vis[adj1[top][i]]=1;
               dist1[adj1[top][i]]=dist1[top]+1;
               q.push(adj1[top][i]);
           }
           if(adj1[top][i]==n)
           {
               f1=1;
           }
       }
    }
    memset(vis,0,sizeof(vis));
    q.push(1);
    while(!q.empty())
    {
       int top=q.front();
       q.pop();
       for(i=0;i<adj2[top].size();i++)
       {
           if(vis[adj2[top][i]]==0)
           {
               vis[adj2[top][i]]=1;
               dist2[adj2[top][i]]=dist2[top]+1;
               q.push(adj2[top][i]);
           }
           if(adj2[top][i]==n)
           {
               f2=1;
           }
       }
    }
    if(f1==-1||f2==-1)
        cout<<"-1";
    else
    {
        cout<<max(dist1[n],dist2[n]);
    }
    return 0;
}
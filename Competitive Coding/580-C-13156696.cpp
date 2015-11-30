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
int a[100009];
vector<int> adj[100009];
int visit[100009];
int dist[100009];
int main()
{
    int n,m,i,j;
    s(n);
    s(m);
    f(i,n)
    {
        s(a[i]);
    }
    int u,v;
    f(i,n-1)
    {
        cin>>u>>v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
    queue<int>q;
    q.push(0);
    int c=0;
    dist[0]=a[0]==1?1:0;

    while(!q.empty())
    {   int f=0;
        int top=q.front();
        visit[top]=1;
        q.pop();
        if(top!=0&&adj[top].size()==1)
        {
            c++;
            f=1;
        }
        f(i,adj[top].size())
        {int curr=adj[top][i];
            if(visit[curr]==0)
            {
                q.push(curr);
                if(dist[top]>m)
                    dist[curr]=m+1;
                else if(a[curr]==1&&dist[top]!=0)
                dist[curr]=dist[top]+1;
                else
                    dist[curr]=a[curr];
                        visit[curr]=1;
            }
        }
        //dist[top]+=a[top]==1?1:0;
        if(f==1&&dist[top]>m)
        {
            c--;
        }
    }
    cout<<c;
    return 0;
}
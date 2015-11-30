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
//typedef pair<int,int> P;
pair<long long int , pair<int,int> >s[1000005];
LL a[1005][1005];
int visit[1005];
int main()
{
    int n,i,j;
    cin>>n;
    //memset(a,0,sizeof(a));
    for(i=1;i<2*n;i++)
    {
        for(j=0;j<i;j++)
        {
            cin>>a[i][j];
        }
    }
    int k=0;
   int p[1005];
    for(i=1;i<2*n;i++)
    {
        for(j=0;j<i;j++)
        {
            s[k].first=a[i][j];
            s[k].second.first=i+1;
            s[k].second.second=j+1;
            k++;
        }
    }
    sort(s,s+k);
    int c=0;
    int z=k-1;
    j=0;
    while(z>=0)
    {
        pair<long long int,pair<int,int> > top=s[z];
        if(visit[top.second.first]==0&&visit[top.second.second]==0)
        {
            c+=2;
            visit[top.second.first]=1;
            visit[top.second.second]=1;
            p[top.second.first]=top.second.second;
            p[top.second.second]=top.second.first;
        }
        z--;
        if(c==2*n)
            break;
       //break;
    }
    for(i=1;i<=2*n;i++)
    {
        if(p[i]==0)
            cout<<i<<" ";
        else
        cout<<p[i]<<" ";
    }
    return 0;
}
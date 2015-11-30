#include <bits/stdc++.h>
#define sflld(n) scanf("%lld",&n)
#define sfulld(n) scanf("%llu",&n)
#define sfd(n) scanf("%d",&n)
#define sfld(n) scanf("%ld",&n)
#define sfs(n) scanf("%s",&n)
#define ll long long
#define ull unsigned long long int
#define pflld(n) printf("%lld\n",n)
#define pfd(n) printf("%d\n",n)
#define pfld(n) printf("%ld\n",n)
#define lt 2*idx
#define rt 2*idx+1
#define MAX 100005
#define f first
#define sf second.first
#define ss second.second


using namespace std;
ll a[MAX],sm,wt[MAX];
int st[4*MAX],lz[4*MAX],n;
void relax(int i,int j,int idx)
{
    if(lz[idx]!=1000)
    {
        st[idx]=min(st[idx],(j-i+1)*lz[idx]);
        if(i!=j)
        {
            lz[lt]=min(lz[idx],lz[lt]);
            lz[rt]=min(lz[idx],lz[rt]);
        }
        lz[idx]=1000;
    }
}
void build(int i,int j,int idx)
{
    cout<<"n"<<idx<<" "<<i<<" "<<j<<endl;
    lz[idx]=1000;
    if(i==j)
    {
        st[idx]=1000;
        return;
    }
    int m=(i+j)>>1;
    build(i,m,lt);
    build(m+1,j,rt);
    cout<<idx<<endl;
    st[idx]=st[lt]+st[rt];
    for(int o=1;o<2*n;o++)
        cout<<i<<" "<<j<<" "<<idx<<" "<<st[o]<<endl;
}
void update(int i,int j,int p,int q,int idx,int v)
{
    relax(i,j,idx);
    if(i>j||i>q||j<p)
        return;
    if(p<=i&&j<=q)
    {
        lz[idx]=v;
        relax(i,j,idx);
        return;
    }
    int m=(i+j)>>1;
    update(i,m,p,q,lt,v);
    update(m+1,j,p,q,rt,v);
    if(i!=j)
         st[idx]=st[lt]+st[rt];
}
int find(int i,int j,int p,int idx)
{
    relax(i,j,idx);
    //cout<<idx<<" "<<i<<j<<" "<<st[idx]<<endl;
    if(i==j&&i==p)
        return st[idx];
    int m=(i+j)>>1;
    if(p<=m)
        return find(i,m,p,lt);
    else
        return find(m+1,j,p,rt);
}
int ct[MAX];
ll dp[100005][505];
int main()
{
    freopen("C:\\Users\\DARPAN\\Desktop\\a.txt","r",stdin);
    freopen("C:\\Users\\DARPAN\\Desktop\\aa.txt","w",stdout);
    int t,m,k,l,r,w,i,j,v[MAX],len;
    sfd(t);
    while(t--)
    {
        sfd(n);
        sfd(k);
        sfd(m);
        sm=0;
        len=0;
        for(i=0;i<n;i++)
           {
               sflld(a[i]);
               sm+=a[i];
               if(a[i]<0)
               {
                   v[len]=i;
                   wt[len]=a[i]*(-1);
                   ct[len]=10000;
                   len++;
               }
            }
        build(0,n-1,1);
        for(i=0;i<m;i++)
        {
            sfd(l);
            sfd(r);
            sfd(w);
            l--;r--;
            if(w<=k)
            {
                update(0,n-1,l,r,1,w);
            }
            for(j=1;j<2*n;j++)
            cout<<st[j]<<endl;
        }

        m=len;
        //memset(dp,0,sizeof(dp));
        for(i=0;i<=m;i++)
        {
            ct[i-1]=find(0,n-1,v[i-1],1);
            cout<<v[i-1]<<endl;
           for(j=0;j<=k;j++)
           {
              if(i==0||j==0)
                dp[i][j]=0;
               else if(j-ct[i-1]>=0)
               {
                   dp[i][j]=max(dp[i-1][j-ct[i-1]]+wt[i-1],dp[i-1][j]);
               }
               else
                dp[i][j]=dp[i-1][j];
           }
        }
        //cout<<sm;
        pflld(sm+dp[m][k]);
    }
    return 0;
}

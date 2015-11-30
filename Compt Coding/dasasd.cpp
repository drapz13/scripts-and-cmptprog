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
#define mod 1000000007
using namespace std;
ll st[4*MAX+40],a[MAX],la[4*MAX+40],lm[4*MAX+40],li[4*MAX+40];
void relax(int i,int j,int idx)
{
   if(li[idx]!=0)
   {
       st[idx]=((j-i+1)*li[idx])%mod;
       if(i!=j)
       {
           li[lt]=li[idx];
           li[rt]=li[idx];
           la[lt]=la[rt]=0;
           lm[lt]=lm[rt]=1;
       }
       li[idx]=0;
     // return;
   }
   if(lm[idx]!=1)
   {
       st[idx]=(st[idx]*lm[idx])%mod;

       if(i!=j)
       {
           lm[lt]=(lm[lt]*lm[idx])%mod;
           lm[rt]=(lm[rt]*lm[idx])%mod;
           la[lt]=(la[lt]*lm[idx])%mod;
           la[rt]=(la[rt]*lm[idx])%mod;
       }
       lm[idx]=1;
   }
   if(la[idx]!=0)
   {
         st[idx]=(st[idx]+((j-i+1)*la[idx])%mod)%mod;
         if(i!=j)
         {
             la[lt]=(la[lt]+la[idx])%mod;
             la[rt]=(la[rt]+la[idx])%mod;
         }
         la[idx]=0;
   }

}
void init(int i,int j,int idx)
{
    la[idx]=0;
    li[idx]=0;
    lm[idx]=1;
    if(i==j)
    {
        st[idx]=a[i]%mod;
        return;
    }
    int m=(i+j)>>1;
    init(i,m,lt);
    init(m+1,j,rt);
    st[idx]=(st[lt]%mod+st[rt]%mod)%mod;
}

void update(int i,int j,int a,int b,ll val,int d,int idx)
{
    relax(i,j,idx);
    if(i>j||i>b||j<a)
        return;
    if(i>=a&&j<=b)
    {
          if(d==1)
          {
              la[idx]=(la[idx]+val)%mod;
          }
          else if(d==2)
          {
              la[idx]=(la[idx]*val)%mod;
              lm[idx]=(lm[idx]*val)%mod;
          }
          else if(d==3)
          {
              li[idx]=(val)%mod;
              la[idx]=0;
              lm[idx]=1;
          }
          relax(i,j,idx);
          return;
    }
    int m=(i+j)>>1;
    update(i,m,a,b,val,d,lt);
    update(m+1,j,a,b,val,d,rt);
    if(i!=j)
    {
        st[idx]=(st[lt]+st[rt])%mod;
    }
}
ll query(int i,int j,int a,int b,int idx)
{
    relax(i,j,idx);
    if(i>j||i>b||j<a)
        return 0;
    if(i>=a&&j<=b)
        return st[idx];
    int m=(i+j)>>1;
    ll l=query(i,m,a,b,lt);
    ll r=query(m+1,j,a,b,rt);
    return (l+r)%mod;
}
int main()
{
    int n,q,i,d,x,y;
    ll val;
    sfd(n);
    sfd(q);
    memset(a,0,sizeof(a));
    for(i=0;i<n;i++)
        sflld(a[i]);
    init(0,n-1,1);
    //pflld(query(0,n-1,0,n-1,1));
    while(q--)
    {
       sfd(d);
       sfd(x);
       sfd(y);
       if(d==4)
       {
           pflld(query(0,n-1,x-1,y-1,1));
       }
       else
       {
           sflld(val);
           update(0,n-1,x-1,y-1,val,d,1);
       }

    }
    return 0;
}

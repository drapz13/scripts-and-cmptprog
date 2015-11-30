#include <bits/stdc++.h>
#define pb push_back
#define _ ios_base::sync_with_stdio(false);cin.tie(0);
#define __ int t;cin>>t;while(t--)
#define endl '\n'
#define MOD 1000000007
#define trct 1000

using namespace std;
long long a[100005];
long long b[100005];
int c[100005];
int d[100005];
int st[400505];
int s_t[400505];
long long dp[100005][505];
int n,k;
long long s=0;
void trv(int x1,int f,int g)
{
    if(s_t[x1]!=trct)
    {
        st[x1]=min(st[x1],(g-f+1)*s_t[x1]);
        if(f!=g)
        {
            s_t[x1<<1]=min(s_t[x1<<1],s_t[x1]);
            s_t[(x1<<1)+1]=min(s_t[(x1<<1)+1],s_t[x1]);
        }
        s_t[x1]=trct;
    }
}

long long stsearch(int x1,int f,int g,int a1)
{
    trv(x1,f,g);
    //cout<<x1<<" "<<f<<g<<" "<<st[x1]<<endl;
    if(a1==f&&f==g)
    {
        return st[x1];
    }
    if(a1<=((f+g)>>1))
        return stsearch(x1<<1,f,(f+g)>>1,a1);
    else
        return stsearch(1+(x1<<1),1+((f+g)>>1),g,a1);
}

void stupdate(int x1,int f,int g,int a1,int b1,int val)
{
    trv(x1,f,g);
    if(f>g||f>b1||g<a1) return;
    if(a1<=f&&b1>=g)
    {
        s_t[x1]=val;
        trv(x1,f,g);
        return;
    }
    stupdate(x1<<1,f,(f+g)>>1,a1,b1,val);
    stupdate((x1<<1)+1,1+((f+g)>>1),g,a1,b1,val);
    if(f!=g) st[x1]=(st[x1<<1]+ st[(x1<<1)+1]);
}
void constr(int nde,int a1,int b1)
{
    //cout<<"n"<<nde<<" "<<a1<<" "<<b1<<endl;
    s_t[nde]=trct;
    if(a1==b1)
    {
        st[nde]=trct;
        return;
    }
    constr(nde<<1,a1,(a1+b1)>>1);
    constr((nde<<1)+1,1+((a1+b1)>>1),b1);
    //cout<<nde<<endl;
    st[nde]=(st[nde<<1] + st[(nde<<1)+1]);
    //for(int o=1;o<2*n;o++)
    //    cout<<a1<<" "<<b1<<" "<<nde<<" "<<st[o]<<endl;
}
long long knapsack(int x)
{
    for(int i=0;i<=x;i++)
    {
        d[i-1]=stsearch(1,0,n-1,c[i-1]);
        //cout<<c[i-1]<<endl;
        for(int j=0;j<=k;j++)
        {
            if(i==0||j==0) dp[i][j]=0;
            else if(d[i-1]<=j)
            {
               dp[i][j]=max(dp[i-1][j],dp[i-1][j-d[i-1]]+b[i-1]);
            }
            else dp[i][j]=dp[i-1][j];
        }
    }
    return dp[x][k];

}
int main()
{
    //freopen("C:\\Users\\DARPAN\\Desktop\\a.txt","r",stdin);
    //freopen("C:\\Users\\DARPAN\\Desktop\\ab.txt","w",stdout);
    _        ///  FAST I/O
    __       ///  T TEST CASES
    {
        int m,v=0;
        cin>>n>>k>>m;
        s=0LL;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            s+=a[i];
            if(a[i]<0)
            {
                b[v]=-1*a[i];
                c[v]=i;
                d[v]=trct*10;
                v++;
            }
        }
        constr(1,0,n-1);
        for(int i=0;i<m;i++)
        {
            int l,r,c;
            cin>>l>>r>>c;
            if(c<=k)
            {
                stupdate(1,0,n-1,l-1,r-1,c);
            }
        }

        //cout<<s;
        s+=knapsack(v);
        cout<<s<<endl;
    }
    return 0;
}

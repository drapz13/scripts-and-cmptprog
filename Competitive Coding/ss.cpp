#include <bits/stdc++.h>
#define pb push_back
#define _ ios_base::sync_with_stdio(false);cin.tie(0);
#define __ int t;cin>>t;while(t--)
#define endl '\n'
#define MOD 1000000007

using namespace std;
long long a[100005];
long long st[400505];
long long s_t[400505][3];

void trv(int x1,int f,int g)
{
    if(s_t[x1][0]!=0)
    {
        st[x1]=((g-f+1)*s_t[x1][0])%MOD;
        if(f!=g)
        {
            s_t[x1<<1][0]=s_t[x1][0];
            s_t[(x1<<1)+1][0]=s_t[x1][0];
            s_t[x1<<1][1]=0;
            s_t[(x1<<1)+1][1]=0;
            s_t[x1<<1][2]=1;
            s_t[(x1<<1)+1][2]=1;
        }
        s_t[x1][0]=0;
    }
    if(s_t[x1][1]!=0)
    {
        st[x1]=(st[x1]+((g-f+1)*s_t[x1][1])%MOD)%MOD;
        if(f!=g)
        {
            s_t[x1<<1][1]+=s_t[x1][1];
            s_t[x1<<1][1]%=MOD;
            s_t[(x1<<1)+1][1]+=s_t[x1][1];
            s_t[(x1<<1)+1][1]%=MOD;
        }
        s_t[x1][1]=0;
    }
    if(s_t[x1][2]!=1)
    {
        st[x1]=(st[x1]*s_t[x1][2])%MOD;
        if(f!=g)
        {
            s_t[x1<<1][2]*=s_t[x1][2];
            s_t[(x1<<1)+1][2]*=s_t[x1][2];
            s_t[x1<<1][1]*=s_t[x1][2];
            s_t[(x1<<1)+1][1]*=s_t[x1][2];
            s_t[x1<<1][2]%=MOD;
            s_t[x1<<1][1]%=MOD;
            s_t[(x1<<1)+1][2]%=MOD;
            s_t[(x1<<1)+1][1]%=MOD;
        }
        s_t[x1][2]=1;
    }
}
void val_add(int x1,int f,int g,int a1,int b1,int val)
{
    trv(x1,f,g);
    if(f>g||f>b1||g<a1)return;
    if(f>=a1&&g<=b1)
    {
        s_t[x1][1]+=val;
        s_t[x1][1]%=MOD;
        trv(x1,f,g);
        return;
    }
    val_add(x1<<1,f,(f+g)>>1,a1,b1,val);
    val_add((x1<<1)+1,1+(f+g)>>1,g,a1,b1,val);
    if(f!=g) st[x1]=(st[x1<<1]+st[(x1<<1)+1])%MOD;
}
void val_mul(int x1,int f,int g,int a1,int b1,int val)
{
    trv(x1,f,g);
    if(f>g||f>b1||g<a1)return;
    if(f>=a1&&g<=b1)
    {
        s_t[x1][1]*=val;
        s_t[x1][1]%=MOD;
        s_t[x1][2]*=val;
        s_t[x1][2]%=MOD;
        trv(x1,f,g);
        return;
    }
    val_mul(x1<<1,f,(f+g)>>1,a1,b1,val);
    val_mul((x1<<1)+1,1+(f+g)>>1,g,a1,b1,val);
    if(f!=g) st[x1]=(st[x1<<1]+st[(x1<<1)+1])%MOD;
}
void val_update(int x1,int f,int g,int a1,int b1,int val)
{
    trv(x1,f,g);
    if(f>g||f>b1||g<a1)return;
    if(f>=a1&&g<=b1)
    {
        s_t[x1][0]=val%MOD;
        s_t[x1][1]=0;
        s_t[x1][2]=1;
        trv(x1,f,g);
        return;
    }
    val_update(x1<<1,f,(f+g)>>1,a1,b1,val);
    val_update((x1<<1)+1,1+(f+g)>>1,g,a1,b1,val);
    if(f!=g) st[x1]=(st[x1<<1]+st[(x1<<1)+1])%MOD;
}

long long stupdate(int x1,int f,int g,int a1,int b1)
{
    trv(x1,f,g);
    if(f>g||f>b1||g<a1) return 0;
    if(a1<=f&&b1>=g)
    {
        return st[x1];
    }
    return ((stupdate(x1<<1,f,(f+g)>>1,a1,b1)+stupdate((x1<<1)+1,1+(f+g)>>1,g,a1,b1))%MOD);
}

void constr(int nde,int a1,int b1)
{
    s_t[nde][0]=0;
    s_t[nde][1]=0;
    s_t[nde][2]=1;
    if(a1==b1)
    {
        st[nde]=a[a1]%MOD;
        return;
    }
    constr(nde<<1,a1,(a1+b1)>>1);
    constr((nde<<1)+1,1+(a1+b1)>>1,b1);
    st[nde]=(st[nde<<1]%MOD+st[(nde<<1)+1]%MOD)%MOD;
}
int main()
{
    _
    int n,q;
    memset(a,0,sizeof a);
    cin>>n>>q;
    for(int i=0;i<n;i++) cin>>a[i];
    constr(1,0,n-1);

    while(q--)
    {
        int w;
        cin>>w;
        switch (w)
        {
            case 1:
            {
                int x,y;
                long long v;
                cin>>x>>y>>v;
                x--,y--;
                val_add(1,0,n-1,x,y,v);
                break;
            }
            case 2:
            {
                int x,y;
                long long v;
                cin>>x>>y>>v;
                x--,y--;
                val_mul(1,0,n-1,x,y,v);
                break;
            }
            case 3:
            {
                int x,y;
                long long v;
                cin>>x>>y>>v;
                x--,y--;
                val_update(1,0,n-1,x,y,v);
                break;
            }
            case 4:
            {
                int x,y;
                cin>>x>>y;
                x--,y--;
                cout<<stupdate(1,0,n-1,x,y)<<endl;
                break;
            }
        }
    }
    return 0;
}

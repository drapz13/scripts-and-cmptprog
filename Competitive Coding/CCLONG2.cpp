#include <bits/stdc++.h>
#define pb push_back
#define _ ios_base::sync_with_stdio(false);cin.tie(0);
#define __ int t;cin>>t;while(t--)
#define endl '\n'
#define MOD 1000000007

using namespace std;
int a[100005];
int st[500005];
int s_t[500005][2];

void trv(int x1,int f,int g)
{
    if(s_t[x1][0]!=0)
    {
        int xx=s_t[x1][1];
        if(xx==1) st[x1]=(st[x1]+((g-f+1)*s_t[x1][0]))%MOD;
        else if(xx==2) st[x1]=(st[x1]*s_t[x1][0])%MOD;
        else st[x1]=((g-f+1)*s_t[x1][0])%MOD;
        if(f!=g)
        {
            s_t[x1<<1][0]=s_t[x1][0];
            s_t[x1<<1][1]=xx;
            s_t[(x1<<1)+1][0]=s_t[x1][0];
            s_t[(x1<<1)+1][1]=xx;
        }
        s_t[x1][0]=0;
    }
}
void val_add(int x1,int f,int g,int a1,int b1,int val)
{
    trv(x1,f,g);
    if(f>g||f>b1||g<a1)return;
    if(f>=a1&&g<=b1)
    {
        if(s_t[x1][0]) trv(x1,f,g);
        s_t[x1][0]=val;
        s_t[x1][1]=1;
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
        if(s_t[x1][0]) trv(x1,f,g);
        s_t[x1][0]=val;
        s_t[x1][1]=2;
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
        if(s_t[x1][0]) trv(x1,f,g);
        s_t[x1][0]=val;
        s_t[x1][1]=3;
        trv(x1,f,g);
        return;
    }
    val_update(x1<<1,f,(f+g)>>1,a1,b1,val);
    val_update((x1<<1)+1,1+(f+g)>>1,g,a1,b1,val);
    if(f!=g) st[x1]=(st[x1<<1]+st[(x1<<1)+1])%MOD;
}

int stupdate(int x1,int f,int g,int a1,int b1)
{
    if(f>g||f>b1||g<a1) return -INT_MAX;
    if(a1<=f&&b1>=g)
    {
        return st[x1];
    }
    return ((stupdate(x1<<1,f,(f+g)>>1,a1,b1)+stupdate((x1<<1)+1,1+(f+g)>>1,g,a1,b1))%MOD);
}

void constr(int nde,int a1,int b1)
{
    if(a1>b1) return;
    if(a1==b1)
    {
        st[nde]=a[a1]%MOD;
        return;
    }
    constr(nde<<1,a1,(a1+b1)>>1);
    constr((nde<<1)+1,1+(a1+b1)>>1,b1);
    st[nde]=(st[nde<<1]+st[(nde<<1)+1])%MOD;
}
int main()
{
    _
    int n,q;
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
                int x,y,v;
                cin>>x>>y>>v;
                x--,y--;
                val_add(1,0,n-1,x,y,v);
                break;
            }
            case 2:
            {
                int x,y,v;
                cin>>x>>y>>v;
                x--,y--;
                val_mul(1,0,n-1,x,y,v);
                break;
            }
            case 3:
            {
                int x,y,v;
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

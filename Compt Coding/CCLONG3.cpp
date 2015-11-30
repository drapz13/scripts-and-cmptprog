#include <bits/stdc++.h>
#define pb push_back
#define _ ios_base::sync_with_stdio(false);cin.tie(0);
#define __ int t;cin>>t;while(t--)
#define endl '\n'
#define MOD 1000000007

using namespace std;
int n,q,x,y;
long long v;
int R[1000005];
int M[1000005];
int A[1000005];
int a[100005];
int sum[100005];
int b[1000005];
int c[1000005];
int st[1000005];
long long get_mid(long long int a,long long int b)
{
    return ((a+b)>>1);
}

void arr_update(int x1,long long val,int xx)
{
    switch(xx)
    {
        case 1:
            A[x1]=(A[x1]+val)%MOD;
            break;
        case 2:
            M[x1]=(M[x1]*val)%MOD;
            A[x1]=(A[x1]*val)%MOD;
            break;
        case 3:
            R[x1]=val;
            M[x1]=1;
            A[x1]=0;
            break;
    }
}
void val_update(int x1,int a1,int b1,long long val,int xx)
{
    /*cout<<xx<<"a";
    for(int i=1;i<=n;i++)
    {
        cout<<b[i]<<" "<<c[i]<<endl;
    }*/
    if(b[x1]==a1 && c[x1]==b1)
    {
        switch(xx)
        {
        case 1:
            A[x1]=(A[x1]+val)%MOD;
            break;
        case 2:
            M[x1]=(M[x1]*val)%MOD;
            A[x1]=(A[x1]*val)%MOD;
            break;
        case 3:
            R[x1]=val;
            M[x1]=1;
            A[x1]=0;
            break;
        }
        /*for(int i=1;i<=n;i++)
    {
        cout<<b[i]<<" "<<c[i]<<endl;
    }*/

    //cout<<"a";

        if(b[x1]!=c[x1])
        {
            if(R[x1]!=-1)
            {
                arr_update(x1<<1,R[x1],3);
                arr_update((x1<<1)+1,R[x1],3);
            }
            arr_update(x1<<1,M[x1],2);
            arr_update((x1<<1)+1,M[x1],2);
            arr_update(x1<<1,A[x1],1);
            arr_update((x1<<1)+1,A[x1],1);
        }
        if(R[x1]!=-1)
        {
            st[x1]=R[x1]*(c[x1]-b[x1]+1);
        }
        st[x1]=(st[x1]*M[x1])%MOD;
		st[x1]=(st[x1]+A[x1]*(c[x1]-b[x1]+1))%MOD;
		A[x1]=0;
		M[x1]=1;
		R[x1]=-1;
		return;
    }
    //cout<<"a";
    int m=get_mid(b[x1],c[x1]);
    if(R[x1]!=-1)
    {
        arr_update(x1<<1,R[x1],3);
        arr_update((x1<<1)+1,R[x1],3);
    }
    arr_update(x1<<1,M[x1],2);
    arr_update((x1<<1)+1,M[x1],2);
    arr_update(x1<<1,A[x1],1);
    arr_update((x1<<1)+1,A[x1],1);
    A[x1]=0;
    M[x1]=1;
    R[x1]=-1;
    if(m>=b1)
    {
		val_update(x1<<1,a1,b1,val,xx);
		val_update((x1<<1)+1,m+1,c[x1],0,1);
	}
	else if(m<a1)
	{
		val_update(x1<<1,b[x1],m,0,1);
        val_update((x1<<1)+1,a1,b1,val,xx);
	}
	else
    {
		val_update(x1<<1,a1,m,val,xx);
        val_update((x1<<1)+1,m+1,b1,val,xx);

	}
    st[x1]=(st[x1<<1]+st[(x1<<1)+1])%MOD;
    /*for(int i=1;i<=n;i++)
    {
        cout<<st[i]<<" "<<A[i]<<" "<<M[i]<<" "<<R[i]<<" "<<b[i]<<" "<<c[i]<<endl;
    }*/
}

long long stupdate(int x1,int a1,int b1)
{
    if(b[x1]==a1 && c[x1]==b1)
    {
        if(a1!=b1)
        {
            if(R[x1]!=-1)
            {
                arr_update(x1<<1,R[x1],3);
                arr_update((x1<<1)+1,R[x1],3);
            }
            arr_update(x1<<1,M[x1],2);
            arr_update((x1<<1)+1,M[x1],2);
            arr_update(x1<<1,A[x1],1);
            arr_update((x1<<1)+1,A[x1],1);
            if(R[x1]!=-1)
            {
                st[x1]=R[x1]*(c[x1]-b[x1]+1);
            }
            st[x1]=(st[x1]*M[x1])%MOD;
            st[x1]=(st[x1]+A[x1]*(c[x1]-b[x1]+1))%MOD;
            A[x1]=0;
            M[x1]=1;
            R[x1]=-1;
            return st[x1];
        }
    }
    if(b[a1]!=c[b1])
    {
        if(R[x1]!=-1)
        {
            arr_update(x1<<1,R[x1],3);
            arr_update((x1<<1)+1,R[x1],3);
        }
        arr_update(x1<<1,M[x1],2);
        arr_update((x1<<1)+1,M[x1],2);
        arr_update(x1<<1,A[x1],1);
        arr_update((x1<<1)+1,A[x1],1);
    }
    if(R[x1]!=-1)
    {
        st[x1]=R[x1]*(c[x1]-b[x1]+1);
    }
    st[x1]=(st[x1]*M[x1])%MOD;
    st[x1]=(st[x1]+A[x1]*(c[x1]-b[x1]+1))%MOD;
    A[x1]=0;
    M[x1]=1;
    R[x1]=-1;
    int m=get_mid(b[x1],c[x1]);
    if(m>=b1)
    {
		return stupdate(x1<<1,a1,b1);
	}
	else if(m<a1)
	{
		return stupdate((x1<<1)+1,a1,b1);
	}
	else
    {
		return (stupdate(x1<<1,a1,m)+stupdate((x1<<1)+1,m+1,b1))%MOD;
	}
}

void constr(int nde,int a1,int b1)
{
    b[nde]=a1;
    c[nde]=b1;
    st[nde]=sum[b1]-sum[a1-1];
    M[nde]=1;
    R[nde]=-1;
    A[nde]=0;
    if(a1!=b1)
    {
        int m=get_mid(a1,b1);
        constr(nde<<1,a1,m);
        constr((nde<<1)+1,m+1,b1);
    }
}
int main()
{
    _
    //freopen("C:\\Users\\DARPAN\\Desktop\\ab.txt","w",stdout);
	//freopen("C:\\Users\\DARPAN\\Desktop\\a.txt","r",stdin);
    cin>>n>>q;
    sum[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum[i]=a[i]+sum[i-1];
    }
    constr(1,1,n);
    while(q--)
    {
        //cout<<"a";
        int w;
        cin>>w;
        if(w!=4)
        {
            //cout<<w;
            cin>>x>>y>>v;
            //cout<<"a";
            val_update(1,x,y,v,w);
            //cout<<q;
        }
        else
        {
            //cout<<"a";
            cin>>x>>y;
            cout<<(stupdate(1,x,y)+MOD)%MOD<<endl;
        }
    }
    return 0;
}

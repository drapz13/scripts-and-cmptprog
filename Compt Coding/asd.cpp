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
#define maxn 1000005
#define mod 1000000007
bool comp(const int& a, const int& b)
       {
          return a<b?false:true;//min_heap
       }
using namespace std;
typedef pair<int,int> P;
int visit[1000009],dist[1000009];
int prime[1000009],ans[1000009];
void prime_()
{
    memset(prime,1,sizeof(prime));
    for(int i=2;i*i<=maxn;i++)
    {
        if(prime[i])
        for(int j=i*i;j<=maxn;j=j+i)
        {
            prime[j]=0;
        }
    }
    int j=0;
    for(int i=2;i<maxn;i++)
    {
        if(prime[i])
        {
            ans[j]=i;
            j++;
        }
    }
}
int num(int a)
{
    int c=0;
    while(a)
    {
        a=a/10;
        c++;
    }
    return c;
}
int pow_(int a,int b)
{
    int temp=1;
    for(int i=0;i<b;i++)
    {
        temp*=a;
    }
    return temp;
}
int main()
{
    prime_();
    queue<int>q;
    int t,a,b,sr,dest,i,j;

    s(t);
    w(t)
    {
        cin>>a>>b;
        sr=a;
        dest=b;
    int n=num(sr);
    memset(dist,0,sizeof(dist));
	memset(visit,0,sizeof(visit));
	    q.push(sr);
	    visit[sr]=1;
	    while(!q.empty())
        {
            int top=q.front();
            q.pop();

            for(i=0;i<n;i++)
            {
                if(i!=(n-1)||(top/pow_(10,i)!=9))
                {
                    int c=(top/pow_(10,i));
                    int le=c%10;
                    le=(le+1)%10;
                    int d=top/pow_(10,i+1);
                    int b=d*pow_(10,i+1)+le*pow_(10,i)+top%pow_(10,i);

                    if(!prime[b]&&visit[b]==0)
                    {   //cout<<b<<" ";
                        q.push(b);
                        dist[b]=dist[top]+1;
                        visit[b]=1;
                    }
                }
            }
            if(visit[b]==1)
                break;
        }
        while(!q.empty())
            q.pop();
            if(visit[dest])
        cout<<dist[dest]<<endl;
        else
            cout<<"Cunning Ashu\n";
    }
	return 0;
}

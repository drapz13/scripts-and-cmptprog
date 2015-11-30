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
int x[4],y[4];
int main()
{
    int n,i,j;
    cin>>n;
    f(i,n)
    {
        cin>>x[i]>>y[i];
    }
    if(n==1)
    {
        cout<<"-1\n";
    }
    else if(n==3||n==4)
    {
        int len,bre;
        if(x[0]==x[1])
            len=abs(x[2]-x[0]);
        else if(x[0]==x[2])
        {
            len=abs(x[1]-x[0]);
        }
        else if(n==4&&x[0]==x[3])
        {
            len=abs(x[1]-x[0]);
        }
        else if(x[1]==x[2])
        {
            len=abs(x[0]-x[1]);
        }
        else if(n==4&&x[1]==x[3])
        {
            len=abs(x[2]-x[1]);
        }
        else if(n==4&&x[2]==x[3])
        {
            len=abs(x[0]-x[2]);
        }
        if(y[0]==y[1])
            bre=abs(y[2]-y[0]);
        else if(y[0]==y[2])
        {
            bre=abs(y[1]-y[0]);
        }
        else if(n==4&&y[0]==y[3])
        {
            bre=abs(y[1]-y[0]);
        }
        else if(y[1]==y[2])
        {
            bre=abs(y[0]-y[1]);
        }
        else if(n==4&&y[1]==y[3])
        {
            bre=abs(y[0]-y[1]);
        }
        else if(n==4&&y[2]==y[3])
        {
            bre=abs(y[0]-y[2]);
        }
        cout<<len*bre;
    }
    else if(n==2)
    {
        int len=abs(x[1]-x[0]);
        int bre=abs(y[1]-y[0]);
        if(len!=0&&bre!=0)
        {
            cout<<len*bre;
        }
        else
            cout<<"-1";
    }
    return 0;
}
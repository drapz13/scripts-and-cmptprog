#include<cstdio>
#include<iostream>
#include<vector>
#include<utility>
#include<string.h>
#include<algorithm>
#include<cmath>

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

using namespace std;
int a[1009][1009];
int main()
{
    int c,d,i,j,n,m,k,f=0,pos;
    cin>>n>>m>>k;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            a[i][j]=0;
        }
    }
    for(i=0;i<k;i++)
    {
        cin>>c>>d;
        c=c-1;
        d=d-1;
        a[c][d]=1;
        if(f==0)
        {if(a[c-1][d]==1&&c>=1)
        {
            if(a[c][d-1]==1&&d>=1)
            {
                if(a[c-1][d-1]==1&&c>0&&d>0)
                {
                        f=1;
                }
            }
        }
        if(a[c+1][d]==1&&c<n-1)
        {
            if(a[c][d-1]==1&&d>=1)
            {
                if(a[c+1][d-1]==1&&c<n-1&&d>0)
                {
                        f=1;

                }
            }
        }
        if(a[c-1][d]==1&&c>=1)
        {
            if(a[c][d+1]==1&&d<m-1)
            {
                if(a[c-1][d+1]==1&&c>0&&d<m-1)
                {
                        f=1;

                }
            }
        }
        if(a[c+1][d]==1&&c<n-1)
        {
            if(a[c][d+1]==1&&d<m-1)
            {
                if(a[c+1][d+1]==1&&c<n-1&&d<m-1)
                {
                        f=1;

                }
            }
        }
        if(f==1)
            pos=i;
        }
    }
    if(f==1)
    {
        cout<<pos+1<<endl;
    }
    else
        cout<<"0"<<endl;
	return 0;
}
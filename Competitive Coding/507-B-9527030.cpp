/*#include<cstdio>
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

int main()
{
    int r,x,y,x1,y1,xm,ym;
    cin>>r>>x>>y>>x1>>y1;
    xm = abs(x1-x)+abs(y1-y);
    if(xm<r)
    {
        xm=2;
    }
    else
    {xm=xm/r;
    if(xm%2==0)
    xm = xm/2;
    else
         xm=xm/2+1;}
    cout<<xm;
	return 0;
}*/
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

int main()
{
    int r,x,y,x1,y1;
    double xm,ym;
    cin>>r>>x>>y>>x1>>y1;
    xm = sqrt(pow(abs(x1-x),2)+pow(abs(y1-y),2));
    xm = ceil(xm/(r*2));
    cout<<xm;
	return 0;
}
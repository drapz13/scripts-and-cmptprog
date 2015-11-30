#include<cstdio>
#include<iostream>
#include<vector>
#include<utility>
#include<string.h>
#include<algorithm>
#include<cmath>

#define LL long long int
#define s(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define ss(a) scanf("%s",a)
#define w(t) while(t--)
#define f(i,n) for(i=0;i<n;i++)
#define fd(i,n) for(i=n-1;i>=0;i--)
#define p(a) printf("%d",a)
#define pl(a) printf("%lld",a)
#define ps(a) printf("%s",a)
#define pc(a) printf("%c",a)
#define ent printf("\n")

using namespace std;
string a,b,c,d;
int x[4];
int main()
{int i,j,pos1,pos2,maxx=-1,minx=1001;
    cin>>a>>b>>c>>d;
    x[0]=a.length()-2;
    x[1]=b.length()-2;
    x[2]=c.length()-2;
    x[3]=d.length()-2;
    for(i=0;i<4;i++)
    {maxx=max(maxx,x[i]);
    if(maxx==x[i])
        pos1=i;
    minx=min(minx,x[i]);
    if(minx==x[i])
        pos2=i;
    }
    int f=0,c=0,d=0;
    for(i=0;i<4;i++)
    {
        if(maxx>=2*x[i]&&i!=pos1)
        {
            c++;
        }
        if(2*minx<=x[i]&&i!=pos2)
        {
            d++;
        }
    }
    if(c==3&&d!=3)
    {
        cout<<(char)(pos1+1+64);
    }
    else if(c!=3&&d==3)
    {
        cout<<(char)(pos2+1+64);
    }
    else
    {
        cout<<"C";
    }
    return 0;
}
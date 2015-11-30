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
char a[100090];
int b[4];
int main()
{
    int n,i,j,k,l;
    cin>>n;
    cin>>a;
    long long int h,p;
    memset(b,0,4);
    for(i=0;i<n;i++)
    {
        if(a[i]-65==0)
            b[0]++;
        else if(a[i]=='C')
            b[1]++;
        else if(a[i]=='G')
            b[2]++;
        else if(a[i]=='T')
            b[3]++;
    }
    int d=0;
    int m=*max_element(b,b+4);
    for(i=0;i<4;i++)
    {
        if(b[i]==m)
        {
            d++;
        }
    }
    p=1;
    for(i=1;i<=n;i++)
    {
        p=p*d;
        p=p%1000000007;
    }

    cout<<p<<endl;
    return 0;
}
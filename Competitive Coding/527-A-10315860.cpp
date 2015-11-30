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
    LL a,b,c=0;
    cin>>a>>b;
    while(1)
    {
        if(a==0||b==0)
            break;
        if(a==1)
        {
            c=c+b;
            break;
        }
        else if(b==1)
        {
            c=c+a;
            break;
        }
        else if(a==b)
        {
            c=c+1;
            break;
        }
        else if(a>b)
        {
            c+=a/b;
            a=a%b;


        }
        else
        {
            c+=b/a;
            b=b%a;

        }
    }
    cout<<c<<endl;
    return 0;
}
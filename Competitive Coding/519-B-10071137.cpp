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

LL a[100090];

int main()
{   vector <long long int>b;
    vector <long long int>c;
    LL n1,n2,c1;
    int n,i,j,k;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<n-1;i++)
    {   cin>>c1;
        b.push_back(c1);
    }
    for(i=0;i<n-2;i++)
    {
        cin>>c1;
        c.push_back(c1);
    }
    sort(a,a+n);
        sort(b.begin(),b.end());
        sort(c.begin(),c.end());
    for(i=0;i<n;i++)
    {
        if(i==n)
        {n2=a[i];
        break;}
        if(a[i]==b[i])
        {

        }
        else
        {
            n1=a[i];
        break;
        }
    }
    for(i=0;i<n-1;i++)
    {
        if(i==n-1)
        {n2=b[i];
        break;}
        if(c[i]==b[i])
        {

        }
        else
        {
            n2=b[i];
        break;
        }
    }
    cout<<n1<<endl<<n2<<endl;
    return 0;
}
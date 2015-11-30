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
vector<long long int>a;
LL c;
LL _gcd(LL a,LL b)
{
    if(b==0)
        return a;
    else
        return _gcd(b,a%b);
}
int main()
{
    int i,j,n;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>c;
        a.push_back(c);
    }
    LL c,ma,gcd=0;
    for(i=0;i<n;i++)
    {
        gcd=_gcd(a[i],gcd);
    }
    ma=*max_element(a.begin(),a.end());
    c = ma/gcd;
    if((n-c)%2==0)
    {
        cout<<"Bob\n";
    }
    else
        cout<<"Alice\n";
    return 0;
}
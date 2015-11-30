#include<cstdio>
#include<iostream>
#include<vector>
#include<utility>
#include<string.h>
#include<algorithm>
#include<cmath>

//#define LL long long int
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
    vector <int> a;
    vector <int> b;
    int n,i,j,k,c,x=0;
    cin>>n;
    f(i,n)
    {cin>>c;
    a.push_back(c);
    b.push_back(a[i]);}
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    reverse(a.begin(),a.end());
    for(i=0;i<n;i++)
    {
    //cout<<x<<endl;
        if(i!=0&&i!=n-1)
        {
            cout<<a[n-i-1]<<" ";
        }
        else
            cout<<a[i]<<" ";
    }
    return 0;
}
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
    int i,j,n,k,sum=0;
    pair <int,int> a[190];
    cin>>n>>k;
    f(i,n)
    {
        s(a[i].first);
        a[i].second=i+1;
    }
    sort(a,a+n);
    for(i=0;i<n;i++)
    {
        sum+=a[i].first;
        if(sum>k)
        {
            break;
        }
    }
    cout<<i<<endl;
    for(j=0;j<i;j++)
    {
        cout<<a[j].second<<" ";
    }
	return 0;
}
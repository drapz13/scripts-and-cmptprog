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

#define mod 1000000007
bool comp(const int& a, const int& b)
       {
          return a<b?false:true;//min_heap
       }
using namespace std;
//int pow2[1000009]={0},cnt[1000009]={0};
#define maxn 100000
int main()
{
    int a[6],i;
    f(i,6)
    s(a[i]);
    LL areaR=0,area=0;
    areaR= 2*(((a[2]+a[0]+2*a[1])*(a[2]))+((a[3]+a[5]+2*a[4])*(a[3])));
    area  = a[3]*a[3]+a[2]*a[2]+a[0]*a[0]+a[5]*a[5];
    cout<<(areaR-area)/2;
    //area += (a[0]*a[0]+a[2]*a[2]+a[3]*a[3]+a[5]*a[5]);
    //area+= 2*(((a[0]+a[2])*a[1])+((a[3]+a[5])*a[4]));
    //cout<<area/2;
    return 0;
}
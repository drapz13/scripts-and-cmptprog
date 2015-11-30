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
int a[1009];
int main()
{
    int n,i;
    s(n);
    f(i,n)
    s(a[i]);
    sort(a,a+n);
    if(a[0]==1)
        cout<<"-1";
    else
        cout<<"1";
    return 0;
}
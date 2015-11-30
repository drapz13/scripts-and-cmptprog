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
#define maxn 100000
#define mod 1000000007
bool comp(const int& a, const int& b)
       {
          return a<b?false:true;//min_heap
       }
using namespace std;
typedef pair<int,int> P;
int a[1000009];
int main()
{
    int n,i;
    int maxx=0,minx=INT_MAX,posin=-1,posax=-1;
    s(n);
    f(i,n)
    {
        s(a[i]);
    }
    if(a[1]<=a[0])
    {
        minx=a[1];
        maxx=a[0];
        posax=0;
        posin=1;
        if(a[0]==a[1])
            posax=1;
    }
    else
    {
        minx=a[0];
        maxx=a[1];
        posin=0;
        posax=1;
    }
    int ans=2;
    int curr=2;
    for(i=2;i<n;i++)
    {
        if(abs(minx-a[i])==2||abs(maxx-a[i])==2)
        {
            if(a[i]<minx)
            {
                int temp=minx;
                maxx=temp;
                minx=a[i];
                ans=max(curr,ans);
                curr=i-posax;
                posax=posin;
                posin=i;
            }
            else
            {
                int temp=maxx;
                minx=temp;
                maxx=a[i];
                ans=max(curr,ans);
                curr=i-posin;
                posin=posax;
                posax=i;
            }
            //cout<<i<<" ";
        }
        else
        {
            if(a[i]==maxx)
            {
                maxx=a[i];
                posax=i;
            }
            if(a[i]==minx)
            {
                minx=a[i];
                posin=i;
            }
            if(a[i]>maxx)
            {
                maxx=a[i];
                posax=i;
            }
            if(a[i]<minx)
            {
                minx=a[i];
                posin=i;
            }
            curr++;
        }

    }
    ans=max(ans,curr);
    cout<<ans;
    return 0;
}
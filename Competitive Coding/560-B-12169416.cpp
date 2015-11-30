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
    int i,a1,a2,b1,b2,c1,c2;
    pair<int,int> f[10];
    for(i=0;i<10;i++)
        f[i].first=f[i].second=0;
    cin>>a1>>a2;
    cin>>b1>>b2;
    cin>>c1>>c2;
    if(b1<=a1&&b2<a2)
    {f[0].first=a1;
    f[0].second=a2-b2;
    }
    if(b1<a1&&b2<=a2)
    {f[1].first=a1-b1;
    f[1].second=a2;
    }
    if(b2<=a1&&b1<a2)
    {f[2].first=a1;
    f[2].second=a2-b1;
    }
    if(b1<=a2&&b2<a1)
    {f[3].first=a1-b2;
    f[3].second=a2;
    }
    if(f[0].first==0&&f[0].second==0&&f[1].first==0&&f[1].second==0&&f[2].first==0&&f[2].second==0&&f[3].first==0&&f[3].second==0)
    {
        cout<<"NO";
    }
    else
    {   int z=0;
        if((c1<=f[0].first&&c2<=f[0].second)||(c2<=f[0].first&&c1<=f[0].second))
        {
            cout<<"YES";
            z=1;
        }
        else if((c1<=f[1].first&&c2<=f[1].second)||(c2<=f[1].first&&c1<=f[1].second))
        {
            cout<<"YES";
            z=1;
        }
        else if((c1<=f[2].first&&c2<=f[2].second)||(c2<=f[2].first&&c1<=f[2].second))
        {
            cout<<"YES";
            z=1;
        }
        else if((c1<=f[3].first&&c2<=f[3].second)||(c2<=f[3].first&&c1<=f[3].second))
        {
            cout<<"YES";
            z=1;
        }
        else
            cout<<"NO";
    }
    return 0;
}
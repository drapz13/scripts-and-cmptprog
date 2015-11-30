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

int main()
{
	//_fast;
    int t,i,j;
    LL n,x,y;
    s(t);
    w(t)
    {
        cin>>n>>x>>y;
        int c=0;
        for(i=1;i*i<=n;i++)
        {
            if(n%i==0&&i<=x)
            {
                if((n/i)<=y)
                {
                    c+=1;
                }
            }
            if(n%i==0&&i<=y&&i*i!=n)
            {
                if((n/i)<=x)
                {
                    c+=1;
                }
            }
            cout<<n<<" "<<i<<endl;
        }
        cout<<c<<endl;
    }
	return 0;
}

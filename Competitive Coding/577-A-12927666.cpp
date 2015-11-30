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
int main()
{
    int j,k;
    LL i;
    LL n;
    LL x;
    cin>>n;
    cin>>x;
    if(x>n*n)
    {
        cout<<"0\n";
    }
    else
    {
        int c=0;
        for(i=1;i*i<=x;i++)
        {
            if(i>n)
            {
                break;
            }
            if(x%i==0&&(x/i)<=n)
            {
                c++;
                if(i*i!=x)
                {
                    c++;
                }
            }
        }
        cout<<c<<endl;

    }
    return 0;
}
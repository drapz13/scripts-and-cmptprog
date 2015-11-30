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
int che[100009];
int np[100001];
int n,l;
void sieve() {
    bool che[n+1];
    for(int i = 0; i <= n;++i) {
        che[i] = true;
    }
    che[0] = false;
    che[1] = false;
    for(int i = 2; i * i <= n; ++i) {
         if(che[i] == true) {
             for(int j = i * i; j <= n ;j += i)
                 che[j] = false;
        }
    }
    int j=0;
    for(int i=2;i<=n;i++)
    {
        if(che[i])
        {
            np[j]=i;
            j++;
        }
    }
    l=j;
}
int ans[1009];
int main()
{
    n=100000;
    int i,j,k=0;
    sieve();
    s(n);
    if(n==1)
        cout<<"0\n";
    else
    {
        int c=0;
        int val;
        for(i=0;np[i]<=n;i++)
        {   val=np[i];
            ans[k]=np[i];
            k++;
           // if(n%val==0)
            {
                for(j=0;val<=n;j++)
                {
                    val=val*np[i];
                   if(val<=n)
                    {
                       // cout<<val<<" ";
                        ans[k]=val;
                        k++;
                        c++;
                    }
                    else
                        break;
                }
            }
            c++;
        }
        cout<<c<<endl;
        for(i=0;i<k;i++)
        {
            cout<<ans[i]<<" ";
        }
    }
    return 0;
}
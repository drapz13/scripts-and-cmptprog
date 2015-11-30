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

int a[10];
int main()
{
    int n,i=0;

    cin>>n;
    vector<int>v;
    int j=0;
    int x=n;
    while(n)
    {
        a[j]=n%10;
        n=n/10;
        j++;
    }
    int k,f=0,l;
    while(1)
    {
        l=0;
        f=0;
        for(i=j-1;i>=0;i--)
        {
            if(a[i]>=1)
            {
                a[i]=a[i]-1;
                l=l*10+1;
            }
            else
                l=l*10;
        }
        if(l!=0)
        {
            v.push_back(l);
            f=1;
        }
        if(f==0)
            break;
    }

    //int f;
    cout<<v.size()<<endl;
    for(auto f=v.begin();f!=v.end();f++)
    {
        cout<<*f<<" ";
    }
    return 0;
}
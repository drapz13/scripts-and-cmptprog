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
int a[105];
int b[1001];
string s;
int main()
{
    int z;
    int x,n,i,j;
    cin>>s;
    x=s.length();
    f(i,x)
    {
        a[i]=s[i]-'0';
    }
   j=0;
    b[j]=0;
    while(b[j]<1000)
    {
        b[j+1]=b[j]+8;
        j++;
    }
    n=j;
    int k,f;
    for(k=0;k<n;k++)
    {
        f=0;
        int s=b[k];
    for(i=x-1;i>=0;i--)
    {
        if(a[i]==0&&s==0)
        {
            z=b[k];
            f=1;
            break;
        }
          if(a[i]==s%10)
          {
              s=s/10;
              if(s==0)
              {
                  f=1;
                  z=b[k];
                  break;
              }
          }
    }
    if(f==1)
        break;
    }
    if(f==1)
    {cout<<"YES\n";
    cout<<z;}
    else
        cout<<"NO";
    return 0;
}
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
int f[1000009],b[1000009];
int z[1000009];
int ans[100009];
map<int,int>asd;
int main()
{
    int n,m,i,j,g=0,h=0;
    cin>>n>>m;
    f(i,n)
    {
        cin>>f[i];
        ans[f[i]]=i+1;
        z[f[i]]++;
        asd[f[i]]=1;
    }
    f(i,m)
    {
        cin>>b[i];

        z[b[i]]--;
        if(z[b[i]]>0)
            g=1;
    }
    f(i,m)
    {
        if(asd[b[i]]==0&&z[b[i]]<0)
        {
            h=1;
            break;
        }
        else if(z[b[i]]>0)
        {
            g=1;
        }
    }
    if(h==1)
        cout<<"Impossible";
    else if(g==1)
            cout<<"Ambiguity";
    else
    {
            cout<<"Possible\n";
            f(i,m)
            {
                cout<<ans[b[i]]<<" ";
            }
    }
    return 0;
}
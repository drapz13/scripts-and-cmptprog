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
int mini[101],maxi[101];
int main()
{
    int n,s,m,i,j,k,cnt=0;
    cin>>n>>s;
    int a,b;
    if(n==1&&s==0)
        cout<<"0 0";
    else
        {int summin=1,summax=1;
        mini[n-1]=1;
        int f=0;
        for(i=0;i<n;i++)
        {
                int j=i;
                if(summin==s)
                    {   f=1;
                        break;}
                while(mini[j]!=9)
                {
                    summin+=1;
                    mini[j]+=1;
                    if(summin==s)
                    {   f=1;
                        break;}
                }
            if(f==1)
                break;
        }
        if(f==1)
        for(i=n-1;i>=0;i--)
            cout<<mini[i];
            else
                cout<<"-1";
        cout<<" ";
            f=0;
            maxi[n-1]=1;
        for(i=n-1;i>=0;i--)
        {
                int j=i;
                if(summax==s)
                    {   f=1;
                        break;}
                while(maxi[j]!=9)
                {
                    summax+=1;
                    maxi[j]+=1;
                    if(summax==s)
                    {   f=1;
                        break;}
                }
            if(f==1)
                break;
        }

        if(f==1)
        for(i=n-1;i>=0;i--)
            cout<<maxi[i];
            else
                cout<<"-1";
        }
    return 0;
}
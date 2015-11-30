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

LL a[100009];
LL b[100009];
queue<int>q;
int z[100009];
multimap<long long int,int>asd;
int main()
{
    int n,i,j;
    cin>>n;
    f(i,n)
    {
       q.push(i);
    }
    f(i,n)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b,b+n);
    f(i,n)
    {
        asd.insert ( std::pair<long long int,int>(b[i],i) );
    }
    //cout<<"aaa";
    int grp=0,max_index=-1;
    f(i,n)
    {
        multimap<long long int,int>:: iterator it=asd.find(a[i]);
        int index=it->second;
        asd.erase(it);
        if(max_index<index)
            max_index=index;
        z[index]=1;
        while(!q.empty()&&z[q.front()]==1)
        {
            q.pop();
        }
        int top=q.front();
        if(!q.empty()&&top>=max_index)
        {
            grp++;
        }
    }
    cout<<grp+1;
    return 0;
}
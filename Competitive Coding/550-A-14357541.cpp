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
string s1;
vector<int>v1,v2;
int main()
{
    int i;
    while(cin>>s1)
    {
    int x=s1.length();
    for(i=0;i<x;i++)
    {
        if(i!=x-1&&s1[i]=='A'&&s1[i+1]=='B')
        {
            v1.push_back(i);
        }
    }
    for(i=0;i<x;i++)
    {
        if(i!=x-1&&s1[i+1]=='A'&&s1[i]=='B')
        {
            v2.push_back(i);
        }
    }
    vector<int>:: iterator it1,it2,it3;
    it1=v1.begin();
    it2=v2.begin();
    if(v1.size()>=2&&v2.size()>=2)
    {
        cout<<"YES";
    }
    else if(v1.size()==0||v2.size()==0)
    {
        cout<<"NO";
    }
    else if(v1.size()==1&&v2.size()==1)
    {
        if(abs(*it1-*it2)>1)
        {
            cout<<"YES";
        }
        else
            cout<<"NO";
    }
    else
    {
        if(v1.size()==2)
        {
            it3=it1;
            it3++;
            if(abs(*it1-*it2)>1||abs(*it3-*it2)>1)
                cout<<"YES";
            else
                cout<<"NO";
        }
        else
        {
            it3=it2;
            it3++;
            if(abs(*it1-*it3)>1||abs(*it1-*it2)>1)
                cout<<"YES";
            else
                cout<<"NO";
        }
    }}
    return 0;
}
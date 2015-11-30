#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(0);
#define __ int t;cin>>t;while(t--)
#define endl '\n'

using namespace std;
template <typename T>
T modpow(T base, T exp, T modulus) {
  base %= modulus;
  T result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}

struct pplli
{
    int a1;
    int a2;
    long long a3;
    long long a4;
};
bool op1(pplli a,pplli b)
{
    return a.a1<a.a2;
}
bool op2(pplli a,pplli b)
{
    return a.a3<a.a3;
}

int foo(pplli* a,pair<long long,long long>* p2,int n,int m)
{
    int l=0,r=0;
    int res=0;
    while(l<m && r<n)
    {
        if((a[r].a3<=p2[l].first) && (p2[l].first<=a[l].a4))
        {
            a[l].a2 = p2[l].second;
            l++;r++;
            res++;
        }
        else
        {
            l++;
        }
    }
    return res;
}

pair<long long,long long> p1[200005];
pair<long long,long long> p2[200005];
pplli p3a[200005];
int main()
{
    _        ///  FAST I/O
    // __       ///  T TEST CASES
    {
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            long long a,b;
            cin>>a>>b;
            p1[i]=make_pair(a,b);
        }
        sort(p1,p1+n);
        for(int i=0;i<m;i++)
        {
            long long a;
            cin>>a;
            p2[i]=make_pair(a,i);
        }
        sort(p2,p2+m);
        for(int i=0;i<n-1;i++)
        {
            p3a[i].a3=p1[i+1].first-p1[i].second;
            p3a[i].a4=p1[i+1].second-p1[i].first+1;
            p3a[i].a1=i;
        }
        sort(p3a,p3a+n-1,op2);
        int res=foo(p3a,p2,n,m);
        sort(p3a,p3a+n-1,op1);
        if(res!=n-1) cout<<"No\n";
        else
        {
            cout<<"Yes\n";
            for(int i=0;i<n-1;i++)
            cout<<p3a[(n-2+i)%(n-1)].a2+1<<" ";
        }
    }
    return 0;
}

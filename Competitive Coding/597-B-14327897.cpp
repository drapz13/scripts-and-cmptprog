#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define _ ios_base::sync_with_stdio(false);cin.tie(0);
#define __ int t;cin>>t;while(t--)
#define endl '\n'
#define ispow2(n) (n&&(!(n&(n-1))))      ///check if its perfect power of 2
using namespace std;
template <typename T>
T modpow(T base, T exp) {
  /// base %= modulus;
  T result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base); ///  % modulus;
    base = (base * base); ///  % modulus;
    exp >>= 1;
  }
  return result;
}

pair<int,int> p[500005];

bool comp(const pair<int,int> &p1,const pair<int,int> &p2)
{
    return p1.second<p2.second;
}
int main()
{
    _        ///  FAST I/O
    // __       ///  T TEST CASES
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int l,r;
            cin>>l>>r;
            p[i]=mp(l,r);
        }
        sort(p,p+n,comp);
        int ct=1;
        int curr=p[0].second;
        for(int i=1;i<n;i++)
        {
            if(p[i].first>curr)
            {
                ct++;
                curr=p[i].second;
            }
        }
        cout<<ct<<endl;
    }
    return 0;
}
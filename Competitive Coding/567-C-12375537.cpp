#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
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
typedef long long LL;
map<LL,LL> m;
map<LL,LL> m1;
LL a[200005];
int main()
{
    _        ///  FAST I/O
    // __       ///  T TEST CASES
    {
        m.clear();
        m1.clear();
        int n,k;
        cin>>n>>k;
        LL ct=0LL;
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=n-1;i>=0;i--)
        {
            if(m1.find(a[i]*k) != m1.end())
            {
                ct+=m1[a[i]*k];
            }
            if(m.find(a[i]*k)!=m.end())
            {
                m1[a[i]]+=m[a[i]*k];
            }
            m[a[i]]++;
        }
        cout<<ct<<endl;
    }
    return 0;
}
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

map< pair< pair<string,string>, string > , int> v1,v2;
int main()
{
    _        ///  FAST I/O
    // __       ///  T TEST CASES
    {
        int n;
        cin>>n;
        string a,b,c,d;
        for(int i=0;i<n;i++)
        {
            cin>>a>>b>>c>>d;
            if(d=="R") v1[mp(mp(a,b),c)]+=1;
            if(d=="L") v2[mp(mp(a,b),c)]+=1;
        }
        int ct=0;
        /*for(auto i=v1.begin();i!=v1.end();++i)
        {
            cout<<i->first.first.first<<" "<<i->first.first.second<<" "<<i->first.second<<endl;
        }*/
        for(auto i=v1.begin();i!=v1.end();++i)
        {
            if(v2.find(i->first)!=v2.end()) ct+=min(v2.find(i->first)->second,i->second);
        }
        cout<<ct<<endl;
    }
    return 0;
}

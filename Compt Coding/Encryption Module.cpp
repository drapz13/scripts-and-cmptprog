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

map<int,int> m1;
int main()
{
    _        ///  FAST I/O
    __       ///  T TEST CASES
    {
        m1.clear();
        string s1,s2;
        cin>>s1>>s2;
        for(int i=0;i<s1.length();i++)
        {
            //cout<<100+s1[i]-s2[i]<<endl;
            if((s1[i]-s2[i]) <0) m1[s2[i]-s1[i]-26]++,m1[s2[i]-s1[i]]++;
            else m1[s2[i]-s1[i]]++,m1[26+s2[i]-s1[i]]++;
        }
        //for(int i=0;i<101;i++) cout<<ct[i]<<endl;
        int maxi=0;
        for(auto i=m1.begin();i!=m1.end();++i)
        {
            maxi=max(maxi,i->second);
        }
        cout<<s1.length()-maxi<<endl;
    }
    return 0;
}

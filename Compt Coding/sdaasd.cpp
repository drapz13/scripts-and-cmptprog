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


int main()
{
    _        ///  FAST I/O
    //__       ///  T TEST CASES
    {
        int l;
        cin>>l;
        string s;
        cin>>s;
        long long ct=0,ct1=0,ctt=0;
        for(int i=0;i<l;i++)
        {
            ct++;
            ctt++;
            ct1=0;
            while(s[i]=='v'||s[i]=='w')
            {
                if(s[i]=='v') ct1++;
                else ct1+=2;
                i++;
            }
            if(ct1) i--;
            ct+=max(0LL,ct1-1);
            ctt+=max(0LL,(long long)ceil(ct1/2.0) -1);
            //cout<<ct<<" "<<ct1<<" "<<i<<" "<<endl;
        }
        cout<<ctt<<" "<<ct<<endl;
    }
    return 0;
}

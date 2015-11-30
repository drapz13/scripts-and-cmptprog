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

string s1;
int f=-1;
bool check(string s,int l,int r)
{
    //cout<<l<<" "<<r<<endl;
    if((l==r || r==l+1) && s[l]==s[r]) return true;
    if(s[l]==s[r])
    {
        if(check(s,l+1,r-1)) return true;
    }
    else if(s[l+1]==s[r] && check(s,l+1,r))
    {
        f=l;
    }
    else if(s[l]==s[r-1] && check(s,l,r-1))
    {
        f=r;
    }
    if(f!=-1) return true;
    return false;
}

int main()
{
    _        ///  FAST I/O
    __       ///  T TEST CASES
    {
        f=-1;
        s1.clear();
        cin>>s1;
        check(s1,0,s1.length()-1);
        cout<<f<<endl;
    }
    return 0;
}

#include <bits/stdc++.h>
#include <memory>
#define pb push_back
#define mp make_pair
#define _ ios_base::sync_with_stdio(false);cin.tie(0);
#define __ int t;cin>>t;while(t--)
#define endl '\n'
#define ispow2(n) (n&&(!(n&(n-1))))      ///check if its perfect power of 2
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

string tostr(int i)
{
    string s="";
    if(i==0) s+='0';
    while(i)
    {
        s+=(i%10+'0');
        i/=10;
    }
    reverse(s.begin(),s.end());
    //cout<<s<<"k";
    return s;
}
bool foo(string a,string b)
{
    int k=0;
    //cout<<a;
    for(int i=0;i<b.length();i++)
    {
        if(a[k]==b[i]) k++;
        if(k==a.length()) return true;
    }
    return false;
}
int main()
{
    _        ///  FAST I/O
    // __       ///  T TEST CASES
    {
        string s;
        cin>>s;
        int f=0;
        auto ans=0;
        for(int i=0;i<1000;i+=8)
        {
            if(foo(tostr(i),s))
            {
                f=1;
                ans=i;
                break;
            }
        }
        if(f) cout<<"Yes\n"<<ans<<endl;
        else cout<<"No\n";
    }
    return 0;
}
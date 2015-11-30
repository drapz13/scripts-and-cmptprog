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

template <typename T>
T pow(T base, T exp) {
  T result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base);
    base = (base * base);
    exp >>= 1;
  }
  return result;
}

bool eq(string s1,string s2)
{
    //cout<<s1<<" "<<s2<<endl;
    if(s1==s2) return true;
    int l1=s1.length();
    int l2=s2.length();
    if(l1%2 || l2%2) return false;
    if (eq(s1.substr(0,l1/2),s2.substr(l2/2,l2/2))&&eq(s1.substr(l1/2,l1/2),s2.substr(0,l2/2))&&l1>0&&l2>0) return true;
    if (eq(s1.substr(0,l1/2),s2.substr(0,l2/2))&&eq(s1.substr(l1/2,l1/2),s2.substr(l2/2,l2/2))&&l1>0&&l2>0) return true;
    return false;
}
int main()
{
    //_        ///  FAST I/O
    // __       ///  T TEST CASES
    {
        string a,b;
        cin>>a>>b;
        if(eq(a,b)) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
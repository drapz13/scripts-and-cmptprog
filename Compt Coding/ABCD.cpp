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


int main()
{
    _        ///  FAST I/O
    __       ///  T TEST CASES
    {
        int n;
        cin>>n;
        string s,s1="";
        cin>>s;
        int l=s.length();
        cout<<l;
        for(int i=0;i<l;i+=2)
        {
            int a[4];
            memset(a,0,sizeof a);
            for(int j=i;j<i+2;j++)
                a[s[j]-'A']++;

            for(int j=0;j<4;j++)
            {
                if(a[j]==0) s1+=(char)(65+j);
            }
        }
        cout<<s1;
    }
    return 0;
}

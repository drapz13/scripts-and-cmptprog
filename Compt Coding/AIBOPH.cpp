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
int dp[6101][6101];
int min_ins(string s, int l)
{
    int j,h;
    memset(dp,0,sizeof(dp));
    for(int gap=1;gap<l;gap++)
    {
        for(j=0,h=gap;h<l;j++,h++)
        {
            dp[j][h]=(s[j]==s[h])?dp[j+1][h-1] : (min(dp[j][h-1],dp[j+1][h]) +1);
        }
    }
    return dp[0][l-1];
}

int main()
{
    _        ///  FAST I/O
    __       ///  T TEST CASES
    {
        string s;
        cin>>s;
        int l=s.length();
        int ans=min_ins(s,l);
        cout<<ans<<endl;
    }
    return 0;
}

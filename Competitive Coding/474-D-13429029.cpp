#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define _ ios_base::sync_with_stdio(false);cin.tie(0);
#define __ int t;cin>>t;while(t--)
#define endl '\n'
#define MOD 1000000007
#define ispow2(n) (n&&(!(n&(n-1))))      ///check if its perfect power of 2
using namespace std;
template <typename T>
T MODpow(T base, T exp) {
  /// base %= MODulus;
  T result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base); ///  % MODulus;
    base = (base * base); ///  % MODulus;
    exp >>= 1;
  }
  return result;
}

int dp[100005];
int cums[100005];
int main()
{
    int t,k;
    cin>>t>>k;
    int n=100000;
    dp[0]=1;
    for(int i=1;i<=n;i++) dp[i]=(dp[i-1]+dp[i-k])%MOD;
    for(int i=1;i<=n;i++) cums[i]=(cums[i-1]+dp[i])%MOD;
    while (t--)
    {
        int a,b;
        cin>>a>>b;
        int ans=(cums[b]-cums[a-1])%MOD;
        while(ans<0) ans+=MOD;
        cout<<ans<<endl;
    }
    return 0;
}
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
#define mod 1000000007
int n,K,sum;
long long int dp[1001][1001][51];
int a[1001];
void solve(int n,int sum,int K)
{
    for(int i=0;i<=n;i++)
        for(int j=0;j<=sum;j++)
            for(int k=0;k<=K;k++)
                dp[i][j][k]=(dp[i][j][k-1]+dp[i][j-a[i]][k-1])%mod;
}

int main()
{
    _        ///  FAST I/O
    // __       ///  T TEST CASES
    {
        cin>>n>>K;
        int l;
        for(int i=0;i<n;i++) a[i]=i;
        solve(n,n,K);
        cout<<dp[n][n][K]%mod<<endl;
    }
    return 0;
}

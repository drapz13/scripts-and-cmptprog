#include <bits/stdc++.h>
#define pb push_back
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
int dp[201][201];
void pre()
{
    for(int i=0;i<201;i++) dp[0][i]=1;
    for(int i=1;i<201;i++) dp[i][0]=0;
    for(int i=1;i<201;i++)
    {
        for(int j=0;j<i;j++)
        {
            dp[i][j]=dp[i-j][j]+dp[i][j-1];
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    _        ///  FAST I/O
    pre();
    __       ///  T TEST CASES
    {
        int n,k;
        cin>>n>>k;
        cout<<dp[n][k]<<endl;
    }
    return 0;
}

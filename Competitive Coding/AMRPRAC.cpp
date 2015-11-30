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

int x[100005];
int c[100005];
int dp[100005];

int main()
{
    _        ///  FAST I/O
    __       ///  T TEST CASES
    {
        int n,l,d;
        memset(x,0,sizeof x);
        memset(c,0,sizeof c);
        memset(dp,-1,sizeof dp);
        cin>>n>>l>>d;
        for(int i=1;i<n+1;i++)
        {
            cin>>x[i]>>c[i];
        }
        x[n+1]=l;dp[0]=0;
        for(int i=1;i<n+2;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(x[i]-x[j]>d) break ;
                else if(j!=i-1) dp[i]=min(dp[i],dp[j]+c[i]);
                else dp[i]=dp[j]+c[i];
            }
        }
        int ans=dp[n+1];
        if(ans==-1) cout<<"NO\n";
        else cout<<"YES "<<ans<<endl;
    }
    return 0;
}

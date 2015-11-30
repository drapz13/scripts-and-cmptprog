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

bool chk[1000005];
int a[505];
int main()
{
    _        ///  FAST I/O
    memset(chk,false,sizeof chk);
    for(int i=1;i*i*i<1000000;i++)
    {
        chk[i*i*i]=true;
    }
    __       ///  T TEST CASES
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i];
        int s=0,p=0;
        for(int i=1;i<n-1;i++)
        {
            for(int j=0;j<i;j++)
            {
                for(int k=i+1;k<n;k++)
                {
                    s=a[i]+a[j]+a[k];
                    //cout<<s<<endl;
                    if(chk[s]) p++;
                }
            }
        }
        //cout<<p;
        double ans=p/(n*(n-1)*(n-2)/6.0)/1.0;
        cout<<fixed<<setprecision(9)<<ans<<endl;
    }
    return 0;
}

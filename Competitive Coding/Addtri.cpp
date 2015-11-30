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

bool a[5000001];
int main()
{
    _        ///  FAST I/O
    memset(a,false,sizeof a);
    for(int i=1;i<=2236;i++)
    {
        for(int j=i+1;j<=2236;j++)
        {
            for(int k=1;k<=2500000;k++)
            {
                int xx=modpow(i,2)+modpow(j,2);
                if(k*xx>5000000) continue;
                a[xx*k]=true;
            }
        }
    }
    __       ///  T TEST CASES
    {
        int n;
        cin>>n;
        if(a[n]) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}

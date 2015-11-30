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

int a[3005];
int b[3005];
int main()
{
    _        ///  FAST I/O
    // __       ///  T TEST CASES
    {
        int n,m;
        cin>>n>>m;
        string s;
        cin>>s;
        int l=s.length();
        for(int i=0;i<l;i++)
        {
            if(s[i]=='G')
            {
                a[i]=1;
            }
            else
            {
                a[i]=-1;
            }
        }
        a[l]=0;
        b[n-1]=0;
        for(int i=n-2;i>=0;i--)
        {
            if(a[i]==-1)
            {
                b[i]=b[i+1]-1;
            }
            else
            {
                b[i]=b[i+1]+1;
            }
        }
        for(int i=0;i<n;i++) cout<<b[i]<<" ";
    }
    return 0;
}

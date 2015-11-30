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

int a[1005];
int main()
{
    _        ///  FAST I/O
    // __       ///  T TEST CASES
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int x=n-a[0];
        int f=0;
        for(int i=0;i<n;i++)
        {
            if(i%2)
            {
                a[i]+=(n-x);
                a[i]%=n;
            }
            else
            {
                a[i]+=x;
                a[i]%=n;
            }
            if(a[i]!=i) f=1;
        }
        if(f) cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
}

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
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

long double p[15][10005];
long double a[10005];
int main()
{
    _        ///  FAST I/O
    __       ///  T TEST CASES
    {
        int n,m;
        cin>>n>>m;
        long double s=0;
        for(int i=0;i<n;i++) a[i]=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>p[i][j];
                a[i]=a[i]*p[i][j];
            }
            s+=a[i];
        }
        if(s==0) cout<<fixed<<setprecision(6)<<a[0]<<endl;
        else cout<<fixed<<setprecision(6)<<a[0]/s<<endl;
    }
    return 0;
}

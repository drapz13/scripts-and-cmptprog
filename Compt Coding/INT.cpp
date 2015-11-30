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
long long n,a[100005];

int main()
{
    _        ///  FAST I/O
    __       ///  T TEST CASES
    {
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i];
        long long maxi=0LL;
        int r=n-1,l=0;
        for(int i=0;i<r-1;i++)
        {
            if(a[i]<=a[i-1]&&i!=0) continue;
            l=i;
            for(int j=n-1;j>l+1;j--)
            {
                if(a[j]<=a[j+1]&&j!=n-1) continue;
                r=j;
                maxi=max(maxi,(j-i-1)*min(a[i],a[j]));
            }
        }
        cout<<maxi<<endl;
    }
    return 0;
}

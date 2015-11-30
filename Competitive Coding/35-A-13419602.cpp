/** drapz13 **/
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

int a[4];
int main()
{
    _        ///  FAST I/O
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    // __       ///  T TEST CASES
    {
        int x,xx;
        cin>>x;
        a[x]=1;
        cin>>x>>xx;
        swap(a[x],a[xx]);
        cin>>x>>xx;
        swap(a[x],a[xx]);
        cin>>x>>xx;
        swap(a[x],a[xx]);
        if(a[1]) cout<<1<<endl;
        else if(a[2]) cout<<2<<endl;
        else cout<<3<<endl;
    }
    return 0;
}
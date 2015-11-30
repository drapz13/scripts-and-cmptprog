#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define _ ios_base::sync_with_stdio(false);cin.tie(0);
#define __ int t;cin>>t;while(t--)
#define endl '\n'
#define ispow2(n) (n&&(!(n&(n-1))))      ///check if its perfect power of 2
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
int a[105];
bool subsum(int n,int s)
{
    if(s==0&&n!=0) return true;
    if(s!=0&&n==0) return false;
    if(a[n-1]>s) return subsum(n-1,s);
    return subsum(n-1,s)||subsum(n-1,s-a[n-1]);
}
map<int,int> m;
int main()
{
    _        ///  FAST I/O
    // __       ///  T TEST CASES
    {
        m.clear();
        int n;
        cin>>n;
        int s=0;
        for(int i=0;i<n;i++) cin>>a[i],s+=a[i],m[a[i]]++;
        s/=100;
        if(s%2) cout<<"NO\n";
        else
        {
            s/=2;
            int f=0;
            for(int i=0;i<=m[100];i++)
            {
                if((s-i)%2==0 && (s-i)/2 <=m[200])
                {
                    f=1;
                    break;
                }
            }
            if(f) cout<<"YES";
            else cout<<"NO\n";
        }
    }
    return 0;
}
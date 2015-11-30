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
int a[1000005];
bool foo(int n,long long int sum)
{
    int l,r;
    for (int i = 0; i < n - 2; i++)
    {
        l = i + 1;
        r = n-1;
        while (l < r)
        {
            if( a[i] + a[l] + a[r] == sum)
            {
                cout<<"True";
                return true;
            }
            else if(a[i] + a[l] + a[r] <sum) l++;
            else r--;
        }
    }

    cout<<"False";
    return false;
}
int main()
{
    _        ///  FAST I/O
    //__       ///  T TEST CASES
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i];
        sort(a,a+n);
        long long int sum;
        cin>>sum;
        foo(n,sum);
    }
    return 0;
}

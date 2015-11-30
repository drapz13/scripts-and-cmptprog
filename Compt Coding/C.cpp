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

int a[100005];
int main()
{
    _        ///  FAST I/O
    // __       ///  T TEST CASES
    {
        int n,k;
        cin>>n>>k;
        long long c=-1;
        int f;
        while(k--)
        {
            int m;
            cin>>m;
            for(int i=0;i<m;i++) cin>>a[i];
            if(a[0]==1)
            {
                f=-1;
                while(a[f+1]==f+2 && f!=m-1)
                    f++;
                m-=f;
            }
            c+=2*m-1;
        }
        cout<<c<<endl;
    }
    return 0;
}

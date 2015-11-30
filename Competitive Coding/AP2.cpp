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

int main()
{
    _        ///  FAST I/O
    __       ///  T TEST CASES
    {
        long long int x,y,z;
        cin>>x>>y>>z;
        long long int n=(2*z)/(x+y);
        if(n!=5)
        {
            long long d=(y-x)/(n-5),a=x-(2*d);
            cout<<n<<endl;
            for(long long int i=0;i<n;i++)
            {
                cout<<a<<" ";
                a+=d;
            }
            cout<<endl;
        }
        else
        {
            cout<<5<<endl;
            for(int i=0;i<5;i++)
                cout<<x-2+i<<" ";
            cout<<endl;
        }

    }
    return 0;
}

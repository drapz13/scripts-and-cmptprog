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


int main()
{
    _        ///  FAST I/O
    // __       ///  T TEST CASES
    {
        int a1,b1;
        int a2,b2;
        int a3,b3;
        cin>>a1>>b1;
        cin>>a2>>b2;
        cin>>a3>>b3;
        if(a1>b1) swap(a1,b1);
        if(a1*b1<(a2*b2+a3*b3))
        {
            cout<<"NO\n";
            return 0;
        }

        if(min((a2+b3), max(b2,a3)) <= a1 && max((a2+b3), max(b2,a3)) <= b1)
        {
            cout<<"YES\n";
            return 0;
        }
        if(min((a2+a3), max(b2,b3)) <= a1 && max((a2+a3), max(b2,b3)) <= b1)
        {
            cout<<"YES\n";
            return 0;
        }
        if(min((b2+a3), max(a2,b3)) <= a1 && max((b2+a3), max(a2,b3)) <= b1)
        {
            cout<<"YES\n";
            return 0;
        }
        if(min((b2+b3), max(a2,a3)) <= a1 && max((b2+b3), max(a2,a3)) <= b1)
        {
            cout<<"YES\n";
            return 0;
        }
        cout<<"NO\n";
    }
    return 0;
}
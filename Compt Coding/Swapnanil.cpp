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

int st=-1,en=-1;
int main()
{
    _        ///  FAST I/O
    // __       ///  T TEST CASES
    {
        string s;
        cin>>s;
        if(s.length()<2) st=en=0;
        else
        {
            int i=0;
            while(i<s.length())
            {
                if(st==-1&&s[i]=='a')
                {
                    i++;
                }
                if(st==-1)
                {
                    st=i;
                    break;
                }
            }
            int maxi=0;
            while(i<s.length())
            {
                while(i<s.length() && s[i]=='b')
                {
                    i++;
                }
                int ct=0;
                while(i<s.length()&&s[i]=='a')
                {
                    i++;
                    ct++;
                }
                if(maxi<=ct)
                {
                    maxi=ct;
                    en=i-1;
                }
            }
        }
        cout<<st<<" "<<en<<endl;
        st=en=-1;
    }
    return 0;
}

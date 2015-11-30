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

int a[100005];
int b[100005];
int cf[100005];
 stack <int> st;
int main()
{
    _        ///  FAST I/O
     __       ///  T TEST CASES
    {
        int f=0;
        string s;
        cin>>s;

        int l=s.length();
        for(int i=0;i<l&&!f;i++)
        {
           if(s[i]=='(')
                st.push(1);
           else if(s[i]=='[')
                st.push(2);
           else if(s[i]==')')
           {
               if(st.top()!=1)
                f=1;
               st.pop();
           }
           else if(s[i]==']')
           {
               if(st.top()!=2)
                f=1;
               st.pop();
           }
        }
        if(f)
            cout<<"No\n";
        else
            cout<<"Yes\n";
        while(!st.empty())
            st.pop();
    }
    return 0;
}

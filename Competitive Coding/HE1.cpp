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

int b[1000005];
int n;
string s;

void kmpPre()
{
    int j = b[0] = -1;

    for(int i = 0 ; i < n; )
    {
        while(j >= 0 && s[i] != s[j])
            j = b[j];
        j++;
        i++;
        b[i] = j;
    }
}

int main()
{
    char c[1000005];
    int t;
    cin>>t;
    while(t--)
    {
        cin>>c;
        s = c;
        n = s.size();
        kmpPre();
        int m = s.size()- b[s.size() - 1] - 1;

        if((s.size() ) %m != 0)
            cout<<"1"<<endl;
        else
        {
            bool f = true;
            int j = 0;
            for(int i = m ; i < n ; i++)
            {
                if(s[i] != s[j])
                {
                    f = false;
                    break;
                }
                j++;
                if(j == m)
                    j = 0;
            }
            if(f)
            {
                cout<<s.size()/m<<endl;
            }
            else
            {
                cout<<"1"<<endl;
            }
        }
    }
    return 0;
}

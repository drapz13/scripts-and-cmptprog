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

int lcs1[100005];
int lcs2[100005];
set<int> s;
set<int>::iterator it,it1;
int main()
{
    _        ///  FAST I/O
    __       ///  T TEST CASES
    {
        int n;
        s.clear();
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            lcs1[x]=i;
        }
        for(int i=0;i<4;i++) cout<<lcs1[i]<<" ";
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            lcs2[i]=lcs1[x];
        }
        cout<<endl;
        for(int i=0;i<4;i++) cout<<lcs2[i]<<" ";

        cout<<endl<<endl;
        for(int i=0;i<n;i++)
        {
            s.insert(lcs2[i]);
            it=s.find(lcs2[i]);
            ++it;
            if(it!=s.end()) s.erase(it);
            for(it1=s.begin();it1!=s.end();++it1)
                cout<<*it1<<" ";
            cout<<endl;
        }
        cout<<s.size()<<endl;
    }
    return 0;
}

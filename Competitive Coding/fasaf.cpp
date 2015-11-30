#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define _ ios_base::sync_with_stdio(false);cin.tie(0);
#define __ int t;cin>>t;while(t--)
#define endl '\n'

using namespace std;
template <typename T>
T modpow(T base, T exp) {
  //base %= modulus;
  T result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base);
    base = (base * base);
    exp >>= 1;
  }
  return result;
}
bool foonum(long long num)
{
    if(num&&(!(num&(num-1)))) return true;
    return (!foonum(modpow(2LL,(long long)log2(num)+1LL)-num));
}

int main()
{
    freopen("C:\\Users\\DARPAN\\Desktop\\in.in","r",stdin);
    freopen("C:\\Users\\DARPAN\\Desktop\\out.txt","w",stdout);
    int t1=1;
    _        ///  FAST I/O
    __       ///  T TEST CASES
    {
        long long k;
        cin>>k;
        cout<<"Case #"<<t1++<<": ";
        if(foonum(k)) cout<<"0\n";
        else cout<<"1\n";
    }
    return 0;
}

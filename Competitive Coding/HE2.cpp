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


bool win(long long a, long long b)
{
  if (a == 0) return false;
  if (!win(b % a, a)) return true;
  long long r = (b/a - 1) % (a + 1) + 1;
  return r == a+1 || r % 2 == 0;
}

int main()
{
    freopen("C:\\Users\\DARPAN\\Desktop\\a.txt","r",stdin);
    freopen("C:\\Users\\DARPAN\\Desktop\\ans.txt","w",stdout);
    _        ///  FAST I/O
    __       ///  T TEST CASES
    {
        long long X,Y;
        cin>>X>>Y;
        if(X>Y) swap(X,Y);
        puts(win(X,Y) ? "Abhi" : "Kitty");
    }
  return 0;
}

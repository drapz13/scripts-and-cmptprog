#include <bits/stdc++.h>
#define pb push_back
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
        int n;
        cin>>n;
        char a[n][n];
        int px,py,mx,my;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>a[i][j];
                if(a[i][j]=='m') mx=j,my=i;
                if(a[i][j]=='p') px=j,py=i;
            }
        }
        if(mx<px)
        {
            while(mx!=px)
            {
                cout<<"RIGHT\n";
                mx++;
            }
        }
        else
        {
            while(mx!=px)
            {
                cout<<"LEFT\n";
                mx--;
            }
        }
        if(my<py)
        {
            while(my!=py)
            {
                cout<<"DOWN\n";
                my++;
            }
        }
        else
        {
            while(my!=py)
            {
                cout<<"UP\n";
                my--;
            }
        }
    }
    return 0;
}

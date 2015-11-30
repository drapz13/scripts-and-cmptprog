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

vector<int> v;

void precomp()
{
    bool *primes=new bool[1000005];
    memset(primes,true,sizeof primes);
    for(int i=0;i<10;i++) cout<<i<<" "<<primes[i]<<endl;
    for(int i=2;i<1000005;i++)
    {
        if(primes[i])
        {
            for(int j=i*i;j<1000005;j+=i)
            {
                primes[j]=false;
            }
        }
    }

    for(int i=2;i<1000005;i++)
    {
        if(primes[i]) {cout<<i<<endl;v.push_back(i);}
    }
    delete []primes;
}

int main()
{
    _        ///  FAST I/O

    precomp();
    //__
    {

    }

    return 0;
}

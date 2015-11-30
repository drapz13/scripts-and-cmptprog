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

vector<int> primes;
int prime[1000005];
bool div_sum[1000005];
vector<int> ans;
void pre()
{
    primes.push_back(2);
    memset(prime,true,sizeof prime);
    memset(div_sum,false,sizeof div_sum);
    prime[0]=prime[1]=false;
    for(int i=2;i<1005;i++)
    {
        if(prime[i])
        {
            for(int j=i*i;j<1000005;j+=i)
            {
                prime[j]=false;
            }
        }
    }
    for(int i=3;i<1000005;i+=2)
        if(prime[i]) primes.push_back(i);
    //cout<<primes.size();
    for(int i=0;i<primes.size();i++)
    {
        long long temp=1,x=1;
        while(x<1000005)
        {
            if(prime[x]) div_sum[temp]=true;
            temp*=primes[i];
            x+=temp;
        }
    }
    for(int i=2;i<1000005;i++)
        if(div_sum[i]) ans.push_back(i);
}

int main()
{
    _        ///  FAST I/O
    pre();
    __       ///  T TEST CASES
    {
        int a,b;
        cin>>a>>b;
        cout<<upper_bound(ans.begin(),ans.end(),b)-lower_bound(ans.begin(),ans.end(),a)<<endl;
    }
    return 0;
}

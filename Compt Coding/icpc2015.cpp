#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define _ ios_base::sync_with_stdio(false);cin.tie(0);
#define __ int t;cin>>t;while(t--)
#define endl '\n'
#define ispow2(n) (n&&(!(n&(n-1))))      ///check if its perfect power of 2
using namespace std;
#define MOD 1000000007
template <typename T>
T modpow(T base, T exp) {
  base %= MOD;
  T result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base);
    result%= MOD;
    base = (base * base);
    base%= MOD;
    exp >>= 1;
  }
  return result;
}
map<int,int> m;
map<int,int>::iterator it;
int main()
{
    _        ///  FAST I/O
    __       ///  T TEST CASES
    {
    	long long p=1LL;
    	int n;
    	cin>>n;
    	long long pp=1LL;
    	for(int i=0;i<n;i++)
    	{
    		int x;
    		cin>>x;
    		m[x]++;
    	}
    	for(it=m.begin();it!=m.end();++it)
    	{
    		int cnt=0;
    		for(int i=1;i*(it->first)<=100005;i++)
    		{
    			if(m.find(i*(it->first))!=m.end())
                    cnt+=m[i*(it->first)];
    		}
            int p=modpow(it->first,cnt);
            pp*=p;
            pp%=MOD;
    	}
    	cout<<pp<<endl;
    }

	return 0;
}

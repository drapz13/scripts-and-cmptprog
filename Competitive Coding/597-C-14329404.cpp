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
#define MAXN 100005
#define MAXK 15
long long BITree[15][MAXN];
int a[MAXN];
long long dp[MAXK];

long long ins(int curr,int idx)
{
    long long sum=0LL;
    while(idx > 0)
    {
        sum+=BITree[curr][idx];
        idx-=(idx & -idx);
    }
    return sum;
}

void update(int curr, int idx,long long val)
{
    while(idx<MAXN)
    {
        long long temp=BITree[curr][idx]+val;
        BITree[curr][idx]=temp;
        idx+=(idx & -idx);
    }
}

int main()
{
    _        ///  FAST I/O
    // __       ///  T TEST CASES
    {
        int n,k;
        cin>>n>>k;
        k=k+1;
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<k-1;j++) dp[j]=ins(j,a[i]);
            update(0,a[i]+1,1);
            for(int j=1;j<k;j++) update(j,a[i]+1,dp[j-1]);
        }
        long long cnt=ins(k-1,MAXN-1);
        cout<<cnt<<endl;
    }
    return 0;
}
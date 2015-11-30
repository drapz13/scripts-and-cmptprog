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
int ct=0;
bool vis[100][100];
int a[105][105];
 int n;
map<int,int> m;
void tr(int i,int j)
{
    ct++;
    m[ct]++;
    vis[i][j]=true;
    if(a[i+1][j]<a[i][j]&&!vis[i+1][j]&&i+1<n) tr(i+1,j);
    if(a[i][j+1]<a[i][j]&&!vis[i][j+1]&&j+1<n) tr(i,j+1);
    if(a[i-1][j]<a[i][j]&&!vis[i-1][j]&&i-1>=0) tr(i-1,j);
    if(a[i][j-1]<a[i][j]&&!vis[i][j-1]&&j-1>=0) tr(i,j-1);
}
int main()
{
    _        ///  FAST I/O
    //__       ///  T TEST CASES
    {

        cin>>n;

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>a[i][j];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                ct=0;
                memset(vis,false,sizeof vis);
                tr(i,j);
            }
        }
        long long ans=0;
        for(auto i=m.begin();i!=m.end();++i)
        {
        	ans+=i->second;
        	ans%=1000000007;
        }
        cout<<ans<<endl;
    }
    return 0;
}

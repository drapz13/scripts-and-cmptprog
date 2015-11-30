#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define _ ios_base::sync_with_stdio(false);cin.tie(0);
#define __ int t;cin>>t;while(t--)
#define endl '\n'
#define P pair<int,int>
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

map<string,P> ma;
map<string,P>::iterator it;
int d[35][35];
int main()
{
    _        ///  FAST I/O
    // __       ///  T TEST CASES
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n,m,k,i,j,x,y,f;
    string s,t;
    cin>>n;
    cin>>m;
    cin>>k;
    while(k--)
    {
        cin>>t;
        if(t=="+1")
        {
            cin>>x;
            cin>>y;
            cin>>s;
            f=0;
            for(i=x;i<=n;i++)
            {
                if(i==x)
                    j=y;
                else
                    j=1;
                for(;j<=m;j++)
                {
                    if(!d[i][j])
                    {
                        d[i][j]=1;
                        ma[s]=mp(i,j);
                        f=1;
                        break;
                    }

                }
                      if(f)
                        break;
            }
        }
        else
        {
            cin>>s;
            it=ma.find(s);
            if(it==ma.end())
            {
                cout<<"-1 -1\n";
            }
            else
            {
              P tmp=it->second;
              cout<<tmp.first<<" "<<tmp.second<<endl;
              d[tmp.first][tmp.second]=0;
              ma.erase(it);
            }
        }
    }
    return 0;
}
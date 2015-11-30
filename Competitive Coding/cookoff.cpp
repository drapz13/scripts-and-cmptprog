#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
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
vector<int> v[100005];
int vis[100005];
int pos1[100005];
int chk[100005];
int k1=0;
map<int, vector<int> > m;
void dfs(int s)
{
    if(vis[s]>=0) return;
    vis[s]=k1;
    k1+=1;
    //m[s].pb(k1);
    for(int i=0;i<v[s].size();i++)
    {
        dfs(v[s][i]);
    }
    pos1[s]=k1;
    k1+=1;
}
int k;
int calc()
{
    int f=-1;
    for(int i=0;i<k-1;i++)
    {
        if(!(vis[chk[k-1]]<vis[chk[i]] && pos1[chk[k-1]]>pos1[chk[i]]))
        {
            return 1;
        }
        if(!(vis[chk[i+1]]<vis[chk[i]] && pos1[chk[i+1]]>pos1[chk[i]]))
        {
            f=i+1;
            break;
        }
    }
    if(f==-1) return 2;
    for(int i=f;i<k-1;i++)
    if(!(vis[chk[i+1]]<vis[chk[i]] && pos1[chk[i+1]]>pos1[chk[i]]))
    {
        return 1;
    }
    return 2;
}
bool condn(int a1,int b1)
{
    return pos1[a1]<pos1[b1];
}
int main()
{
    freopen("C:\\Users\\DARPAN\\Desktop\\a.txt","r",stdin);
    _        ///  FAST I/O
    __       ///  T TEST CASES
    {
        int n;
        cin>>n;
        m.clear();
        k1=0;
        int maxi=0;
        for(int i=0;i<n;i++) v[i].clear();


        for(int i=0;i<n-1;i++)
        {
            int x,y;
            cin>>x>>y;
            //maxi=max(maxi,(max(x,y)));
            v[x-1].pb(y-1);
            v[y-1].pb(x-1);
        }
        memset(vis,-1,sizeof vis);
        dfs(0);
        int q;
        cin>>q;
        while(q--)
        {
            cin>>k;
            for(int i=0;i<k;i++)
            {
                cin>>chk[i];
                chk[i]-=1;
            }
            int g=-1;
            sort(chk,chk+k,condn);
            int ans=calc();
            //cout<<ans<<endl;
            if(ans==2) cout<<"Yes\n";
            else cout<<"No\n";
        }
    }
    return 0;
}

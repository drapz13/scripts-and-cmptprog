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

int a[100005];
vector < set<int> > depend;
set<int> temp;
bool vis[100005];
char type[100005];
void dfs(int source,int truth)
{
    temp.insert(source); /// source speaks truth
    if(truth==0) type[source]='A';
    else type[source]='B';
    vis[source]=true;
    int chk=a[source];
    if(a[source]<0) chk=abs(a[source]);
    if(!vis[chk])
    {
        if(truth==0)
        {
            if(a[source]<0) dfs(a[source]*-1,1);
            else dfs(a[source],0);
        }
        else
        {
            if(a[source]<0) dfs(a[source]*-1,0);
            else dfs(a[source],1);
        }
    }
    else
    {
        if(truth==0)
        {
            if(a[source]<0 && type[a[source]]=='B') type[source]='A';
            else if(a[source]<0 && type[a[source]]=='A') type[source]='B';
        }
    }
}
int main()
{
    _        ///  FAST I/O
    // __       ///  T TEST CASES
    {
        memset(a,0,sizeof a);
        memset(vis,false,sizeof vis);
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(int i=1;i<=n;i++)
        {
            temp.clear();
            if(vis[i]==false) dfs(i,0);
            depend.pb(temp);
        }
        for(int i=1;i<=n;i++)
        {
            cout<<type[i];
        }
        cout<<endl;
        int countknight=0,tempcountknight=0;
        for(auto i=depend.begin();i!=depend.end();++i)
        {
            tempcountknight=0;
            for(auto j=(*i).begin();j!=(*i).end();++j)
            {
                cout<<*j<<" ";
                if(type[*j]=='A') tempcountknight++;
            }
            if((tempcountknight<(*i).size()/2&&(*i).size()%2==0) || (tempcountknight<=(*i).size()/2&&(*i).size()%2))
            {
                for(auto j=(*i).begin();j!=(*i).end();++j)
                {
                    cout<<*j<<" ";
                    if(type[*j]=='A') type[*j]='B';
                    else type[*j]='A';
                }
            }
            else if(tempcountknight==(*i).size()/2 && (*i).size()%2==0)
            {
                int flag=0;
                for(auto j=(*i).begin();j!=(*i).end();++j)
                {
                    if(type[*j]=='A'&&flag==0) break;
                    else flag=1;
                    cout<<*j<<" ";
                    if(type[*j]=='A') type[*j]='B';
                    else type[*j]='A';
                }
            }
            cout<<endl;
        }
    }
    return 0;
}

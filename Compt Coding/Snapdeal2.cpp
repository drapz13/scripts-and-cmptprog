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

int pin[21];
int charges[21];
map<int,int> loc_charge; /// pin, price
map<int, vector< pair<int,int> > >shop; /// pin, price:quality
pair<int, pair<int,int> > shop1[51];
int l,r,n;
int cnt=-1;
int k;
map<int,int>dap;
void auro(int i,int price,int qual,int da[1000009],int abhi)
{
    if(abhi>k)
        return;
    if(i==-1)
    {
       // cout<<price<<" "<<qual<<endl;
        if(price>=l&&price<=r&&abhi==k)
        {
           cnt=max(cnt,qual);
        dap[qual]++;
            //cout<<endl<<cnt<<endl;
        }
        return;
    }
    auro(i-1,price,qual,da,abhi);

    if(da[shop1[i].first]==0)
    {
        da[shop1[i].first]++;
     //   cout<<shop1[i].second.first<<" "<<shop1[i].second.second<<endl;
        auro(i-1,price+shop1[i].second.first,qual+shop1[i].second.second,da,abhi+1);
        da[shop1[i].first]=0;
    }
    //cout<<price<<" "<<qual<<endl;
}
int main()
{
    _        ///  FAST I/O
    // __       ///  T TEST CASES
    {
        int m,x,y,z;
//        int l,r;
        int da[100009];
        cin>>m>>n>>k;
        for(int i=0;i<m;i++)
        {
            int x1,y1;
            cin>>x1>>y1;
            loc_charge[x1]=y1;
        }
        for(int i=0;i<n;i++)
        {
            cin>>x>>y>>z;
            shop[x].pb(mp(y+loc_charge[x],z));
        }
        cin>>l>>r;
        if(shop.size()<k)
        {
            cout<<"-1\n";
            return 0;
        }
        int ct=0;
        for(auto i=shop.begin();i!=shop.end();++i)
        {
            for(int j=0;j<i->second.size();++j)
            {
              //  cout<<i->first<<" "<<i->second[j].first<<" "<<i->second[j].second<<endl;
                shop1[ct++]=mp(i->first,mp(i->second[j].first,i->second[j].second));
            }
        }
        //cout<<endl;
        /*for(int i=0;i<ct;i++)
        {
            cout<<shop1[i].first<<" "<<shop1[i].second.first<<" "<<shop1[i].second.second<<endl;
        }*/
        auro(n-1,0,0,da,0);
        if(cnt!=-1)
        cout<<cnt<<" "<<dap[cnt]<<endl;
        else
            cout<<"-1";
    }
    return 0;
}

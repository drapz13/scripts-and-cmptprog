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


vector<string> v1;
vector<int> v2;
int main()
{
    //_        ///  FAST I/O
    __       ///  T TEST CASES
    {
        //cin.ignore();
        string x;
        long long ct=0;
        getline(cin,x);
        long long l=0,r=0;
        //cout<<x<<" "<<x.length()<<"\n";
        for(long long i=0;i<(long long)x.length();i++)
        {
            r=0;
            while(x[i]!=' ')
            {
                r++;
                i++;
                //cout<<r;
            }
            string y=x.substr(l,r);
            if(ct%2==0)
            {
                for(long long k=0;k<(long long)y.length();k++) if(y[k]<97) y[k]-=('Z'-'z');
                //cout<<y<<endl;
                v1.pb(y);
            }
            else
            {
                long long int len=y.length();
                long long int z=0;
                for(long long int k=0;k<len;k++)
                {
                    z+=(y[len-1-k]-'0')*modpow(10LL,k);
                }
                v2.pb(z);
            }
            l=i+1;
            ct++;
        }
        long long step,ct1=0,ct2=0;
        cin>>step;
        for(long long i=0;i<step;i++)
        {
            if(i%2==0&&ct1<(long long)v1.size())
            {
                swap(v1[ct1],v1[min_element(v1.begin()+ct1,v1.end())- v1.begin()]);
                ct1++;
            }
            else if(i%2!=0&&ct2<(long long)v2.size())
            {
                swap(v2[ct2],v2[min_element(v2.begin()+ct2,v2.end())- v2.begin()]);
                ct2++;
            }
            if(ct1>=(long long)v1.size()&&ct2>=(long long)v2.size()) break;
        }
        long long k1=0,k2=0;
        for(long long i=0;i<(long long)(v1.size()+v2.size());i++)
        {
            if(i%2==0) cout<<v1[k1++]<<" ";
            else cout<<v2[k2++]<<" ";
        }
        cout<<endl;
        v1.clear();
        v2.clear();
    }
    return 0;
}

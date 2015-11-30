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

map< pair<int,int> , int > m;
int main()
{
    _        ///  FAST I/O
    // __       ///  T TEST CASES
    {
        m.clear();
        string s;
        cin>>s;
        int x=0,y=0;
        pair<int,int> p;
        p=make_pair(x,y);
        m[p]=1;
        int l=s.length();
        int f=0;
        for(int i=0;i<l;i++)
        {
            if(s[i]=='L') x--;
            else if(s[i]=='R') x++;
            else if(s[i]=='U') y++;
            else if(s[i]=='D') y--;
            p=make_pair(x,y);
            //cout<<x<<" "<<y<<" "<<m[p]<<endl;
            if(m[p]!=0 || (m[make_pair(x,y-1)]!=i+1&&m[make_pair(x,y-1)]!=0) || (m[make_pair(x,y+1)]!=i+1&&m[make_pair(x,y+1)]!=0) || (m[make_pair(x-1,y)]!=i+1&&m[make_pair(x-1,y)]!=0) || (m[make_pair(x+1,y)]!=i+1&&m[make_pair(x+1,y)]!=0))
            {
                f=1;
                cout<<"BUG\n";
                break;
            }
            else m[p]=i+2;
            //cout<<x<<" "<<y<<" "<<m[p]<<endl;
        }
        if(f==0) cout<<"OK\n";
    }
    return 0;
}
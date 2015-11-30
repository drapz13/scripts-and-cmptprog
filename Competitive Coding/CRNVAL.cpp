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


int main()
{
    _        ///  FAST I/O
    __       ///  T TEST CASES
    {
        int n;
        cin>>n;
        int f=0;
        int a[n],b[n];
        memset(b,0,sizeof b);
        int maxi=0,mini=INT_MAX;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]>n-1) f=1;
            maxi=max(maxi,a[i]);
            mini=min(mini,a[i]);
        }
        for(int i=0;i<n;i++)
        {
            if(a[i]==maxi) b[i]=0;
            if(a[i]==mini) b[i]=1;
            if(a[i]!=maxi && a[i]!=mini)
            {
                f=1;
                break;
            }
        }
        if(maxi==mini&maxi==0) cout<<0<<endl;
        else if(f==1) cout<<"-1\n";
        else
        {
            int tot=0;
            for(int i=0;i<n;i++)
                if(b[i]==1) tot++;
            for(int i=0;i<n;i++)
            {
                if(b[i]==1 && a[i]!=tot-1)
                {
                    f=1;break;
                }
                if(b[i]==0 && a[i]!=tot)
                {
                    f=1;break;
                }
            }
            if(f) cout<<"-1\n";
            else cout<<tot<<endl;
        }
    }
    return 0;
}

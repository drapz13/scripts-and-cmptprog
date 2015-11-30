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

int ct[100005];
int main()
{
    _        ///  FAST I/O
    __       ///  T TEST CASES
    {
        int n;
        cin>>n;
        int a[n];
        memset(ct,0,sizeof ct);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            ct[a[i]]++;
        }
        int maxi=*max_element(a,a+n);
        int ctmax=*max_element(ct,ct+maxi+1);
        int ctmaxloc=max_element(ct,ct+maxi+1)-ct;
        //cout<<ctmax<<endl;
        //cout<<ctmaxloc<<endl;
        int loc_max_ct=find(a,a+n,ctmaxloc)-a;
        if(loc_max_ct==0||loc_max_ct==n-1)
        {
            for(int i=1;i<n-1;i++)
            {
                if(ct[a[i]]==ctmax)
                {
                    loc_max_ct=i;
                    break;
                }
            }
        }
        int f=0;
        for(int i=1;;i++)
        {
            if((loc_max_ct-i) <0 || (loc_max_ct+i)>=n) break;
            if(abs(a[loc_max_ct-i]-a[loc_max_ct])==abs(a[loc_max_ct-i]-a[loc_max_ct]))
            {
                f=1;
                break;
            }
        }
        if(f!=1)
        {
            if(find(ct,ct+maxi+1,ctmax-1)-ct != maxi+1)
            {
                int ctmaxloc=find(ct,ct+maxi+1,ctmax-1)-ct;
                loc_max_ct=find(a,a+n,ctmaxloc)-a;
                if(loc_max_ct==0||loc_max_ct==n-1)
                {
                    for(int i=1;i<n-1;i++)
                    {
                        if(ct[a[i]]==ctmax)
                        {
                            loc_max_ct=i;
                            break;
                        }
                    }
                }

                for(int i=1;;i++)
                {
                    if((loc_max_ct-i) <0 || (loc_max_ct+i)>=n) break;
                    if(abs(a[loc_max_ct-i]-a[loc_max_ct])==abs(a[loc_max_ct-i]-a[loc_max_ct]))
                    {
                        f=2;
                        break;
                    }
                }
            }
        }
        if(f==1) cout<<ctmax+2<<endl;
        else if(f==2) cout<<ctmax+1<<endl;
        else cout<<ctmax<<endl;
    }
    return 0;
}

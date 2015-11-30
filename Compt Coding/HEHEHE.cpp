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

int a[100005];
int main()
{
    _        ///  FAST I/O
    __       ///  T TEST CASES
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i];
        int loc_mini=min_element(a,a+n)-a;
        long long s=0LL;
        if(a[loc_mini+1]>a[loc_mini-1])
        {
            for(int i=loc_mini;i>0;i--)
            {
                if(a[i-1]>a[i]) a[i]=a[i-1];
                else a[i-1]=a[i];
                s+=a[i-1];
            }
            for(int i=loc_mini;i<n-1;i++)
            {
                if(a[i+1]>a[i]) a[i]=a[i+1];
                else a[i+1]=a[i];
                s+=a[i+1];
            }
        }
        else
        {
            for(int i=loc_mini;i<n-1;i++)
            {
                if(a[i+1]>a[i]) a[i]=a[i+1];
                else a[i+1]=a[i];
                s+=a[i+1];
            }
            for(int i=loc_mini;i>0;i--)
            {
                if(a[i-1]>a[i]) a[i]=a[i-1];
                else a[i-1]=a[i];
                s+=a[i-1];
            }
        }
        cout<<s<<endl;
    }
    return 0;
}

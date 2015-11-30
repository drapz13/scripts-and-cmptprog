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
template <typename T,typename T1>
T npow(T base, T1 exp) {
  T result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base);
    base = (base * base);
    exp >>= 1;
  }
  return result;
}
vector<long double> r;
int main()
{
    _        ///  FAST I/O
    //__       ///  T TEST CASES
    {
        int t;
        freopen("C:\\Users\\DARPAN\\Desktop\\b.txt","r",stdin);
        cin>>t;
        long double a=0;
        long long n0,r1,r2,r3,r4,p,m,rn=0,b,r11,r22,r33,r44,rd;
        r.pb(0);
        cin>>n0>>p>>m>>b;
        cin>>r1>>r2>>r3>>r4;
        r11=1/(2*r1);
        r22=1/(2*r2);
        rd=fabs(r11-r22)/2;
        double s = 1 / (a.x * a.x + a.y * a.y - r * r);
        ooo = a * s;
        double res = fabs(s) * r;
        return res;
        r.pb(r1);
        r.pb(r2);
        r.pb(r3);
        r.pb(r4);
        while(t--)
        {
            n0=((n0*p)%m)+b;
            for(int i=4;i<n0;i++)
            {
                long double soddy=npow(r[1]*r[2]*r[i],2)/((npow(r[1]*(r[2]+r[i])-r[2]*r[i],2)-4*r[1]*r[2]*r[i]*(r[1]-r[2]-r[i]))*r[i-1]);
                r.pb(soddy);
            }
            a+=r[n0];
        }
        cout<<fixed<<setprecision(6)<<a<<endl;
    }
    return 0;
}

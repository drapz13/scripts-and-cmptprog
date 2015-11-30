#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define _ ios_base::sync_with_stdio(false);cin.tie(0);
#define __ int t;cin>>t;while(t--)
#define endl '\n'
#define pi 3.1415
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
double degree2radians(double a)
{
    return pi*a/180.0;
}

double distance_between(pair<double,double> point1, pair<double,double> point2)
{
    int EARTH_RADIUS = 6371;//in km
    double point1_lat_in_radians  = degree2radians( point1.first );
    double point2_lat_in_radians  = degree2radians( point2.first );
    double point1_long_in_radians  = degree2radians( point1.second );
    double point2_long_in_radians  = degree2radians( point2.second );

    return acos( sin(point1_lat_in_radians ) * sin( point2_lat_in_radians ) +
                 cos( point1_lat_in_radians ) * cos( point2_lat_in_radians ) *
                 cos( point2_long_in_radians - point1_long_in_radians) ) * EARTH_RADIUS;
}
map< pair<double,double> , pair<pair<int,int>,int> > m;
int main()
{
    _        ///  FAST I/O
    // __       ///  T TEST CASES
    {
        int n;
        m.clear();
        cin>>n;
        for(int i=0;i<n;i++)
        {
            double x,y;
            cin>>x>>y;
            m[mp(x,y)].first.first=0;
            m[mp(x,y)].first.second=0;
            m[mp(x,y)].second=0;
        }
        for(auto it=m.begin();it!=m.end();++it)
        {
            for(auto j=it+1;j!=m.end();++j)
            {
                if(distance_between(it.first,j.first)
            }
        }
    }
    return 0;
}

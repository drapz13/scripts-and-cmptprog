#include <iostream>
#include <cmath>

using namespace std;

int main()
{
   long long a,b,c;
      cin>>a>>b>>c;
      long long  d=(ceil((a*1.0)/c));
      long long  e=(ceil((b*1.0)/c));
      cout<<d*e<<endl;
   return 0;
}
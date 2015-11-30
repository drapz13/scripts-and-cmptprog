#include <iostream>
#include <cmath>

using namespace std;

int main()
{
   int n;
   cin>>n;
   int k;
   cin>>k;
   int a[n],d=0;
   for(int i=0;i<n;i++)
   {
       cin>>a[i];
   }
   for(int i=0;i<n;i++)
   {
       if(a[i]>=a[k-1] && a[i]>0) d++;
       else break;
   }
   cout<<d<<endl;


   return 0;
}
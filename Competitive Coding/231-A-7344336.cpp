#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int d=0;
    while(n--)
    {
        int a[3];
        cin>>a[0]>>a[1]>>a[2];
        if(count(a,a+3,1)>=2) d++;
    }
    cout<<d<<endl;
    return 0;
}
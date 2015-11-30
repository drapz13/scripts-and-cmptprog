#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    long long int a,b,c,d;
    long long s=0;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b>>c>>d;
        s+=(c-a+1)*(d-b+1);
    }
    cout<<s<<endl;
    return 0;
}
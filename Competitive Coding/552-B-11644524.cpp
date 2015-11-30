#include <bits/stdc++.h>
using namespace std;

long long lim[]={0,9,99,999,9999,99999,999999,9999999,99999999,999999999};
int main()
{
    int n;
    cin>>n;
    long long ans=0;
    int i=upper_bound(lim,lim+10,n)-lim;
    //cout<<i<<endl;
    if(i==10) i--;
    for(int j=1;j<i;j++)
        ans+=(j)*(lim[j]-lim[j-1]);
    ans+=i*(n-lim[i-1]);
    if(n==1000000000) ans++;
    cout<<ans<<endl;
    return 0;
}
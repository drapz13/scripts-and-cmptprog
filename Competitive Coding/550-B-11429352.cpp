#include <bits/stdc++.h>
using namespace std;

int solve(int *a1,int i,int min1,int max1,int s,int n,int l,int r,int x)
{
    if(i==n) return int(s<=r && s>=l && max1-min1>=x);
    int ans1=solve(a1,i+1,min1,max1,s,n,l,r,x);
    if(min1>=a1[i]) min1=a1[i];
    if(max1<=a1[i]) max1=a1[i];
    int ans2=solve(a1,i+1,min1,max1,s+a1[i],n,l,r,x);
    return ans1+ans2;
}
int maxi=1e9+1;
int a[17];
int main()
{
    int n,l,r,x;
    cin>>n>>l>>r>>x;
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<solve(a,0,maxi,-maxi,0,n,l,r,x)<<endl;
    return 0;
}
#include<bits/stdc++.h>
#include<iostream>
#define mod 1000000007
using namespace std;
int n,k;
int cnt=0;
/*int solve(int i,int j)
{
     if(i==0)
     {
          if(j%k==0)
          {
               cnt+=1;
               return 1;
          }
          return 0;
     }
     if(j%k==0)
     return (solve(i-1,j)+solve(i-1,j+1));
     return (solve(i-1,j+1));

}*/
long long dp[1000009],sum[1000009];
int main()
{
     int t,a,b,i;
     cin>>t;
     cin>>k;
     dp[0]=1;
     for(i=1;i<=100000;i++)
     {
          dp[i]=dp[i-1];
          if(i>=k)
               dp[i]+=dp[i-k];
          dp[i]%=mod;
     }
     sum[0]=0;
     for(i=1;i<=100000;i++)
     {
          sum[i]=sum[i-1]+dp[i];
          sum[i]%=mod;
     }
     while(t--)
     {
          cin>>a>>b;
           if(sum[b]-sum[a-1]<0)
               cout<<mod+sum[b]-sum[a-1]<<endl;
           else
               cout<<sum[b]-sum[a-1]<<endl;
     }
     return 0;
}
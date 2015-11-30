#include<bits/stdc++.h>

using namespace std;

bool dp[1001][1001];

pair<int,int>a[100005];
int main()
{
    int n,m,k,v1,v2,flag=0;
    cin>>n>>m>>k;
    for(int i=0;i<k;i++)
    {
        cin>>a[i].first>>a[i].second;
    }
    int i;
    for(i=0;i<k;i++)
    {
        v1=a[i].first;v2=a[i].second;
        dp[a[i].first][a[i].second]=true;
        if((v1-1)>0 && (v2-1)>0 && dp[v1-1][v2-1]==true && dp[v1-1][v2]==true && dp[v1][v2-1]==true)
        {
            flag=1;
            break;
        }
        if((v1-1)>0 && (v2+1)<=m && dp[v1-1][v2]==true && dp[v1-1][v2+1]==true && dp[v1][v2+1]==true)
        {
            flag=1;
            break;
        }
        if((v1+1)<=n && (v2+1)<=m && dp[v1+1][v2]==true && dp[v1+1][v2+1]==true && dp[v1][v2+1]==true)
        {
            flag=1;
            break;
        }
        if((v1+1)<=n && (v2-1)>0 && dp[v1+1][v2-1]==true && dp[v1+1][v2]==true && dp[v1][v2-1]==true)
        {
            flag=1;
            break;
        }
    }
    if(flag==0) cout<<"0\n";
    else cout<<i+1<<endl;
    return 0;
}
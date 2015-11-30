#include<cstdio>
#include<iostream>
#include<vector>
#include<utility>
#include<string.h>
#include<algorithm>
#include<cmath>

#define LL long long int
#define s(a) scanf("%d",&a)
#define ss(a) scanf("%s",a)
#define w(t) while(t--)
#define f(i,n) for(i=0;i<n;i++)
#define fd(i,n) for(i=n-1;i>=0;i--)
#define p(a) printf("%d",a)
#define ps(a) printf("%s",a)
#define pc(a) printf("%c",a)
#define ent printf("\n")

using namespace std;
char s[1009];

int main()
{
	int n,i,j,k,t;
	cin>>t;
	while(t--)
	{
	    //memset(a,0,sizeof(int));
	    int a[26]={0};
	    cin>>s;
	    n = strlen(s);
	    for(i=0;i<n;i++)
        {
            a[s[i]-97]++;
        }
        /*for(i=0;i<=26;i++)
        {
            cout<<a[i]<<" ";
        }*/
        //cout<<endl;
        int val;
        val=*max_element(a,a+26);
        int dp[val+1][27];
        for(j=0;j<=val;j++)
        {
            dp[j][0]=0;
        }
        for(j=0;j<=26;j++)
        {
            dp[0][j]=0;
        }
        int f=0;
        for(i=1;i<=val;i++)
            {f=0;
                for(j=1;j<=26;j++)
                {
                    if(a[j-1]>0&&a[j-1]==i&&(f==0||a[j-1]==i))
                    {dp[i][j]=max(dp[i-1][j],dp[i][j-1]+1);
                    if(a[j-1]==i)
                        f=1;
                    }
                    else
                     {dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                     if(dp[i][j]==dp[i-1][j])
                     f=0;}

                  //  cout<<dp[i][j]<<" ";
                }
                //cout<<endl;
            }
            int i = val, j = 26;
        int v = dp[i][j];
        char l[v];
        while (i > 0 && j > 0)
        {
        if (dp[i][j] == dp[i][j-1])
        {
          j--;
        }
        else if(i>0&&((dp[i][j]-dp[i-1][j]==1)||(dp[i-1][j]-dp[i][j-1]==0)))
         {
             l[v-1]=char(j+96);
             v--;
             i--;
         }
        else
         {
            l[v-1]=char(j+96);
             v--;
             j--;
         }
        }
        for(i=0;i<dp[val][26];i++)
            cout<<l[i];
        cout<<endl;
            //cout<<dp[val][26]<<endl;
	}
	return 0;
}

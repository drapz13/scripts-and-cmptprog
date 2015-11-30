#include<bits/stdc++.h>
using namespace std;
long long int read_int(){
	char r;
	bool start=false,neg=false;
	long long int ret=0;
	while(true){
		r=getchar();
		if((r-'0'<0 || r-'0'>9) && r!='-' && !start){
			continue;
		}
		if((r-'0'<0 || r-'0'>9) && r!='-' && start){
			break;
		}
		if(start)ret*=10;
		start=true;
		if(r=='-')neg=true;
		else ret+=r-'0';
	}
	if(!neg)
		return ret;
	else
		return -ret;
}
int main()
{
long long int tc;
tc=read_int();
long long int mi[100005];
 long long int a[100005];
while(tc--)
{


long long int n,k,m;
n=read_int();
k=read_int();
m=read_int();
for(long long int i=0;i<n+1;++i)
mi[i]=9999999999;
long long int sum=0;
for(long long int i=1;i<=n;++i)
{
a[i]=read_int();
sum+=a[i];
}
long long int l,r;
long long int c;
for(long long int i=0;i<m;++i)
{
l=read_int();
r=read_int();
c=read_int();
for(long long int j=l;j<=r;++j)
{
if(mi[j]>c)
{
mi[j]=c;
}
}
}
long long int profit[n+2];
long long int wt[n+2];
long long int x=1;
for(long long int i=1;i<=n;++i)
{
if(a[i]<0)
{
profit[x]=-1*a[i];
wt[x]=mi[i];
++x;
}
}
long long int maxp[2][k+1];
for(int i=0;i<k+1;i++)
for(int j=0;j<2;j++)
maxp[j][i]=0;
long long int p=1,t;
for(long long int i=1;i<x;++i,p=p^1)
{
    t=p^1;
for(long long int j=1;j<=k;++j)
{
if(wt[i]<=j)
{
maxp[p][j]=max(maxp[t][j],maxp[t][j-wt[i]]+profit[i]);
//printf("max value is%d\n",maxp[2][j]);
}
else
maxp[p][j]=maxp[t][j];
}
/*for(long long int p=0;p<k+1;++p)
{
maxp[0][p]=maxp[1][p];
}*/
}
printf("%lld\n",maxp[t^1][k]+sum);
}
return 0;
}

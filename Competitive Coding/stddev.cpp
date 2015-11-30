#include <bits/stdc++.h>
using namespace std;
int n;
int a[102][102];
int f=0;
int foo(int i,int j)
{
	//cout<<"a";
    if(i==n-1&&j==n-1)
    {
    	f+=1;
        return 1;
    }

     if(i<n-1&&a[i+1][j]==0)
     foo(i+1,j);
     if(j<n-1&&a[i][j+1]==0)
     foo(i,j+1);
     if(i>0&&a[i-1][j]==0)
     foo(i-1,j);
     if(j>0&&a[i][j-1]==0)
     foo(i,j-1);
}
int main()
{
        cin>>n;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&a[i][j]);
  		f=0;
		foo(0,0);
		cout<<f<<endl;

    return 0;
}

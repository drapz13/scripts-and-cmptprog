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

int main()
{
    int n,m,i,j,k;
    cin>>n>>m;
    k=m;

        j=0;
        int c=0;
            while(1)
            {
            if(k<=n)
            {
                break;
            }
            if(k%2!=0)
            {k=k+1;j++;}
            k=k/2;
            j++;
            }

        cout<<j+(n-k)<<endl;

	return 0;
}
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
    int m,t,r,i,j,c,k,x;
    int a[350],b[350];
    cin>>m>>t>>r;
    for(i=0;i<m;i++)
    {
        cin>>a[i];
    }
    if(r>t)
        printf("-1\n");
    else
    {
        for(i=0;i<r;i++)
        {
            b[i]=a[0]-r+1+i+t;

        }
        j=r;
        for(i=0;i<m;i++)
        {
            if(b[0]>a[i])
            {

            }
            else
            {
                c=0;
                for(k=0;k<r;k++)
                {
                    if(b[k]<=a[i])
                        {   b[k]=a[i]+t-k;
                            //cout<<b[k]<<" ";
                            c++;}
                    else
                        break;
                }
                sort(b,b+r);
                j+=c;
            }
        }
        cout<<j<<endl;
    }
	return 0;
}
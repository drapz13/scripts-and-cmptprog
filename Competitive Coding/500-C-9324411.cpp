//abhi26
#include<cstdio>
#include<iostream>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<utility>

#define LL long long int
#define s(a) scanf("%d",&a)
#define ss(a) scanf("%s",a)
#define p(a) printf("%d",a)
#define ent printf("\n")
#define f(i,n) for(i=0;i<n;i++)
#define fd(i,n) for(i=n-1;i>=0;i--)
#define sl(a) scanf("%I64d",&a)
#define pl(a) printf("%I64d",a)
#define w(t) while(t--)

using namespace std;

int main()
{
	int b[505],c[1010],n,f=0,k=0,m,i,j,a[505],d[505];

	s(n);
	s(m);
	for(i=0;i<n;i++)
    {
        s(a[i]);
        b[i]=0;
    }
    for(i=0;i<m;i++)
    {
        scanf("%d",&c[i]);
        ++b[c[i]-1];
        if(b[c[i]-1]==1)
        {d[k]=c[i]-1;
        k++;    }
    }
	/*for(i=0;i<k;i++)
	{

		printf("%d ",d[i]+1);
	}*/
    int temp,pos,sum=0,z;
    for(i=0;i<m;i++)
    {
        temp=c[i]-1;
        for(j=0;j<=k-1;j++)
        {
            if(d[j]==temp)
            {
                pos=j;

            }
        }
        for(z=pos-1;z>=0;z--)
        {
            sum+=a[d[z]];
            d[z+1]=d[z];


        }
        d[0]=temp;
        /*for(z=0;z<k;z++)
        p(d[z]);
        	printf("\n");*/
    }
    printf("%d\n",sum);
	return 0;
}
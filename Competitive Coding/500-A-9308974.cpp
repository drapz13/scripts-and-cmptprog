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
	int c=0,f=0,n,a[40000],i,k;
	s(n);
	s(k);
	f(i,n-1)
	{
	    s(a[i]);
	}
	for(i=0;i<n-1;)
    {
        c+=a[i];
        i=c;
        if(c==k-1)
        {f=1;
        break;}
        else if(c>=k||i>=n)
            break;
    }
	if(f==1)
        printf("YES");
    else
        printf("NO");
	return 0;
}
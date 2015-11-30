//abhi26
#include<cstdio>
#include<iostream>
#include<string.h>
#include<math.h>
#include<algorithm>

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
#define ii pair<int,int>

using namespace std;

int main()
{
	int i,n,x,sum=0,c=0;
	ii a[100];
	s(n);
	s(x);
	f(i,n)
	{
	    s(a[i].first);
	    s(a[i].second);
	}

	sort(a,a+n);

     c=1;
	for(i=0;i<n;i++)
    {


                while(c+x<=a[i].first)
                {
                    c=c+x;
                }
           //         p(c);
            //    ent;
                sum+=a[i].first-c;
                sum+=a[i].second - a[i].first+1;
                c = a[i].second+1;




    }

    p(sum);
	return 0;
}
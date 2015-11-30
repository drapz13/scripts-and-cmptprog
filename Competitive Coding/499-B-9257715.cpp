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

using namespace std;

char a[3050][3050];
char c[3050][3050];
char b[3050],d[3050];
int e[3050],f[3050];

int main()
{
	int j,n,m,x,i,k=0;
	s(n);
	s(m);
	f(i,m)
	{
	    scanf("%s",a[i]);
	    e[i]=strlen(a[i]);
	    scanf("%s",c[i]);
	    f[i]=strlen(c[i]);
	}
	//scanf("%c",&z);
	for(i=0;i<n;i++)
	{
	    scanf("%s",b);
	    for(j=0;j<m;j++)
            {
                if(strcmp(a[j],b)==0||strcmp(c[j],b)==0)
                {
                    if(e[j]<=f[j])
                        printf("%s ",a[j]);
                    else
                        printf("%s ",c[j]);



                }

            }



	}

	return 0;
}
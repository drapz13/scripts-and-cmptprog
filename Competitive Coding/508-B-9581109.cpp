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
char a[100090];
int main()
{
    int i,x,f=0,pos;
    char y,j;
    ss(a);
    x = strlen(a);
    y=a[x-1];

    for(i=0;i<x;i++)
    {

//        cout<<a[i]<<" ";
        if((a[i]-'0')%2==0)
        {
            //cout<<a[i]<<endl;
            f=1;
            j=a[i];
            pos=i;
            if(j<y)
            {
           //     cout<<a[i]<<endl;
                break;
            }

        }
    }
    if(f==1)
    {
        //char temp = j;
        a[pos]=y;
        a[x-1]=j;
        for(i=0;i<x;i++)
        {
            printf("%c",a[i]);
        }
        cout<<endl;
    }
    else
        printf("-1\n");
	return 0;
}
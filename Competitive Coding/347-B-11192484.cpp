#include<cstdio>
#include<iostream>
#include<vector>
#include<utility>
#include<string.h>
#include<algorithm>
#include<cmath>

//#define LL long long int
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
int a[100009];
int main()
{
    int n,i,j,k=0;
    cin>>n;
    f(i,n)
    {
        cin>>a[i];
        if(a[i]==i)
            k++;
    }
    if(n-k>1)
    {int f=0;
        for(i=0;i<n;i++)
        {
            if(a[i]!=i)
            {
                if(a[a[i]]==i)
                {
                    k+=2;
                    f=1;
                    break;
                }
            }
        }
        if(f==0)
        cout<<k+1;
        else
            cout<<k;
    }
    else
        cout<<k;
    return 0;
}
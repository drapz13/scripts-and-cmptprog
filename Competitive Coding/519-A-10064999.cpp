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
    char a[10][10];
    int i,j,sum=0,sumw=0;
    for(i=0;i<8;i++)
    {
        scanf("%s",a[i]);
    }
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            if(a[i][j]=='Q')
                sum+=9;
            if(a[i][j]=='R')
                sum+=5;
                if(a[i][j]=='B')
                sum+=3;
                if(a[i][j]=='N')
                sum+=3;
                if(a[i][j]=='q')
                sumw+=9;
                if(a[i][j]=='r')
                sumw+=5;
                if(a[i][j]=='b')
                sumw+=3;
                if(a[i][j]=='n')
                sumw+=3;
                if(a[i][j]=='P')
                sum+=1;
                if(a[i][j]=='p')
                sumw+=1;
        }
    }
    if(sum==sumw)
        cout<<"Draw"<<endl;
    else if(sum>sumw)
        cout<<"White"<<endl;
    else
        cout<<"Black"<<endl;
    return 0;
}
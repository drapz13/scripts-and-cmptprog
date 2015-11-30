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
char a[200090],b[200090];
int main()
{
    int i,j,x,y,z1[26],z2[26],v1[26],v2[26];/** z1 -> lowercase a z2 -> uppercase a v1->lowercase b v2->uppercase b;**/
    for(i=0;i<26;i++)
        z1[i]=z2[i]=v1[i]=v2[i]=0;
    cin>>a>>b;
    x = strlen(a);
    y = strlen(b);
    for(i=0;i<x;i++)
    {
        for(j=0;j<26;j++)
        {
            if(a[i]==j+97)
            {
                z1[j]++;
            }
            if(a[i]==j+65)
            {
                z2[j]++;
            }
        }
    }
    for(i=0;i<y;i++)
    {
        for(j=0;j<26;j++)
        {
            if(b[i]==j+97)
            {
                v1[j]++;
            }
            if(b[i]==j+65)
            {
                v2[j]++;
            }
        }
    }
    int c1,c2,s,d,e;
    c1=c2=0;
    for(i=0;i<26;i++)
    {

        if(z1[i]<=v1[i])
        {
            c1=c1+z1[i];
            d=v1[i];
            v1[i]=v1[i]-z1[i];
        }
        else
            {c1+=v1[i];
            d=v1[i];
            v1[i]=0;}
        if(z2[i]<=v2[i])
        {
            c1=c1+z2[i];
            e=v2[i];
            v2[i]=v2[i]-z2[i];
        }
        else
            {c1+=v2[i];
            e = v2[i];
            v2[i]=0;}
        if(z1[i]>d)
        {
            if(z1[i]-d<=v2[i])
            {
                c2+=z1[i]-d;
                v2[i]=v2[i]-z1[i]+d;
            }
            else
                {c2+=v2[i];
                v2[i]=0;}
        }
        if(z2[i]>e)
        {
            if(z2[i]-e<=v1[i])
            {
                c2+=z2[i]-e;
                v1[i]=v1[i]-z2[i]+e;
            }
            else
                {c2+=v1[i];
                v1[i]=0;}
        }
        //cout<<c1<<" "<<c2<<" "<<endl;
    }
    cout<<c1<<" "<<c2<<endl;
	return 0;
}
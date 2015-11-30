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
pair <char,int>c[200090];
pair <char,int>d[200090];
int main()
{

    int n,i,j,k=0;
    s(n);
    ss(a);
    ss(b);
    for(i=0;i<n;i++)
    {
        if(a[i]!=b[i])
        {
            c[k].first=a[i];
            d[k].first=b[i];
            c[k].second=i;
            d[k].second=i;
            k++;
        }
    }
    if(k==0)
    {
        cout<<"0\n";
        cout<<"-1 -1\n";
    }
    else
    {
        sort(c,c+k);
        sort(d,d+k);
        /*for(i=0;i<k;i++)
        {
            cout<<c[i].first<<" "<<c[i].second<<endl;
            cout<<d[i].first<<" "<<d[i].second<<endl;
        }*/
        int m=0,s=0,j=0,i=0,pos1=-2,pos2=-2;
        for(;i<k;)
        {   if(i==k||j==k)
            break;
            if(c[i].first==d[j].first)
            {
                m++;
            if(b[c[i].second]==a[d[j].second])
                m++;

            if(s<m)
            {
             s=m;
             pos1=c[i].second;
             pos2=d[j].second;
            }
            if(s==2)
                {break;}i++;
                m=0;}
            else if(c[i].first>d[j].first)
            {
                m=0;
                j++;
            }
            else if(c[i].first<d[j].first)
            {   m=0;
                i++;
            }
        }
        i=0;j=0,m=0;
        for(;i<k;)
        {   if(i==k||j==k)
            break;
            if(c[i].first==d[j].first)
            {
                m++;
            if(b[c[i].second]==a[d[j].second])
                m++;

            if(s<m)
            {
             s=m;
             pos1=c[i].second;
             pos2=d[j].second;
            }
            if(s==2)
                {break;}j++;
                m=0;}
            else if(c[i].first>d[j].first)
            {
                m=0;
                j++;
            }
            else if(c[i].first<d[j].first)
            {   m=0;
                i++;
            }
        }
        cout<<k-s<<endl;
        cout<<pos1+1<<" "<<pos2+1<<endl;
    }

    return 0;
}
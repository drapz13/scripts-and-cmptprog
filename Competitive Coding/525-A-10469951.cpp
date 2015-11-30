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
char a[200090],b[100009];
vector <int>c[26];
int main()
{
    int n,i,j,s=0;
    cin>>n;
    cin>>a;
    for(i=0;i<2*n-2;i++)
    {
        if(i%2!=0)
        {
            b[i/2]=a[i];
        }
        else
            c[a[i]-97].push_back(i/2);
    }
    for(i=0;i<n-1;i++)
    {
        if(c[b[i]-65].size()!=0&&c[b[i]-65][0]<=i)
        {
            c[b[i]-65].erase(c[b[i]-65].begin());
        }
        else
            s++;
    }
    cout<<s<<endl;
    return 0;
}
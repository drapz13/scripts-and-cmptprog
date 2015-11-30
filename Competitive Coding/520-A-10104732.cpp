#include<bits/stdc++.h>

using namespace std;
char a[190];
int b[190];
int main()
{
    int i,j,n;
    cin>>n;
    cin>>a;

    //n = strlen(a);
    memset(b,0,sizeof(n));
    for(i=0;i<n;i++)
    {
        if(a[i]<95)
        b[a[i]-65]++;
        else
            b[a[i]-97]++;
    }
    int f=0;
    for(i=0;i<26;i++)
    {
        if(b[i]==0)
        {
            f=1;
            break;
        }
    }
    if(f==0)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}
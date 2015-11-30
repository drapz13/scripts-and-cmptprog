#include<bits/stdc++.h>
using namespace std;

char s[200090];
int d[100090]={0};
int main()
{
    int m,k,i,x,j,e,l=0;
    cin>>s;
    x = strlen(s);
    cin>>m;
    for(i=0;i<m;i++)
    {
        cin>>e;
        if(d[e-1]%2==0)
            d[e-1]++;
        else
            d[e-1]=0;
    }
    for(i=0;i<x;i++)
    {
        if(2*i<x)
        {
            if(d[i]!=0&&l%2==0)
            l++;
            else if(d[i]!=0&&l%2!=0)
            l=0;
        if(l!=0)
            {cout<<s[x-i-1];
            }
        else
            {cout<<s[i];}}
        else
        {

        if(l!=0)
            {cout<<s[x-i-1];
            }
        else
            {cout<<s[i];}
        if(d[x-1-i]!=0&&l%2==0)
            l++;
            else if(d[x-1-i]!=0&&l%2!=0)
            l=0;

        }

    }
    cout<<endl;
    return 0;
}
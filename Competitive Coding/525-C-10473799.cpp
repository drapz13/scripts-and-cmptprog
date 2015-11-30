#include<bits/stdc++.h>

using namespace std;
int a[100009];
long long int e[100009];
int main()
{
    int n,i,pos1,j;

    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    pos1=n;
    sort(a,a+n);
    j=0;
    for(i=n-1;i>0;i--)
    {
        if(a[i]-a[i-1]==0)
        {
            if(pos1!=i)
            {e[j]=a[i];
            j++;
            pos1=i-1;}

        }
        else if(a[i]-a[i-1]==1)
        {
            if(pos1!=i)
            {e[j]=a[i-1];
            j++;
            pos1=i-1;}
        }

    }
    /*for(i=0;i<j;i++)
        cout<<e[i]<<" ";*/
    sort(e,e+j);
    long long int s=0;
                for(i=j-1;i>=1;i=i-2)
                {
                    s+=e[i]*e[i-1];
                }
                cout<<s<<endl;

    return 0;
}
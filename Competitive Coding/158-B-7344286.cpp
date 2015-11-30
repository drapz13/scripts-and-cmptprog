#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int p=0,q=0,r=0,s=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==1)
            p++;
        else if(a[i]==2)
            q++;
        else if(a[i]==3)
            r++;
        else s++;
    }
    int f=s + r;//cout<<"f"<<f<<endl;
    if(p>r)
        p-=r;
    else p=0;
    //cout<<"p"<<p<<endl;
    int t=q%2;
    q/=2;
    //cout<<"q"<<q<<endl;
    //cout<<"t"<<t<<endl;
    f+=q;
    if(t>0)
    {
        f++;
        if(p>0)
        {
            if(p==1)
                p=0;
            else p-=2;
        }
    }
    //cout<<"p"<<p<<endl;
    if(p>0)
        f+= ceil(p/4.0);

    cout<<f<<endl;
    return 0;
}
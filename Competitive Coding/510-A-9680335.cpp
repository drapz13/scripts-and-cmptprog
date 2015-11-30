#include<bits/stdc++.h>

using namespace std;

int main()
{
    int i,j,k,l,f,n,m;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {   f=0;

            if((i+1)%4==0)
            {
                if(j==0)
                {
                    cout<<"#";
                }
                else
                cout<<".";

                f=1;
            }
            if((i+1)%2==0&&j!=m-1&&f==0)
            {   f=1;
                cout<<".";
            }
            if(f==0)
                cout<<"#";
        }
        cout<<endl;
    }
    return 0;
}
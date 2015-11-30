#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
  int a=m,i,c=0;
          for(i=0;i<a;i++)
          {
              if(m+n<3||m==0||n==0)
                break;
              else
              {
                  if(m>=n)
                    {m=m-2;
                    n=n-1;
                    c+=1;
                    }
                  else
                    {m=m-1;
                    n=n-2;
                    c+=1;
                    }
              }
          }
          cout<<c<<endl;
    return 0;
}
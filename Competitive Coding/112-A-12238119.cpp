#include <bits/stdc++.h>

    using namespace std;


    int main()
    {

      char arr[100000];
      char arr1[100000];
      int ptr=0,sze,ct=0,ct1=0;
      gets(arr);
      gets(arr1);
      int f=0;
      sze=strlen(arr);
      for(int i=0;i<sze;i++)
        {
            if((int)arr[i]>=65&&(int)arr[i]<=90)
            {
                arr[i]+=32;
            }
            if((int)arr1[i]>=65&&(int)arr1[i]<=90)
            {
                arr1[i]+=32;
            }
            //cout<<arr[i]<<" "<<arr1[i]<<endl;
            if(arr[i]!=arr1[i])
            {
                f=(arr[i]>arr1[i])?1:-1;
                break;
            }

 //       printf("%d %d %d %d %d\n",arr[i],arr1[i],ptr,ct,ct1);
        }
        if(f==0)
            printf("0\n");
        else if(f==1)
            printf("1\n");
        else
            printf("-1\n");
        return 0;
    }
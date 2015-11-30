#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int a[n],i,maxx=0,max2=0,pos2,minx=1009,pos1;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(i>0&&maxx<=a[i]-a[i-1])
        {
            maxx=a[i]-a[i-1];
            pos1=i-1;
        }
        if(i>1&&minx>a[i]-a[i-2])
        {
            minx=a[i]-a[i-2];
            pos2=i-2;
        }
    }

    if(pos1!=pos2&&pos1+1!=pos2)
    {
        printf("%d",max(maxx,minx));
    }
    else
    {
        for(i=0;i<n;i++)
        {
                if(i>0&&max2<=a[i]-a[i-1]&&i!=pos2+2&&i!=pos2+1)
                {
                    max2=a[i]-a[i-1];
                }
        }

        printf("%d",max(max2,minx));

    }
    //printf("\n%d %d %d %d %d \n",pos1,pos2,maxx,max2,minx);
    return 0;
}
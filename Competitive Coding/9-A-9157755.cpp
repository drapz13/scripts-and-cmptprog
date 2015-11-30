#include<cstdio>
#include<algorithm>
using namespace std;

int gcd(int a,int b)
{if (b==0) { return a;}

    else
        return gcd(b, a % b);
}


int main()
{
    int a,b,c,d;
    scanf("%d %d",&a,&b);
    c = max(a,b);
    if(c<=6&&a<=6&&b<=6)
    {d = gcd(6-c+1,6);
    //printf("%d\n",d);
    printf("%d/%d",(6-c+1)/d,6/d);
    }
    else
        printf("0/1");
    return 0;
}
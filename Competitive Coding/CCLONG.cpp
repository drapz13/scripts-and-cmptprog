#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
using namespace std;
typedef long long ll;
#define mod 1000000007

int n,q;
ll st[300000];
int s[300000];
int e[300000];
ll cumsum[100009];
ll input[100009];
ll lazyM[300000];
ll lazyA[300000];
ll lazyR[300000];
void init(int in,int si,int ei){
	s[in] = si;
	e[in] = ei;
	st[in] = cumsum[ei]-cumsum[si-1];
	lazyR[in] = -1;
	lazyM[in] = 1;
	lazyA[in] = 0;
	if(si!=ei){
		int middle = (si+ei)/2;
		init(2*in,si,middle);
		init(2*in+1,middle+1,ei);
	}
}







void jupdate(int in,ll v,int ty){
	if(ty==1){lazyA[in]+=v;lazyA[in]%=mod;}
	else if(ty==2){lazyM[in]*=v;lazyA[in]*=v;lazyM[in]%=mod;lazyA[in]%=mod;}
	else {lazyR[in] = v;lazyA[in] = 0;lazyM[in] = 1;}
}





void update(int in,int si,int ei,ll v,int ty){
	cout<<in<<si<<ei<<"a";
	for(int i=1;i<=n;i++)
    {
        cout<<s[i]<<" "<<e[i]<<endl;
    }
	if(s[in]==si&&e[in]==ei)
    {
		cout<<"DARPAN";
		if(ty==1){lazyA[in]+=v;lazyA[in]%=mod;}
		else if(ty==2){lazyM[in]*=v;lazyA[in]*=v;lazyM[in]%=mod;lazyA[in]%=mod;}
		else {lazyR[in] = v;lazyA[in] = 0;lazyM[in] = 1;}
       /* for(int i=1;i<=n;i++)
    {
        cout<<s[i]<<" "<<e[i]<<endl;
    }*/

		if(s[in]!=e[in])
        {
		//int middle = (s[in]+e[in])/2;
            if(lazyR[in]!=-1){jupdate(2*in,lazyR[in],3);jupdate(2*in+1,lazyR[in],3);}
            jupdate(2*in,lazyM[in],2);
            jupdate(2*in+1,lazyM[in],2);
            jupdate(2*in,lazyA[in],1);
            jupdate(2*in+1,lazyA[in],1);
        }


		if(lazyR[in]!=-1){st[in] = (e[in]-s[in]+1)*lazyR[in];}
		st[in] *= lazyM[in];
		st[in]%=mod;
		lazyM[in] = 1;
		st[in] += (e[in]-s[in]+1)*lazyA[in];
		st[in]%=mod;
		lazyA[in] = 0;
		lazyR[in] = -1;
		return;
	}
    //cout<<"a";
    cout<<"BANSAL";
	int middle = (s[in]+e[in])/2;
	if(lazyR[in]!=-1){jupdate(2*in,lazyR[in],3);jupdate(2*in+1,lazyR[in],3);}
	jupdate(2*in,lazyM[in],2);
	jupdate(2*in+1,lazyM[in],2);
	jupdate(2*in,lazyA[in],1);
	jupdate(2*in+1,lazyA[in],1);


lazyR[in] =  -1;
lazyM[in] = 1;
lazyA[in] = 0;




	if(ei<=middle){
		update(2*in,si,ei,v,ty);
		update(2*in+1,middle+1,e[in],0,1);
	}
	else if(si>middle){
		update(2*in,s[in],middle,0,1);
		update(2*in+1,si,ei,v,ty);
	}
	else{
		update(2*in,si,middle,v,ty);
		update(2*in+1,middle+1,ei,v,ty);

	}
	st[in] = (st[2*in] + st[2*in+1])%mod;
	for(int i=1;i<=n;i++)
    {
        cout<<st[i]<<" "<<lazyA[i]<<" "<<lazyM[i]<<" "<<lazyR[i]<<" "<<s[i]<<" "<<e[i]<<endl;
    }
}

ll query(int in,int si,int ei){
	int middle = (s[in]+e[in])/2;



	if(s[in]==si&&e[in]==ei){
		if(si!=ei){
			if(lazyR[in]!=-1){jupdate(2*in,lazyR[in],3);jupdate(2*in+1,lazyR[in],3);}
				jupdate(2*in,lazyM[in],2);
				jupdate(2*in+1,lazyM[in],2);
				jupdate(2*in,lazyA[in],1);
				jupdate(2*in+1,lazyA[in],1);
		}
		if(lazyR[in]!=-1){st[in] = (e[in]-s[in]+1)*lazyR[in];}
				st[in] *= lazyM[in];
				st[in]%=mod;
				lazyM[in] = 1;
				st[in] += (e[in]-s[in]+1)*lazyA[in];
				st[in]%=mod;
				lazyA[in] = 0;
				lazyR[in] = -1;
		return st[in];
	}





	if(s[in]!=e[in]){
	if(lazyR[in]!=-1){jupdate(2*in,lazyR[in],3);jupdate(2*in+1,lazyR[in],3);}

	jupdate(2*in,lazyM[in],2);
	jupdate(2*in+1,lazyM[in],2);
	jupdate(2*in,lazyA[in],1);
	jupdate(2*in+1,lazyA[in],1);
	}


	if(lazyR[in]!=-1){st[in] = (e[in]-s[in]+1)*lazyR[in];}
			st[in] *= lazyM[in];
			st[in]%=mod;
			lazyM[in] = 1;
			st[in] += (e[in]-s[in]+1)*lazyA[in];
			st[in]%=mod;
			lazyA[in] = 0;
			lazyR[in] = -1;
	if(ei<=middle){
		return query(2*in,si,ei);
	}
	else if(si>middle){return query(2*in+1,si,ei);}
	else{return (query(2*in,si,middle)+query(2*in+1,middle+1,ei))%mod;}
	return 0;}










int main(){
	freopen("C:\\Users\\DARPAN\\Desktop\\aa.txt","w",stdout);
	freopen("C:\\Users\\DARPAN\\Desktop\\a.txt","r",stdin);

	cin>>n>>q;
	cumsum[0] = 0;
	for(int i=1;i<=n;i++){cin>>input[i];cumsum[i] = cumsum[i-1]+input[i];}
	init(1,1,n);
	while(q--){
		int temp;
		cin>>temp;
		if(temp==4){
			int x;
			int y;
			cin>>x>>y;
			printf("%lld\n",(query(1,x,y)+mod)%mod);}
		else{
			int x,y;
			ll v;
			cin>>x>>y>>v;
			//cout<<q;
			update(1,x,y,v,temp);
			//cout<<q;
		}
	}

}





/*

#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
#define mod 1000000007
#define max 100010
#define Fr(i,a,n) for(i=a; i<n; i++)

int max_size;

int getMid(int a, int b) {  return a+(b-a)/2;  }

int getSumUtil(int *st, int ss, int se, int qs, int qe, int i)
{
 if(qs<=ss && qe>=se)
        return st[i];

    if(se<qs || ss>qe)
        return 0;

    int mid=getMid(ss, se);
    return getSumUtil(st, ss, mid, qs, qe, 2*i+1) + getSumUtil(st, mid+1, se, qs, qe, 2*i+2);
}

void ValueUpdate(int *st, int x, int y, int i, int d, int in)
{  int mid;

 if(i<x || i>y) return;
 st[in]=(st[in]+d)%mod;

 if(y!=x)
 { mid=getMid(x, y);
  ValueUpdate(st, x, mid, i, d, 2*in+1);
  ValueUpdate(st, mid+1, y, i, d, 2*in+2); }
}

int getSum(int *st, int n, int qs, int qe)
{
    if(qs<0 || qe>n-1 || qs>qe)
    {
       return -1;
    }
    return getSumUtil(st, 0, n-1,
qs, qe, 0);
}

int makeSTUtil(int arr[], int ss, int se, int *st, int si, int *b)
{
    if(ss==se)
    {
        st[si]=arr[ss];
        b[ss]=si;
        return arr[ss];
    }

    int mid=getMid(ss, se);
    st[si]= makeSTUtil(arr, ss, mid, st, si*2+1, b) + makeSTUtil(arr, mid+1, se, st, si*2+2, b);
    return st[si];
}

int *makeST(int arr[], int n, int b[])
{
    int x=(int)(ceil(log2(n)));
    max_size=2*(int)pow(2, x)-1;
  int *st=new int[max_size];

    makeSTUtil(arr, 0, n-1, st, 0, b);
    return st;
}

int main()
{ int N, Q, n, x, y, v, i, j, a[max], b[max], d, k;

 scanf("%d %d",&N,&Q);
 Fr(i,0,N)
    scanf("%d", &a[i]);

 int *st=makeST(a, N, b);

while(Q--)
{ scanf("%d %d %d",&n,&x,&y);
 if(n==4)
  printf("%d\n",getSum(st, N, x-1, y-1));
 else
 { scanf("%d",&v);
  x-=1;
  Fr(i,x,y)
  {
 switch(n)
 { case 1: d=v; break;
   case 2: k=b[i]; d=((v*st[k])%mod)-st[k]; break;
   case 3: k=b[i]; d=v-st[k]; break;
 }

   ValueUpdate(st, 0, N-1, i, d, 0);
  }
 }

}

    return 0;
}
*/








/*
// Program to show segment tree operations like construction, query and update
#include <stdio.h>
#include <math.h>
#include<iostream>

int getMid(int s, int e) { return s + (e -s)/2; }


int getSumUtil(int *st, int ss, int se, int qs, int qe, int index)
{
	if (qs <= ss && qe >= se)
		return st[index];
	if (se < qs || ss > qe)
		return 0;

	int mid = getMid(ss, se);
	return getSumUtil(st, ss, mid, qs, qe, 2*index+1) +
		getSumUtil(st, mid+1, se, qs, qe, 2*index+2);
}

int addvUtil(int *st, int ss, int se, int qs, int qe, int index,int v)
{

	if ((ss == se) && (ss>=qs && se<=qe))
	{
		st[index]+=v;
		return st[index];
	}

	if (se < qs || ss > qe)
		return st[index];


	int mid = getMid(ss, se);
	st[index]= addvUtil(st, ss, mid, qs, qe, 2*index+1,v) +
		addvUtil(st, mid+1, se, qs, qe, 2*index+2,v);
		return st[index];
}

int mulvUtil(int *st, int ss, int se, int qs, int qe, int index,int v)
{

	if (ss == se && (ss>=qs && se<=qe))
	{
		st[index]*=v;
		return st[index];
	}

	if (se < qs || ss > qe)
		return st[index];


	int mid = getMid(ss, se);
	st[index]= mulvUtil(st, ss, mid, qs, qe, 2*index+1,v) +
		mulvUtil(st, mid+1, se, qs, qe, 2*index+2,v);
		return st[index];
}

int updatevUtil(int *st, int ss, int se, int qs, int qe, int index,int v)
{

	if (ss == se && (ss>=qs && se<=qe))
	{
		st[index]=v;
		return st[index];
	}

	if (se < qs || ss > qe)
		return st[index];


	int mid = getMid(ss, se);
	st[index]= updatevUtil(st, ss, mid, qs, qe, 2*index+1,v) +
		updatevUtil(st, mid+1, se, qs, qe, 2*index+2,v);
		return st[index];
}


int constructSTUtil(int arr[], int ss, int se, int *st, int si)
{
	if (ss == se)
	{
		st[si] = arr[ss];
		return arr[ss];
	}

	int mid = getMid(ss, se);
	st[si] = constructSTUtil(arr, ss, mid, st, si*2+1) +
			constructSTUtil(arr, mid+1, se, st, si*2+2);
	return st[si];
}

int *constructST(int arr[], int n)
{
	int x = (int)(ceil(log2(n))); //Height of segment tree
	int max_size = 2*(1<<x) - 1; //Maximum size of segment tree
	int *st = new int[max_size];

	constructSTUtil(arr, 0, n-1, st, 0);

	return st;
}

int main()
{
	int n,q;
	scanf("%d %d",&n,&q);
	int a[n];
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	int *st = constructST(a, n);
	for(int i=0;i<q;i++)
	{
	int t,x,y,v,temp;
		scanf("%d %d %d",&t,&x,&y);
		x--;
		y--;
		if(t==1)
		{
			scanf("%d",&v);
			temp=addvUtil(st, 0, n-1, x, y, 0, v);
		}
		if(t==2)
		{
			scanf("%d",&v);
			temp=mulvUtil(st, 0, n-1, x, y, 0, v);
		}
		if(t==3)
		{
			scanf("%d",&v);
			temp=updatevUtil(st, 0, n-1, x, y, 0, v);
		}
		if(t==4)
		{
			temp=getSumUtil(st, 0, n-1, x, y, 0);
			printf("%d\n",temp);
		}
	}
	return 0;
}
*/

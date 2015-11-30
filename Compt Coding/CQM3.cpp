#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define _ ios_base::sync_with_stdio(false);cin.tie(0);
#define __ int t;cin>>t;while(t--)
#define endl '\n'
#define ispow2(n) (n&&(!(n&(n-1))))      ///check if its perfect power of 2
using namespace std;
template <typename T>
T modpow(T base, T exp) {
  /// base %= modulus;
  T result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base); ///  % modulus;
    base = (base * base); ///  % modulus;
    exp >>= 1;
  }
  return result;
}

int getMid(int s, int e) {  return s + (e -s)/2;  }
int getSumUtil(int *st, int ss, int se, int qs, int qe, int index)
{
    if (qs <= ss && qe >= se)
        return st[index];
    if (se < qs || ss > qe)
        return 0;
    int mid = getMid(ss, se);
    return pow(-1,2*index+1)*getSumUtil(st, ss, mid, qs, qe, 2*index+1) +
           pow(-1,2*index+2)*getSumUtil(st, mid+1, se, qs, qe, 2*index+2);
}
void updateValueUtil(int *st, int ss, int se, int i, int diff, int index)
{
    if (i < ss || i > se)
        return;
    st[index] = st[index] + diff;
    if (se != ss)
    {
        int mid = getMid(ss, se);
        updateValueUtil(st, ss, mid, i, diff, 2*index + 1);
        updateValueUtil(st, mid+1, se, i, diff, 2*index + 2);
    }
}
void updateValue(int arr[], int *st, int n, int i, int new_val)
{
    if (i < 0 || i > n-1)
    {
        printf("Invalid Input");
        return;
    }
    int diff = new_val - arr[i];
    arr[i] = new_val;
    updateValueUtil(st, 0, n-1, i, diff, 0);
}
int getSum(int *st, int n, int qs, int qe)
{
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        printf("Invalid Input");
        return -1;
    }

    return getSumUtil(st, 0, n-1, qs, qe, 0);
}
int constructSTUtil(int arr[], int ss, int se, int *st, int si)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
    int mid = getMid(ss, se);
    st[si] =  constructSTUtil(arr, ss, mid, st, si*2+1) +
              constructSTUtil(arr, mid+1, se, st, si*2+2);
    return st[si];
}
int *constructST(int arr[], int n)
{
    int x = (int)(ceil(log2(n)));
    int max_size = 2*(int)pow(2, x) - 1;
    int *st = new int[max_size];
    constructSTUtil(arr, 0, n-1, st, 0);
    return st;
}

int arr[100005];
int main()
{
    string s;
    cin>>s;
    int l=s.length();
    int n=l;
    for(int i=0;i<l;i++) arr[i]=s[i]-'0';
    int *st = constructST(arr, n);
    int q;
    cin>>q;
    while(q--)
    {
        int x;
        cin>>x;
        if(x==0)
        {
            int a,b;
            cin>>a>>b;
            int temp=getSum(st,n,a,b);
            temp=abs(temp);
            cout<<temp<<endl;
        }
        else
        {
            int a;
            cin>>a;
            updateValue(arr,st,n,a,1);
        }
    }
    return 0;
}

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

int tree[200005];
int arr[100005];
void maxi(int curr,int st,int en)
{
    tree[curr]=(*min_element(arr+st,arr+en+1));
    //cout<<curr<<" "<<st<<" "<<en<<endl;
    if(st==en) return;
    maxi(2*curr+1,st,(st+en)/2);
    maxi(2*curr+2,(st+en)/2 +1,en);
}
int mini=0;
int n;
/// 0 4 6 0 7
int RMQ(int curr,int st,int en,int ss,int ee) /// st>>req_start ss>>curr_start en>>req_end ee>>curr_end
{
    if(st>ee || en<ss) return INT_MAX;
    if(st<=ss && en>=ee)
    {
        //cout<<tree[curr]<<"YES"<<curr<<endl;
        return tree[curr];
    }
    int mid=(ss+ee)/2; /// 5
    return min(RMQ(curr*2 +1,st,en,ss,mid),RMQ(curr*2 +2,st,en,mid+1,ee)); /// 2 4 6 4 7 >> 2 ;; 3
}
int main()
{
    _        ///  FAST I/O
    // __       ///  T TEST CASES
    {
        int t;
        cin>>n>>t;
        for(int width_i = 0;width_i < n;width_i++)
        {
            cin >> arr[width_i];
        }
        maxi(0,0,n-1);
        for(int a0 = 0; a0 < t; a0++)
        {
            int i;
            int j;
            cin>>i>>j;
            cout<<RMQ(0,i,j,0,n-1)<<endl; /// 0 3
        }
    }
    return 0;
}

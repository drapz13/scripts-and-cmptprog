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

int n;
vector < int > v[100005];
int v1[100005];
int ct[100005][4];
bool vis[100005];
bool ff;


void dfs(int ii) {
    vis[ii] = 1;
    for (auto u: v[ii]) {
        if (!vis[u]) {
            dfs(u);
            ct[ii][v1[u]]++;
        }
    }
    int mx = 0;
    for (int i = 0; i < 4; i++)
        if (ct[ii][i] > 0)
            mx = i;
    if (mx <= 0 && ct[ii][0] <= 1)  {
        v1[ii] = 0;
        return;
    }
    if (mx <= 0 && ct[ii][0] == 2) {
        v1[ii] = 1;
        return;
    }
    if (mx <= 2 && ct[ii][2] <= 1) {
        v1[ii] = 2;
        return;
    }
    if (mx <= 2 && ct[ii][2] == 2) {
        v1[ii] = 3;
        return;
    }
   /* if (mx <= 3 && ct[ii][3] == 1) {
        if (ct[ii][2] == 0 && ct[ii][1] == 0 && ct[ii][0] <= 2)  {
            v1[ii] ==
        }


    }*/
    ff = 1;

}

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int ii, u;
        scanf("%d%d", &ii, &u); ii--; u--;
        v[ii].pb(u);
        v[u].pb(ii);
    }
}

void clear() {
    ff = 0;
    for (int i = 0; i < n; i++) {
        vis[i] = 0;
        v1[i] = 0;
        for (int j = 0; j < 4; j++)
            ct[i][j] = 0;
    }

}

int solve(int st = 0) {
    clear();
    dfs(st);
    if (ff) {
        for (int i = 0; i < n; i++)
            if (v1[i] == 3) {
                clear();
                dfs(i);
                break;
            }
    }
    //for (int i = 0; i < n; i++) {
        //db2(i + 1, v1[i]);
    //}
    return !ff;
}

void printAns(int x)
{
    if (x)
        puts("Yes");
    else
        puts("No");
}
int main()
{
    _        ///  FAST I/O
    // __       ///  T TEST CASES
    {
        read();
        printAns(solve(0));
    }
    return 0;
}

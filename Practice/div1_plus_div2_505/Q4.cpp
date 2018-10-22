#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>
#include <list>
#include <map>
#include <utility>
#include <vector>
#include <set>
#include <string>
#include <queue>
using namespace std;

#define ll long long int
#define INF 1000000007
#define INFLL 1000000000000000011LL
#define pb(x) push_back(x)
#define mp make_pair
#define fi first
#define se second
#define vi vector
#define gtl(x) getline(cin, (x))
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)((a).size())
#define setv(x,a) memset(x,a,sizeof(x))
#define ull unsigned long long int 

long long modmult(long long a,long long b,long long mod)
{
    if (a == 0 || b < mod / a)
        return (a*b)%mod;
    long long sum;
    sum = 0;
    while(b>0)
    {
        if(b&1)
            sum = (sum + a) % mod;
        a = (2*a) % mod;
        b>>=1;
    }
    return sum;
}

ull PowMod(ull n, ll m)
{
    ull ret = 1;
    ull a = m;
    while (n > 0) {
        if (n & 1) ret = ((ret%INF) * (a%INF)) % INF;
        a = ((a%INF) * (a%INF)) % INF;
        n >>= 1;
    }
    return ret;
}

int gcd(int a, int b) {
            if (a == 0) return b;
            if (b == 0) return a;
            if (a < 0) return gcd(-1 * a, b);
            if (b < 0) return gcd(a, -1 * b);
            if (a > b) return gcd(b, a);
            return gcd(b%a, a);
}

int g[710][710];
int dp[710][710][2];


int solve(int i, int j, int k) {
    if(i>j) return 1;

    if(dp[i][j][k]!=-1) return dp[i][j][k];

    if(k==0) {
        for(int l=i;l<=j;l++) {
            if(g[i-1][l]==1) {
                int a = solve(i,l-1,1);
                int b = solve(l+1,j,0);
                if(a&b) {
                    dp[i][j][k]=1;
                    return 1;
                }
            }
        }

        return dp[i][j][k]=0;
    } else {
        for(int l=i;l<=j;l++) {
            if(g[l][j+1]==1) {
                int a = solve(i,l-1,1);
                int b = solve(l+1,j,0);
                if(a&b) {
                    dp[i][j][k]=1;
                    return 1;
                }
            }
        }

        return dp[i][j][k]=0;
    }
}



int main() {
    int n;
    cin>>n;

    ll a[n];
    for(int i=0;i<n;i++) cin>>a[i];


    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) if(__gcd(a[i],a[j])>1) g[i][j]=1;
    }

    for(int i=0;i<n;i++) g[i][i]=1;

    for(int i=0;i<710;i++) {
        for(int j=0;j<710;j++) dp[i][j][0]=-1,dp[i][j][1]=-1;
    }

    for(int i=0;i<n;i++) {
        if(solve(0,i-1,1) && solve(i+1,n-1,0)) {
            cout<<"Yes"<<endl;
            return 0;
        }
    }

    cout<<"No"<<endl;
    
}
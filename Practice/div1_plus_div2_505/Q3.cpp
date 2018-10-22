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


int main() {
   string b;
   cin>>b;

   int n = b.length();
   int answer=0;

   int mx = 1;
    for(int i=0;i<n-1;i++) {
        if(b[i]!=b[i+1]) {
            mx++;
        } else {
            answer = max(answer,mx);
            mx=1;
        }
    }

    answer = max(answer,mx);
    if(answer == n) {
        cout<<answer<<endl;
        return 0;
    }
   // for(int i=0;i<n;i++) {
        if((b[0]=='b' && b[n-1]=='b')||(b[0]=='w' && b[n-1]=='w')) {
           // break;
        } else {
            int t=0;
            for(;t<n-1;t++) {
                if(b[t]==b[t+1]) {
                    break;
                }
            }

            int y = n-1;
            for(;y>1;y--) {
                if(b[y-1]==b[y]) break;
            }

            if(y<=t) {
                // check=1;
                
            } else {
                if(n-y+t+1>answer) {
                answer = n-y+t+1;
                 } 
            }
            
   }

   cout<<answer<<endl;

    
}
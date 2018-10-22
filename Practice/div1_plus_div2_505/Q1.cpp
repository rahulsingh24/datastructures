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
    int n;
    cin>>n;

    string s;
    cin>>s;

    // if(n==1) cout<<"Yes"<<endl;

    int al[26];
    for(int i=0;i<26;i++) al[i]=0;
    for(int i=0;i<n;i++) {
        al[s[i]-'a']++;
    }

    for(int i=0;i<26;i++) {
        if(al[i]==n) {
            cout<<"Yes"<<endl;
            return 0;
        }
    }

    int check=0;
    for(int i=0;i<26;i++) {
        if(al[i]>1) {
            check=1;
            break;
        }
    }

    if(check) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
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


//see use of them
// #include <forward_list>
// #include <iomanip>

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;

        string s;
        cin>>s;

        if(n%2==0) {
            char t;
            for(int i=0;i<n-1;i+=2) {
                t = s[i+1];
                s[i+1] = s[i];
                s[i] = t;
            }
        } else {
            char t;
            for(int i=0;i<n-2;i=i+2) {
                t = s[i+1];
                s[i+1] = s[i];
                s[i] = t;
            }
        }

        // cout<<s<<endl;

        bool check[n];
        memset(check,false,n);

        char y;
        int m,k;
        for(int i=0;i<26;i++) {
            for(int j=0;j<n;j++) {
                y = 'a'+i;
                // cout<<(char)y<<endl;
                if(s[j]==y && !check[j]){
                    m = 'z'+1;
                    k = 'a'+i;
                    k = m-k;
                    s[j] = (char)k+'a'-1;
                     // cout<<s[i]<<endl;
                    check[j] = true;
                }
            }
        }

        cout<<s<<endl;
    }
}
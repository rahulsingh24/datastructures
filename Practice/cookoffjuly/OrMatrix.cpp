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
        int n,m;
        cin>>n>>m;

        string mat[n];

        int row[n], col[m];
        setv(row,0);
        setv(col,0);

        for(int i=0;i<n;i++) {
           cin>>mat[i];
        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(mat[i][j]=='1'){
                    row[i]=1;
                    break;
                }
            }
        }

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(mat[j][i]=='1'){
                    col[i]=1;
                    break;
                }
            }
        }

        bool check=false;
        for(int i=0;i<n;i++){
            if(row[i])
            {
                check=true;
                break;
            }
        }

        for(int i=0;i<m;i++){
            if(col[i])
            {
                check=true;
                break;
            }
        }

        if(check==false){
           for(int i=0;i<n;i++) {
                for(int j=0;j<m;j++) {
                    cout<<-1<<" "; 
                }
                cout<<endl;
             }

             continue;
        }

        int answer[n][m];
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                answer[i][j]=0; 
            }
        }


        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if((row[i] && mat[i][j]=='0') || (col[j] && mat[i][j]=='0')) {
                    answer[i][j]=1;
                    continue;
                }
                if(row[i]==0 && col[j]==0 && mat[i][j]=='0'){
                    answer[i][j]=2;
                }
            } 
        }

        // for(int i=0;i<m;i++) {
        //     if(col[i]) {
        //         for(int j=0;j<n;j++) {
        //             if(mat[i][j]=='0') {
        //                 answer[i][j]=1;
        //             }
        //          }
        //     } 
        // }

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                cout<<answer[i][j]<<" "; 
            }
            cout<<endl;
        }
        
    }
}
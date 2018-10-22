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
        int n,k;
        cin>>n>>k;

        int x;
        vector<int> v, a;
        for(int i=0;i<n;i++) {
            cin>>x;
            v.pb(x);
            a.pb(x);
        }

        sort(all(v));
        sort(all(a));

        vector<int>::iterator itt;
        itt = unique (v.begin(), v.end());   
        v.resize(distance(v.begin(),itt));

        if(v.size()>=k){
            cout<<-1<<endl;
            continue;
        }

        map<int,int> m;
        x = -1;
        int y=-1;
        for(int i=0;i<k;i++) {
            m[a[i]]++;
            if(x==-1) {
                if(m[a[i]]>=2) {
                    x=a[i];
                    m[a[i]]-=2;
                    continue;
                }
            }
            if(y==-1) {
                if(m[a[i]]>=2){
                    y=a[i];
                    // break;
                }
            }
        }

        if(x==-1 || y==-1)
        {
            // cout<<"dhanraj"<<endl;
            cout<<-1<<endl;
            continue;
        }
        m[x] = m[x]+2;

        // cout<<m[x]<<endl;

        long long int answer = (long long int)x*y;

        map<int,int>::iterator it;
        bool check=false;
        for(int i=k;i<n;i++) {
            m[a[i-k]]--;
            if(m[a[i-k]]==0) {
                m.erase(a[i-k]);
            }
            m[a[i]]++;
            x=-1,y=-1;
            // for(it=m.begin();it!=m.end();it++) {
            //     cout<<it->first<<" "<<it->second<<endl;
            // }
            // cout<<"dhanraj"<<endl;

            for(it=m.begin();it!=m.end();it++) {
                if(x==-1) {
                    if(it->second>=2) {
                        x = it->first;
                        it->second=it->second-2;
                        // continue;
                     }
                }
                if(y==-1) {
                    if(it->second>=2) {
                        y = it->first;
                        break;
                    }
                }
                // cout<<it->first<<" "<<it->second<<endl;
            }

            if(x==-1 || y==-1) {
                // cout<<"i = "<<i<<endl;
                check=true;
                break;
            }

            m[x] = m[x]+2;
        }

        if(check) {
            cout<<-1<<endl;
        } else  {
            cout<<answer<<endl;
        }
    }
}
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

        int x,y;
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

        int un= v.size();

        map<int,int> m;
        map<int,int>::iterator it;
        for(int i=0;i<n;i++) {
            m[a[i]]++;
        }

        

        for(it=m.begin();it!=m.end();it++) {
            m[it->first]--;
            /*if(m[it->first]==0) {
                m.erase(it->first);
            }*/
        }
         for(it=m.begin();it!=m.end();it++) {
            if(m[it->first]==0) {
                m.erase(it->first);
            }
        }

       /* for(it=m.begin();it!=m.end();it++) {
            cout<<"it->first = "<<it->first<<" "<<m[it->first]<<endl;
        }

        cout<<"__--------------"<<endl;
*/
        k = k-un;

        x=-1,y=-1;
        it = m.begin();
        bool check=false;
        while(k>0 && it!=m.end()) {
            // cout<<"it->first = "<<it->first<<" "<<m[it->first]<<endl;
            if(m[it->first]>=2) {
                if(m[it->first]==2) {
                    if(it->first>x) {
                        // cout<<"it->first = "<<it->first<<" "<<x<<" "<<y<<" "<<k<<endl;
                        y = x;
                        x = it->first;
                        k-=2;
                        it++;

                    }
                } else if(m[it->first]>2) {
                    if(it->first>x) {
                        y = x;
                        x = it->first;
                        k-=2;
                        // it++;
                        m[it->first]-=2;
                    }
                    if(k<=0) break;
                    y=x=it->first;
                    k-=m[it->first];
                    it++;
                }
            } else {
                if(it->first>x) {
                    y = x;
                    x = it->first;
                    k--;
                    it++;
                }
            }
        }

        cout<<x<<" "<<y<<endl;

        if(x==-1 || y==-1) {
            cout<<-1<<endl;
        } else {
            cout<<(ll)(x*1ll*y)<<endl;
        }
    }
}
#include <bits/stdc++.h>
using namespace std;

int T;
int n,k;
int sm_n=0;
map<int,int> mp;
int h;
pair<int,int> arr[100100];
int sm[100100];
int m;
map<int,int>::iterator ii;
int main(){
    cin>>T;
    while(T--){
        mp.clear();
        cin>>n;
        
        cin>>k;
        k=n-k; // instead of selecting K sticks, we remove n-k sticks
        for(int i=0;i<n-1;i++){
           cin>>h;
            mp[h]++; // keep frequencies of sticks in a map
        }
        cin>>h;
        mp[h]++;
        m=1;
        for(ii=mp.begin();ii!=mp.end();ii++){
            if(ii->second > 1){
                arr[m++] = *ii; 
            }
        }
        m--;
        int req=0;
        int mxx=0;
        for(int i=1;i<=m;i++){
            sm[i] = sm[i-1] + arr[i].second; // prefix sum of frequencies, we gonna need that
            if(arr[i].second > 1){
                req += arr[i].second -1;
                mxx = max ( arr[i].second -1,mxx);
            }
        }
        if (req -min(mxx,2)<= k){ // condition to tell if we can prevent having any rectangle
            cout<<-1<<endl;
            continue;
        }
        long long ans=1ll<<60;
        for(int i=m;i>=1;i--){   // go through sticks from tallest to smallest
            if(arr[i].second > 3){ // if we leave more than 3 sticks of currently tallest stick then answer is immediately  arr[i].first * 1ll *arr[i].first
                if(arr[i].second - 3 > k){
                    ans = min(ans, arr[i].first * 1ll *arr[i].first);
                    break;
                } 
                k -= arr[i].second  - 3;
                arr[i].second= 3;
            }
            if(arr[i].second  == 3){ // if there are  3 sticks we don't know whether we should remove 2 sticks or not, sometimes first option is optimal sometimes second
                int l=1,r=i; // so if we decided to leave 3 sticks then Chef's brother clear will take 2 of them for first dimension of rectangle
                while(r-l>1){ // now we have to minimize the second dimension
                    int mid=(r+l)/2;
                    if(sm[i-1] - sm[mid-1] - (i-mid) > k){
                        l=mid;
                    } else {
                        r=mid;
                    }
                }
                ans = min(ans,arr[i].first * 1ll * arr[l].first);
            }
            if(arr[i].second > 1){ // if there are more than 1 stick we have to take them
                if(arr[i].second - 1 > k){ // if we can't take them then we minimize the second dimension
                    for(int j=i-1;j>=1;j--){
                        if(arr[j].second - 1 > k){
                            ans = min (ans, arr[j].first * 1ll * arr[i].first);
                            break;
                        }
                        k -= arr[j].second - 1;
                    }
                    break;
                } 
                k -= arr[i].second  - 1; // if we can take them we try this option
                arr[i].second = 1;
            }
        }
        cout<<ans<<endl;
    }
    assert(getchar()==-1);
}
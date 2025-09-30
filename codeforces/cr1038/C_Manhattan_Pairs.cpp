#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define F first
#define S second
const ll mod = 1e9+7;

ll findmaxsum(vector<pair<int,int>> &arr) {
    int n = arr.size();
    sort(all(arr));
    ll ans = accumulate(arr.begin()+n/2,arr.end(),0ll,[&](const auto &a, const auto &b){return a+b.F;});
    ans-=accumulate(arr.begin(),arr.begin()+n/2,0ll,[&](const auto &a, const auto &b){return a+b.F;});
    sort(all(arr),[&](const auto &a,const auto &b){return a.S<b.S;});
    ans+=accumulate(arr.begin()+n/2,arr.end(),0ll,[&](const auto &a, const auto &b){return a+b.S;});
    ans-=accumulate(arr.begin(),arr.begin()+n/2,0ll,[&](const auto &a, const auto &b){return a+b.S;});
    return ans;
}

void solve() {
	int n;
    cin >> n;
    vector<pair<int,int>> arr(n);
    for(int i=0;i<n;i++) {
        cin >> arr[i].F >> arr[i].S;
    }
    cout << findmaxsum(arr) << "\n"
    

}


int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}

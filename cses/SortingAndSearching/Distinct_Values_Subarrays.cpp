#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define F first
#define S second


void solve() {
	int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    multiset<int,greater<int>> ss;
    map<int,int> freq;
    int i=0,j=0;
    ll ans = 0;
    while(j<n) {
        if (auto itr = ss.find(freq[arr[j]]);itr!=ss.end())
            ss.erase(itr);
        freq[arr[j]]++;
        ss.insert(freq[arr[j]]);
        while(i<n && (*ss.begin())>1) {
            if (auto itr = ss.find(freq[arr[i]]);itr!=ss.end())
                ss.erase(itr);
            freq[arr[i]]--;
            ss.insert(freq[arr[i]]);
            i++;
        }
        j++;
        ans+=j-i;
    }
    cout << ans << "\n";

}


int main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}

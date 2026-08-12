#include <bits/stdc++.h>

using namespace std;

#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define F first
#define S second

template <typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
using ll = long long;
using pii = pair<int,int>;



void solve() {
	int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    vector<ll>psum(n);
    psum[0]=arr[0];
    for(int i=1;i<n;i++) {
        psum[i]=psum[i-1]+arr[i];
    }
    vector<ll> ans(n);
    ans[0]=arr[0];
    for(int i=1;i<n;i++) {
        ans[i]=min(ans[i-1],psum[i]/(i+1));
    }
    for(int i=0;i<n;i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";


}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while(t--) {
    	solve();
    }
    
    return 0;
}

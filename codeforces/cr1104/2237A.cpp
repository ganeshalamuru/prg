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
    int ans = 0;
    while (arr.size()>0) {
        int minval = INT_MAX, minind =-1;
        int sz = int(arr.size());
        for(int i=0;i<sz;i++) {
            if (arr[i] < minval) {
                minval = arr[i];
                minind = i;
            }
        }
        ans += minval*(sz-minind);
        while (int(arr.size())>minind) {
            arr.pop_back();
        }
    }
    cout << ans << "\n";


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

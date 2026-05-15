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
    array<int,101>numfreq{};
    for(int i=0;i<n;i++) {
        cin >> arr[i];
        numfreq[arr[i]]++;
    }
    for(int i=1;i<101;i++) {
        if (numfreq[i]>1) {
            cout << -1 << "\n";
            return;
        }
    }
    sort(rall(arr));
    for(int i=0;i<n;i++) {
        cout << arr[i] << " ";
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

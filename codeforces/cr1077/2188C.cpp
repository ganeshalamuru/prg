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
    for(int &num:arr)
        cin >> num;
    bool sorted = true;
    for(int i=1;i<n;i++) {
        if (arr[i-1]>arr[i]) {
            sorted = false;
            break;
        }
    }
    if (sorted) {
        cout << -1 << "\n";
        return;
    }
    vector<int> sarr(arr);
    sort(all(sarr));
    int mindis = INT_MAX;
    for(int i=0;i<n;i++) {
        if (arr[i]==sarr[i])
            continue;
        mindis = min(mindis,max(sarr[n-1]-arr[i],arr[i]-sarr[0]));
    }
    cout << mindis << "\n";
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

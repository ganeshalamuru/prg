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
    vector<ll>arr(n);
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    for(int i=0;i<n-1;i++){
        if (arr[i]>arr[i+1]) {
            swap(arr[i],arr[i+1]);
            arr[i+1]+=arr[i];
        }
    }
    cout << arr[n-1] << "\n";

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

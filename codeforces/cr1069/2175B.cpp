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
	int n,l,r;
    cin >> n >> l >> r;
    vector<int> arr(n+1);
    int curxor = 0;
    for(int i=1;i<=n;i++) {
        if (i==r) {
            arr[i]=curxor^(l-1);
        } else {
            arr[i]=curxor^i;
        }
        curxor^=arr[i];
    }
    for(int i=1;i<=n;i++) {
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

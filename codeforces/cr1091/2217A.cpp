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
	int n,k;
    cin >> n >> k;
    int sum = 0;
    for(int i=0,x;i<n;i++) {
        cin >> x;
        sum+=x;
    }
    if (sum%2 == 1) {
        cout << "YES\n";
    } else if ((k*n)%2 == 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }


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

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
	int n,x;
    cin >> n;
    vector<int> arr(n);
    for(int &num:arr)
        cin >> num;
    cin >> x;
    if (n==1) {
        if (arr[0]==x) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        return;
    }
    sort(all(arr));
    if (arr[0]<=x && x<=arr[n-1]) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";

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

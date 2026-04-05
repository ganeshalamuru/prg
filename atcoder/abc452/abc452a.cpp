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
	int m,d;
    cin >> m >> d;
    if (m==1 && d==7) {
        cout << "Yes\n";
    } else if (m==3 && d==3) {
        cout << "Yes\n";
    } else if (m==5 && d==5) {
        cout << "Yes\n";
    } else if (m==7 && d==7) {
        cout << "Yes\n";
    } else if (m==9 && d==9) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }


}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;

    while(t--) {
    	solve();
    }
    
    return 0;
}

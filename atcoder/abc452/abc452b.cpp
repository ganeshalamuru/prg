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
	int h,w;
    cin >> h >> w;
    vector<string> grid(h,string(w,'.'));
    for(int j=0;j<w;j++) {
        grid[0][j]=grid[h-1][j]='#';
    }
    for(int i=0;i<h;i++) {
        grid[i][0]=grid[i][w-1]='#';
    }
    for(auto &str:grid) {
        cout << str << "\n";
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

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
    string ans(n-1,'0');
    int mask = (1<<(n))-1;
    vector<int> vis((1<<n)+1);
    int cnt = 0;
    function<bool(int)> dfs = [&](int u) {
        vis[u]=1;
        ans.push_back(char('0'+ (u&1)));
        cnt++;
        if (cnt==(1<<n)) {
            return true;
        }
        int neigh0 = ((u<<1)|0)&mask,neigh1 = ((u<<1)|1)&mask; 
        if (neigh0!=u && vis[neigh0]==0 && dfs(neigh0)) {
            return true;
        } else if (neigh1!=u && vis[neigh1]==0 && dfs(neigh1)) {
            return true;
        }
        ans.pop_back();
        vis[u]=0;
        cnt--;
        return false;
    };
    dfs(0);
    cout << ans << "\n";
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

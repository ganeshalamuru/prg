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
    string s;
    cin >> s;
    int i=0;
    while(i<n && s[i]=='0') {
        i++;
    }
    if (i==n) {
        cout << (n+2)/3 << "\n";
        return;
    }
    int ans = (i+1)/3;
    while(i<n) {
        if (s[i]=='1') {
            i++;
            ans++;
            continue;
        }
        int cnt = 0;
        while (i<n && s[i]=='0') {
            cnt++,i++;
        }
        if (i==n) {
            ans+=(cnt+1)/3;
        } else {
            ans+=cnt/3;
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

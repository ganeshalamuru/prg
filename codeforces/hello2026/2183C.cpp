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
	int n,m,k;
    cin >> n >> m >> k;
    if (n==1) {
        cout << 1 << "\n";
        return;
    }
    if (k==1 || k==n) {
        cout <<  min((m+1)/2 + 1, n) << "\n";
    } else {
        int maxposts = min((m+1)/2+1,n-k+1);
        for(int i=1;i<=k-1;i++) {
            int usedm = 2*i-1;
            if (usedm<=m) {
                maxposts = max(maxposts,i+min(min((m-usedm+(usedm+1)/2)/2+1,m-usedm+1),n-k+1));
            }
        }
        maxposts = max(maxposts,min((m+1)/2+1,k));
        for(int i=k+1;i<=n;i++) {
            int usedm = 2*(i-k)-1;
            if (usedm<=m) {
                maxposts = max(maxposts,i-k+min(min((m-usedm+(usedm+1)/2)/2+1,m-usedm+1),k));
            }
        }
        cout << maxposts << "\n";
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

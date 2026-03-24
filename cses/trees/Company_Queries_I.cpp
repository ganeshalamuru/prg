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
	int n,q;
    cin >> n >> q;
    vector<vector<int>> dp(n+1,vector<int>(18,-1));
    for(int i=2;i<=n;i++) {
        cin >> dp[i][0];
    }
    for(int j=1;j<18;j++) {
        for(int i=1;i<=n;i++) {
            if (dp[i][j-1]!=-1)
                dp[i][j]=dp[dp[i][j-1]][j-1];
        }
    }
    while(q--) {
        int x,k;
        cin >> x >> k;
        int curpa = x,curk=k;
        while (curk>0 && curpa!=-1) {
            int hpow2 = int(bitset<18>((curk&-curk)-1).count()); 
            curpa=dp[curpa][hpow2];
            curk-=curk&-curk;
        }
        cout << curpa << "\n";
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

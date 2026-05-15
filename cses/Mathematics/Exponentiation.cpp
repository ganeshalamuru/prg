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


const int mod = 1e9+7;

int modexpo(int x,int n) {
    if (n==0)
        return 1;
    if (x==0)
        return 0;
    int ans = 1;
    while(n>0) {
        if (n&1)
            ans = int((1ll*ans*x)%mod);
        x = int((1ll*x*x)%mod);
        n>>=1;
    }
    return ans;
}

void solve() {
	int n;
    cin >> n;
    while (n--) {
        int a,b;
        cin >> a >> b;
        cout << modexpo(a,b) << "\n";
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

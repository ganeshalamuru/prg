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


vector<int> nums(1e6+1);
void solve() {
	int n;
    cin >> n;
    for(int i=1,x;i<=n;i++)
        cin >> x,nums[x]++;
    for(int i=1e6;i>=1;i--) {
        int cnt = 0;
        for(int j=i;j<=1e6;j+=i) {
            cnt+=nums[j];
            if (cnt>1) {
                cout << i << "\n";
                return;
            }
        }
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

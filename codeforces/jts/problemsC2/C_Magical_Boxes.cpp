#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define F first
#define S second
#define PB push_back
#define MP make_pair
const ll mod = 1e9+7, N = 2e6+7, M = 2e6+7, INF = INT_MAX/10;
ll powe(ll x, ll y){ x = x%mod, y=y%(mod-1);ll ans = 1;while(y>0){if (y&1){ans = (1ll * x * ans)%mod;}y>>=1;x = (1ll * x * x)%mod;}return ans;}


bool check_if_all_boxes_fit(vector<vector<int>> &inner_boxes, int outer_box_sz) {
    for(int i=0;i<inner_boxes.size();i++) {
        int inner_box_sz = inner_boxes[i][0], num_inner_boxes = inner_boxes[i][1];
        if (outer_box_sz < inner_box_sz)
            return false;
        int max_inner_boxes = 1<<min(30, abs(2*outer_box_sz - 2*inner_box_sz));
        if (num_inner_boxes > max_inner_boxes)
            return false;
    }
    return true;
}


void solve() {
	int n;
    cin >> n;
    vector<vector<int>> arr(n,vector<int>(2));
    int maxsz = INT_MIN;
    for(int i=0;i<n;i++)
        cin >> arr[i][0] >> arr[i][1], maxsz = max(maxsz, arr[i][0]);
    int l=maxsz+1, r=1e9+15;
    while(l<r) {
        int mid = l + (r-l)/2;
        if (check_if_all_boxes_fit(arr, mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l << "\n";
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}

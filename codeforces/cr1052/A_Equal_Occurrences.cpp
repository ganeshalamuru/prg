#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define F first
#define S second
const ll mod = 1e9+7;


void solve() {
	int n;
    cin >> n;
    vector<int> freq(n+1,0);
    for(int x,i=0;i<n;i++) {
        cin >> x;
        freq[x]++;
    }
    vector<int> nums;
    for(int i=1;i<n+1;i++) {
        if (freq[i]>0)
            nums.push_back(freq[i]);
    }
    sort(nums.rbegin(), nums.rend());
    int ans = INT_MIN;
    for(int i=0;i<nums.size();i++) {
        ans = max(ans, nums[i]*(i+1));
    }
    cout << ans << "\n";


}


int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}

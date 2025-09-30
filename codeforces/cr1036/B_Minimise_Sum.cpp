#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define F first
#define S second
const ll mod = 1e9+7;


void solve() {
	int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    vector<int> p(n);
    ll ans = arr[0]+arr[1];
    p[0]=arr[0];
    ll sum = arr[0];
    for(int i=1;i<n;i++) {
        p[i]=min(p[i-1],arr[i]);
        sum+=p[i];
        if (sum < ans)
            ans = sum;
    }
    bool cord = false;
    if (arr[0] <= arr[1]) {
        cord = true;
    }
    set<int>ss;
    ss.insert(arr[0]);
    ss.insert(arr[1]);
    sum = p[0]+p[1];
    int diff = arr[0]-arr[1];
    for(int i=2;i<n;i++) {
        if (cord) {
            ans = min(ans, sum);
        } else {
            ans = min(ans,sum+min(arr[i],diff));
        }
        if (arr[i]>=(*ss.begin())) {
            cord=true;
        } else if (!cord) {
            diff=min(diff,(*ss.begin())-arr[i]);
        }
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

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


int closestRightSideOne(vector<int> &ones, string &str, int l) {
    if (str[l] == '1') {
        return l;
    }
    int left = 0, right = ones.size() - 1;
    while(left < right) {
        int mid = left + (right - left) / 2;
        if (ones[mid] < l) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    if (ones.size() > 0 && ones[right] > l) {
        return ones[left];
    }
    return str.size();
}

int closestLeftSideZero(vector<int> &zeros, string &str, int r) {
    if (str[r] == '0') {
        return r;
    }
     int left = 0, right = zeros.size() - 1;
    while(left < right) {
        int mid = left + (right - left + 1) / 2;
        if (zeros[mid] > r) {
            right = mid - 1;
        } else {
            left = mid;
        }
    }
    if (zeros.size() > 0 && zeros[left] < r) {
        return zeros[left];
    }
    return -1;
}

void solve(){
	int n,m;
    cin >> n >> m;
    string str;
    cin >> str;
    vector<int> ones,zeros;
    for(int i=0;i<n;i++) {
        if (str[i] == '0') {
            zeros.push_back(i);
        } else {
            ones.push_back(i);
        }
    }
    set<pair<int,int>> unqrng;
    while(m--) {
        int l,r;
        cin >> l >> r; 
        l--,r--;
        pair<int, int> unqpr = make_pair(closestRightSideOne(ones, str, l), closestLeftSideZero(zeros, str, r));
        if (unqpr.first <= unqpr.second)
            unqrng.insert(unqpr);
        else 
            unqrng.insert(make_pair(-1, n));
    }
    cout << unqrng.size() << endl;
}


signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}

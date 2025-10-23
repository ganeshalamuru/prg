#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define F first
#define S second
const int mod = 1e9+7;
const int N = 2e5+1;
// bit[i] = number of increasing seq ending with i
vector<int> bit(N,0);

void inc(int i, int v) {
    while(i<N) {
        bit[i]=(bit[i]+v)%mod;
        i+=(i&(-i));
    }
}

int sum(int i) {
    int ans = 0;
    while(i>0) {
        ans = (ans+bit[i])%mod;
        i-=(i&(-i));
    }
    return ans;
}

void solve() {
	int n;
    cin >> n;
    set<int> ss;
    vector<int> arr(n);
    for(int &x:arr)
        cin >> x,ss.insert(x);
    map<int,int> mp;
    for(int num=1;auto &distnum:ss)
        mp[distnum]=num,num++;
    for(int i=0;i<n;i++)
        arr[i]=mp[arr[i]];
    for(int i=0;i<n;i++) {
        int pvseqs = sum(arr[i]-1);
        inc(arr[i],(pvseqs+1)%mod);
    }
    cout << sum(N-1) << "\n";

}


int main() {
    fast;
    int t = 1;
    //cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}

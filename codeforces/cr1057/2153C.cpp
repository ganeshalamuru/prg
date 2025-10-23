#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define F first
#define S second


void solve() {
	int n;
    cin >> n;
    map<int,int> freq;
    for(int i=0,x;i<n;i++) {
        cin >> x;
        freq[x]++;
    }
    // point, point
    ll ppsum = 0, numsides = 0;
    set<ll> ss;
    for(auto [num,cnt]:freq) {
        ppsum+=1ll*num*(cnt-(cnt%2));
        numsides+=cnt-(cnt%2);
        if (cnt%2==1) {
            ss.insert(num);
        }
    }
    if (numsides==0) {
        cout << 0 << "\n";
    } else {
        ll ans = ppsum;
        auto itr3 = ss.upper_bound(ppsum-1);
        if (itr3!=ss.begin()) {
            itr3--;
            ans = max(ans, ppsum+(*itr3));
        }
        for(auto itr=ss.begin();itr!=ss.end();itr++) {
            if ((*itr)==(*ss.rbegin())) {
                break;
            }
            auto itr2 = ss.upper_bound(ppsum+(*itr)-1);
            if (itr2!=ss.begin()) {
                itr2--;
                if ((*itr2)>(*itr))
                    ans = max(ans, ppsum+(*itr)+(*itr2));
            }
        }
        if (numsides==2 && ans==ppsum) {
            cout << 0 << "\n";
        } else {
            cout << ans << "\n";
        }
    }
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

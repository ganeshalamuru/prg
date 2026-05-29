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


ll findabsdiff(ll mid, ll a,ll d1, ll d2) {
    bitset<20>bs(mid);
    int j=19;
    while (bs[j]==0)
        j--;
    j--;
    ll midval = 0;
    while (j>=0) {
        if (bs[j]==1)
            midval=midval*10+d2;
        else
            midval=midval*10+d1;
        j--;
    }
    // cout << "midval " << midval << "\n";
    return abs(a-midval);
}

void solve() {
	ll a,n,d1,d2;
    cin >> a >> n;
    cin >> d1 >> d2;
    ll l=2,r=(1<<20)-1;
    while (l<r) {
        ll mid = l+(r-l)/2;
        ll f_mid = findabsdiff(mid,a,d1,d2);
        ll f_midp1 = findabsdiff(mid+1,a,d1,d2);
        // cout << "l " << " r" << l << " " << r << " " << f_mid << " " << f_midp1 << "\n"<<flush;
        if (f_midp1<f_mid) {
            l=mid+1;
        } else if (f_midp1 == f_mid) {
            cout << f_mid << "\n";
            return;
        } else {
            r=mid;
        }
    }
    cout << findabsdiff(l,a,d1,d2) << "\n" << flush;
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

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
	int n;
    cin >> n;
    vector<int> freq(2*n+1,0);
    for(int i=0,x;i<2*n;i++) {
        cin >> x;
        freq[x]++;
    }
    int evnevn = 0;
    int ans = 0, maxoddfreq = -1;
    for(int i=1;i<=2*n;i++) {
        if (freq[i]==0)
            continue;
        if (freq[i]%2 == 0) {
            if ((freq[i]/2)%2 == 1)
                ans+=2;
            else
                evnevn++;
        } else {
            maxoddfreq = max(maxoddfreq, freq[i]);
            ans++;
        }
    }
    if (evnevn%2==0 || maxoddfreq>0) {
        ans+=2*evnevn;
    } else {
        ans+=2*(evnevn-1);
    }
    cout << ans << "\n";


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

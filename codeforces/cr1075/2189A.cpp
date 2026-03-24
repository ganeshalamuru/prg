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
	int n,h,l;
    cin >> n >> h >> l;
    vector<int> freq(1001,0);
    for(int i=0,x;i<n;i++) {
        cin >> x;
        freq[x]++;
    }
    int ans = 0;
    for(int i=h;i>=1;i--) {
        for(int j=l;j>=1;j--) {
            if (i==j) {
                while (freq[i]>1) {
                    ans++;
                    freq[i]-=2;
                }
            } else {
                while (freq[i]>0 && freq[j]>0) {
                    ans++;
                    freq[i]--;
                    freq[j]--; 
                }
            }
        }
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

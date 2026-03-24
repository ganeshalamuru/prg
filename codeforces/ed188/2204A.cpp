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
    string s;
    cin >> s;
    vector<int> ballrecv(n,0);
    ballrecv[0]=1;
    int i=0,times=n;
    while (times--) {
        if (s[i]=='R') {
            i++;
        } else {
            i--;
        }
        ballrecv[i]=1;
    }
    cout << accumulate(all(ballrecv),0) << "\n";
    


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

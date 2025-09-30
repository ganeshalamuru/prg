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
	int n,a,b;
    cin >> n >> a >> b;
    if (a+b>n) {
        cout << "NO\n";
        return;
    }
    vector<vector<int>> plays(2);
    int diff=n-(a+b);
    while(diff>0) {
        plays[0].push_back(n);
        plays[1].push_back(n);
        n--,diff--;
    }
    if ((a==0 && b!=0) || (a!=0 && b==0)) {
        cout << "NO\n";
        return;
    }
    for(int i=1,j=a+1;i<=n;i++,j=(j%n)+1) {
        plays[0].push_back(i);
        plays[1].push_back(j);
    }
    cout << "YES\n";
    for(auto &cards:plays) {
        for(auto& card:cards) {
            cout << card << " ";
        }
        cout << "\n";
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

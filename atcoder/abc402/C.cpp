#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define all(v) (v).begin(),(v).end()
#define F first
#define S second
const ll mod = 1e9+7;


void solve() {
    int n,m;
    cin >> n >> m;
    vector<set<int>>dishes(m);
    vector<vector<int>>ingdishes(n);
    for(int i=0;i<m;i++) {
        int k;
        cin >> k;
        for(int j=0,ing;j<k;j++) {
            cin >> ing;
            ing--;
            dishes[i].insert(ing);
            ingdishes[ing].push_back(i);
        }
    }
    int ans = 0;
    for(int i=0,ing;i<n;i++) {
        cin >> ing;
        ing--;
        for(int &dish:ingdishes[ing]) {
            dishes[dish].erase(ing);
            if (dishes[dish].empty()) {
                ans++;
            }
        }
        cout << ans << "\n";
    }
}
int main() {
    fast;
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
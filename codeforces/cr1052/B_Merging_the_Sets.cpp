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
	int n,m;
    cin >> n >> m;
    vector<int> freq(m+1,0);
    vector<vector<int>> arr;
    for(int i=0,setsz;i<n;i++) {
        cin >> setsz;
        vector<int> tmp(setsz);
        for(int j=0;j<setsz;j++) {
            cin >> tmp[j];
            freq[tmp[j]]++;
        }
        arr.push_back(tmp);
    }
    if (n==2) {
        for(int i=1;i<=m;i++) {
            if (freq[i]!=2) {
                cout << "NO\n";
                return;
            }
        }
        cout << "YES\n";
        return;
    }
    bool allpres = true;
    for(int i=1;i<=m;i++) {
        if (freq[i]<1) {
            allpres=false;
            break;
        }
    }
    if (!allpres) {
        cout << "NO\n";
        return;
    }
    int cnt = 0;
    for(int i=0;i<arr.size();i++) {
        bool alldupes = true;
        for(int j=0;j<arr[i].size();j++) {
            if (freq[arr[i][j]]==1) {
                alldupes=false;
                break;
            }
        }
        if (alldupes)
            cnt++;
    }
    if (cnt>1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define F first
#define S second
const ll mod = 1e9+7;


void solve() {
	int n;
    cin >> n;
    vector<int>arr(n);
    map<int,int>freq;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
        freq[arr[i]]++;
    }
    for(auto &pp:freq) {
        if (pp.second>=4) {
            cout << "Yes\n";
            return;
        }
    }
    auto itr = freq.begin();
    while(itr!=freq.end()) {
        if (itr->second==1) {
            itr++;
            continue;
        }
        int num = itr->first;
        itr++;
        while (itr->first==num+1 && itr->second>=1) {
            if (itr->second>1) {
                cout << "Yes\n";
                return;
            }
            num++,itr++;
        }
    }
    cout << "No\n";
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

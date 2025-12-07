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
    string s,t;
    cin >> s >> t;
    int ssz = int(s.size());
    vector<int> freqt(26,0),freqs(26,0);
    for(char ch:t) {
        freqt[ch-'a']++;
    }
    for(char ch:s) {
        freqs[ch-'a']++;
    }
    multiset<char> mst;
    for(int j=0;j<26;j++) {
        if (freqt[j]<freqs[j]) {
            cout << "Impossible\n";
            return;
        }
        freqt[j]-=freqs[j];
        while (freqt[j]>0) {
            mst.insert(char('a'+j));
            freqt[j]--;
        }
    }
    int i=0;
    string ans;
    while(!mst.empty() && i<ssz) {
        auto itr = mst.begin();
        if ((*itr)<s[i]) {
            ans.push_back(*itr);
            mst.erase(itr);
        } else {
            ans.push_back(s[i]);
            i++;
        }
    }
    while(!mst.empty()) {
        auto itr = mst.begin();
        ans.push_back(*itr);
        mst.erase(itr);
    }
    while(i<ssz) {
        ans.push_back(s[i]);
        i++;
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

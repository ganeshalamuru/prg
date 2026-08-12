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
	int n,k;
    cin >> n >> k;
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++) {
        cin >> arr[i];
    }
    auto cmp = [](const pii& a, const pii& b) {
        if (a.F==b.F)
            return a.S < b.S;
        return a.F>b.F;
    };
    set<pii,decltype(cmp)> ss;
    map<int,int> freq;
    for(int i=1;i<k;i++) {
        freq[arr[i]]++;
    }
    for(auto [val,cnt]:freq) {
        ss.insert({cnt,val});
    }
    for(int i=k;i<=n;i++) {
        if (auto itr = ss.find({freq[arr[i]],arr[i]});itr!=ss.end())
            ss.erase(itr);
        freq[arr[i]]++;
        ss.insert({freq[arr[i]],arr[i]});
        cout << ss.begin()->S << " ";
        int leftendval = arr[i-k+1];
        if (auto itr = ss.find({freq[leftendval],leftendval});itr!=ss.end())
            ss.erase(itr);
        freq[leftendval]--;
        ss.insert({freq[leftendval],leftendval});
    }
    cout << "\n";

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;

    while(t--) {
    	solve();
    }
    
    return 0;
}

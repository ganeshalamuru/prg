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
	int n,m,l;
    cin >> n >> m >> l;
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    multiset<int> ms;
    for(int i=0;i<min(m,n+1);i++) {
        ms.insert(0);
    }
    int i=0,tt=1;
    while (tt<=l) {
        auto itr = ms.begin();
        int val = *itr;
        ms.erase(itr);
        ms.insert(val+1);
        if (i<n && tt==arr[i]) {
            ms.erase(ms.find(*(ms.rbegin())));
            ms.insert(0);
            i++;
        }
        while (int(ms.size())>n-i+1){
            ms.erase(ms.find(*(ms.begin())));
        }
        tt++;
    }
    cout << *(ms.rbegin()) << "\n" << flush;

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

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
    int i = (n+1)/2,j=i+1;
    vector<int> arr;
    while(i>=1 && j<=n) {
        arr.push_back(i);
        arr.push_back(j);
        i--,j++;
    }
    if (i>=1)
        arr.push_back(1);
    for(int num:arr) {
        cout << num << " ";
    }
    cout << "\n";


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

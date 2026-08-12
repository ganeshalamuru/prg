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
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    for(int i=0;i<n;i++) {

        vector<int> pmax(n),suffmax(n);
        pmax[0]= arr[i];
        for(int j=1;j<n;j++) {
            pmax[j]=max(pmax[j-1],arr[(i+j)%n]);
        }
        suffmax[n-1]=arr[(i+n-1)%n];
        for(int j=n-2;j>=0;j--) {
            suffmax[j]=max(suffmax[j+1],arr[(i+j)%n]);
        }
        ll maxwater = 0;
        for(int j=i+1;j<i+n;j++) {
            maxwater+=min(pmax[j-i-1],suffmax[j-i]);
        }
        cout << maxwater << " ";
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

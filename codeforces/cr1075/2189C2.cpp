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
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++) {
        arr[i]=i;
    }
    if (n%2 == 1) {
        arr[1]=n-1,arr[n]=1,arr[n-1]=n;
        for(int i=2;i<n-1;i+=2) {
            swap(arr[i],arr[i+1]);
        }
        for(int i=1;i<=n;i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    } else if ((n&(n-1))==0) {
        cout << -1 << "\n";
    } else {
        swap(arr[1],arr[n]);
        for(int i=2;i<n;i+=2) {
            swap(arr[i],arr[i+1]);
        }
        int tmp = 2*(n&-n) - 1;
        swap(arr[1],arr[tmp]);
        for(int i=1;i<=n;i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }

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

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

vector<int> bit;
void update(int i,int val) {
    while (i<int(bit.size())) {
        bit[i]+=val;
        i+=(i&-i);
    }
}

int psum(int i) {
    int ans = 0;
    while (i>0) {
        ans+=bit[i];
        i-=(i&-i);
    }
    return ans;
}

int findsum(int sum) {
    int l=1,r=int(bit.size())-1;
    while (l<r) {
        int mid = l+(r-l)/2;
        int midsum = psum(mid);
        if (midsum>sum) {
            r=mid-1;
        } else if (midsum==sum){
            r=mid;
        } else {
            l=mid+1;
        }
    }
    return l;
}

void solve() {
	int n;
    cin >> n;
    vector<int> arr(n+1),queries(n+1);
    for(int i=1;i<=n;i++) {
        cin >> arr[i];
    }
    for(int i=1;i<=n;i++) {
        cin >> queries[i];
    }
    bit.resize(n+1);
    for(int i=1;i<=n;i++) {
        update(i,1);
    }
    for(int i=1;i<=n;i++) {
        int index = findsum(queries[i]);
        update(index,-1);
        cout << arr[index] << " ";
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

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

void update(int i, int val) {
    while (i<int(bit.size())) {
        bit[i]+=val;
        i+=(i&-i);
    }
}

int sum(int i) {
    int ans = 0;
    while (i>0) {
        ans+=bit[i];
        i-=(i&-i);
    }
    return ans;
}

int numgreater(int i) {
    return sum(int(bit.size())-1)-sum(i);
}

vector<int> vals;

int getnum(int val) {
    return int(distance(vals.begin(),lower_bound(all(vals),val)));
}

void solve() {
	int n,k;
    cin >> n >> k;
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++) {
        cin >> arr[i];
        vals.push_back(arr[i]);
    }
    vals.push_back(0);
    sort(all(vals));
    auto itr = unique(all(vals));
    vals.erase(itr,vals.end());

    bit.resize(vals.size());
    ll numinv = 0;
    for(int i=1;i<k;i++) {
        int num = getnum(arr[i]);
        update(num,1);
        numinv+=numgreater(num);
    }

    for(int i=k;i<=n;i++) {
        int num = getnum(arr[i]);
        update(num,1);
        numinv+=numgreater(num);
        cout << numinv << " ";
        int removenum = getnum(arr[i-k+1]);
        update(removenum,-1);
        numinv-=sum(removenum-1);
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

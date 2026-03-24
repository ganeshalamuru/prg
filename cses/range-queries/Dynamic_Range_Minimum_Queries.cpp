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


vector<int> sgtre;

void update(int i, int val) {
    i += int(sgtre.size())/2;
    sgtre[i]=val;
    int k = i/2;
    while(k>=1) {
        sgtre[k] = min(sgtre[2*k],sgtre[2*k+1]);
        k/=2;
    }
}

int find_min(int l, int r) {
    int ans = INT_MAX;
    l += int(sgtre.size())/2;
    r += int(sgtre.size())/2;
    while(l<=r) {
        if (l%2 == 1) ans = min(ans,sgtre[l++]);
        if (r%2 == 0) ans = min(ans,sgtre[r--]);
        l/=2,r/=2;
    }
    return ans;
}


void solve() {
	int n,q;
    cin >> n >> q;
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    int sgtresz = 0;
    for(int j=1;j<=30;j++) {
        if ((1<<j)>=n) {
            sgtresz = 1<<j;
            break;
        }
    }
    sgtresz<<=1;
    sgtre.resize(sgtresz, INT_MAX);
    for(int i=0;i<n;i++) {
        update(i,arr[i]);
    }
    while (q--) {
        int t,k,u,a,b;
        cin >> t;
        if (t == 1) {
            cin >> k >> u;
            k--;
            update(k,u);
        } else {
            cin >> a >> b;
            a--,b--;
            cout << find_min(a,b) << "\n";
        }
    }
    

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

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

vector<int>bit;

void update(int i) {
    while(i<int(bit.size())) {
        bit[i]++;
        i += (i&-i);
    }
}

int sum(int l, int r) {
    int ans = 0;
    while(r>0) {
        ans+=bit[r];
        r-=(r&-r);
    }
    l--;
    while(l>0) {
        ans-=bit[l];
        l-=(l&-l);
    }
    return ans;
}


void solve(int n, vector<pii> arr) {

    sort(all(arr));
    bit.resize(n+1);
    ll ans = 0;
    for(int i=0;i<n;i++) {
        int ind = arr[i].S;
        update(ind);
        ll curans = 1ll*sum(1,ind)*sum(ind,n);
        // cout << "ind " << ind << "\n";
        // for(int j=1;j<=n;j++) {
        //     cout << sum(j,j) << " ";
        // }
        // cout << "\n";
        // cout << sum(1,ind) << " " <<sum(ind,n) << " " << curans << "\n";
        ans+=curans;
    }
    cout << ans << "\n";

}

void solve2(int n, vector<pii> arr) {
    set<set<int>> ss;
    for(int l=0;l<n;l++) {
        vector<pii> tmp2;
        for(int r=l;r<n;r++) {
            tmp2.push_back(arr[r]);
            sort(rall(tmp2));
            set<int> inds;
            for(int z=0;z<int(tmp2.size());z++) {
                inds.insert(tmp2[z].S);
                ss.insert(inds);
            }
        }
    }
    cout << ss.size() << "\n";
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;

    while(t--) {
        int n;
        cin >> n;
        vector<pii> arr(n);
        for(int i=0;i<n;i++) {
            cin >> arr[i].F;
            arr[i].S=i+1;
        }
    	solve(n,arr);
        // solve2(n,arr);
    }
    
    return 0;
}

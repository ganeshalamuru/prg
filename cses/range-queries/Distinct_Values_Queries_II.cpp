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
 
vector<int> sgtree;
int sgtreebasesz = 1;
 
 
void update(int i, int val) {
    i+=sgtreebasesz;
    sgtree[i]=val;
    i/=2;
    while (i>0) {
        sgtree[i]=min(sgtree[2*i],sgtree[2*i+1]);
        i/=2;
    }
 
}
 
int query(int a, int b) {
    a += sgtreebasesz;
    b += sgtreebasesz;
    int ans = INT_MAX;
    while (a<=b) {
        if (a%2 == 1) ans = min(ans, sgtree[a++]);
        if (b%2 == 0) ans = min(ans, sgtree[b--]);
        a/=2,b/=2;
    }
    return ans;
}
 
 
vector<set<int>> valinds;
vector<int> vals;
int getmappednum(int val) {
    return int(distance(vals.begin(), lower_bound(all(vals),val)));
}
void solve() {
	int n,q;
    cin >> n >> q;
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin >> arr[i];
        vals.push_back(arr[i]);
    }
    vector<array<int,3>> queries(q);
    for(int i=0;i<q;i++) {
        cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
        if (queries[i][0]==1)
            vals.push_back(queries[i][2]);
    }
    sort(all(vals));
    vals.erase(unique(all(vals)),vals.end());
    valinds.resize(vals.size());
    for(int i=0;i<n;i++) {
        arr[i]=getmappednum(arr[i]);
        valinds[arr[i]].insert(i);
    }
    for(auto &[typ,a,b]:queries) {
        a--;
        if (typ==1) {
            b=getmappednum(b);
        } else {
            b--;
        }
    }

    while (sgtreebasesz<n) {
        sgtreebasesz<<=1;
    }
    sgtree.resize(sgtreebasesz<<1);
    for(auto &pp:valinds) {
        if (pp.empty())
            continue;
        int prev = *pp.begin();
        auto itr = ++pp.begin();
        while (itr!=pp.end()) {
            update(prev,*itr);
            prev = *itr;
            itr++;
        }
        update(prev, n);
    }
    // cout << "sgtree done\n" << flush;
    for(auto &[typ,a,b]:queries) {
        // cout << "q " << i << "\n" << flush;
        if (typ == 1) {
            if (arr[a]==b) continue;
            auto &valarr = valinds[arr[a]]; 
            auto itr = valarr.lower_bound(a);
            if (itr != valarr.begin()) {
                update(*(--itr),query(a,a));
            }
            valarr.erase(a);
            // cout << "remove prev\n" << flush;
            arr[a]=b;
            auto &valarr2 = valinds[arr[a]];
            valarr2.insert(a);
            itr = valarr2.lower_bound(a);
            auto nitr = next(itr);
            int nxtind = n;
            if (nitr!=valarr2.end())
                nxtind = *nitr;
            // cout << "updated nxtind\n" << flush;
            update(a,nxtind);
            if (itr != valarr2.begin()) {
                itr--;
                update(*itr,a);
            }
            // cout << "updated prev to new\n" << flush;
        } else {
            int minnxtind = query(a,b);
            if (minnxtind>b) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
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
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


vector<int> vals;
vector<int> bit;

void increment(int i) {
    while (i<int(bit.size())) {
        bit[i]++;
        i+=(i&-i);
    }
}

int sum(int a) {
    int ans = 0;
    while (a>0) {
        ans+=bit[a];
        a-=(a&-a);
    }
    return ans;
}

int getmappednum(int i) {
    return int(distance(vals.begin(),lower_bound(all(vals),i)))+1;
}

void solve() {
	int n,q;
    cin >> n >> q;
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin >> arr[i];
        vals.push_back(arr[i]);
    }
    // ans = #(i<=b && x_i<=d) - #(i<=a-1 && x_i<=d) 
    //       - ( #(i<=b && x_i<=c-1) - #(i<=a-1 && x_i<=c-1) )
    vector<array<int,4>> intmdqueries;  
    for(int i=0,a,b,c,d;i<q;i++) {
        cin >> a >> b >> c >> d;
        a--,b--;
        vals.push_back(c-1);
        vals.push_back(d);
        intmdqueries.push_back({b,d,1,i});
        intmdqueries.push_back({b,c-1,-1,i});
        if (a-1>=0) {
            intmdqueries.push_back({a-1,d,-1,i});
            intmdqueries.push_back({a-1,c-1,1,i});
        }
    }
    sort(all(vals));
    sort(all(intmdqueries));
    vals.erase(unique(all(vals)),vals.end());
    vector<int> ans(q);
    bit.resize(int(vals.size())+1);
    for(int i=0,j=0;i<n;i++) {
        increment(getmappednum(arr[i]));
        while (j<int(intmdqueries.size()) && intmdqueries[j][0]<=i) {
            auto [endind,val,op,qind]=intmdqueries[j];
            ans[qind]+=op*sum(getmappednum(val));
            j++;
        }
    }
    for(int i=0;i<q;i++) {
        cout << ans[i] << "\n";
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

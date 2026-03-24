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
    while(i<int(bit.size())) {
        bit[i]+=val;
        i+=(i&(-i));
    }
}
int sum(int i) {
    int ans = 0;
    while (i>0) {
        ans+=bit[i];
        i-=(i&(-i));
    }
    return ans;
}

int sum(int i,int j) {
    return sum(j)-sum(i-1);
}
vector<int> vals;

int mappedind(int val) {
    return int(distance(vals.begin(),lower_bound(all(vals),val))) + 1;
}
void solve() {
	int n,q;
    cin >> n >> q;
    vector<int> salaries(n);
    set<int> ss;
    for(int i=0;i<n;i++){
        cin >> salaries[i];
        vals.push_back(salaries[i]);
    }
    vector<array<int,3>> queries(q);
    for(int i=0,a,b;i<q;i++) {
        char ch;
        cin >> ch >> a >> b;
        queries[i] = array<int,3>{ch=='?'?0:1,a,b};
        if (queries[i][0]==0) {
            vals.push_back(a);
            vals.push_back(b);
        } else if (queries[i][0]==1) {
            vals.push_back(b);
        }
    }
    sort(all(vals));
    vals.erase(unique(all(vals)),vals.end());
    bit.resize(int(vals.size())+1);
    for(int i=0;i<n;i++) {
        update(mappedind(salaries[i]),1);
    }
    for(auto [type,a,b]:queries) {
        // cout << "qq\n";
        if (type==1) {
            a--;
            update(mappedind(salaries[a]),-1);
            salaries[a]=b;
            update(mappedind(salaries[a]),1);
        } else {
            cout << sum(mappedind(a), mappedind(b)) << "\n";
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

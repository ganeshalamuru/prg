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


int calculatemaxseated(int firstambitointrovert, string &str, int x, int s) {
    int nonfullindex = 0;
    vector<int> tables;
    for(auto &ch:str) {
        if (ch=='I' || (ch=='A' && firstambitointrovert>0)) {
            if (int(tables.size())<x) {
                tables.push_back(1);
            }
            if (ch=='A')
                firstambitointrovert--;
        } else {
            while (nonfullindex<int(tables.size()) && tables[nonfullindex]==s)
                nonfullindex++;
            if (nonfullindex<int(tables.size())) {
                tables[nonfullindex]++;
            }
        }
    }
    return accumulate(all(tables),0);
}


void solve() {
	int n,s,x;
    cin >> n >> x >> s;
    string str;
    cin >> str;
    int numabivert = 0;
    for(auto &ch:str) {
        if (ch=='A')
            numabivert++;
    }
    int l=0,r=numabivert;
    while (l<r) {
        int mid = l + (r-l+1)/2;
        if (mid == r)
            mid--;
        int f_mid = calculatemaxseated(mid,str,x,s),f_midp1 = calculatemaxseated(mid+1,str,x,s);
        if (f_mid < f_midp1) {
            l=mid+1;
        } else {
            r=mid;
        }
    }
    // cout << "l " << l << " ";
    cout << calculatemaxseated(l,str,x,s) << "\n";
    
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
    	solve();
    }
    
    return 0;
}

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
	int n,k,q;
    cin >> n >> k >> q;
    vector<array<int,3>>arr(q);
    for(int i=0;i<q;i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
        arr[i][1]--,arr[i][2]--;
    }
    vector<int> mexmark(n,0);
    for(int i=0;i<q;i++) {
        if (arr[i][0]==1)
            continue;
        for(int j=arr[i][1];j<=arr[i][2];j++) {
            mexmark[j]=1;
        }
    }
    vector<int> ans(n,-1);
    for(int i=0;i<q;i++) {
        if (arr[i][0]==2)
            continue;
        for(int j=arr[i][1];j<=arr[i][2];j++) {
            if (mexmark[j]==0) {
                ans[j]=k;
            } else {
                ans[j]=n+1;
            }   
        }
    }
    vector<pii> mexs;
    for(int i=0;i<q;i++) {
        if (arr[i][0]==1)
            continue;
        mexs.push_back({arr[i][1],arr[i][2]});
    }
    sort(all(mexs));
    set<int> sss;
    for(int i=0;i<k;i++)
        sss.insert(i);
    for(auto [l,r]:mexs) {
        set<int>ss(sss);
        for(int j=l;j<=r;j++) {
            if (ans[j]!=-1)
                ss.erase(ans[j]);
        }
        int j=l;
        while(j<n &&ans[j]!=-1) j++;
        while(!ss.empty()) {
            auto num = *ss.begin();
            ans[j]= num;
            ss.erase(num);
            while(j<n && ans[j]!=-1) j++;    
        }
    }
    for(int i=0;i<n;i++) {
        if (ans[i]==-1)
            ans[i]=n+1;
    }
    for(int num:ans) {
        cout << num << " ";
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

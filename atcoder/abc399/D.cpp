#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define all(v) (v).begin(),(v).end()
#define F first
#define S second
const ll mod = 1e9+7;
void solve(int n, vector<int>&arr) {
    cout << "My: ";
    vector<vector<int>> adj(n+1);
    vector<int> toge(n+1,0);
    for(int i=0;i<2*n;i++) {
        int val = INT_MAX;
        if (i-1>=0) {
            if (arr[i]==arr[i-1]) {
                toge[arr[i]]=1;
            } else if (arr[i-1]>arr[i]) {
                val = arr[i-1];
                adj[arr[i]].push_back(arr[i-1]);
            }
        }
        if (i+1<2*n) {
            if (arr[i]==arr[i+1]) {
                toge[arr[i]]=1;
            } else if (arr[i+1]>arr[i] && arr[i+1]!=val) {
                adj[arr[i]].push_back(arr[i+1]);
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++) {
        if (toge[i]==1)
            continue;
        sort(all(adj[i]));
        for(int j=1;j<adj[i].size();j++) {
            if (adj[i][j]==adj[i][j-1] && toge[adj[i][j]]!=1)
                ans++;
        }
    }
    cout << ans << "\n";
}

// 3 1 4 8 9 1 4 3
/*
    1 3 5 1 3
    3 1 5 1 3
    1 1 3 3
    1 3 1 3 ----
    1 3 3 1
    3 1 1 3
    3 1 3 1 ---
    3 3 1 1

*/
void solve2(int n, vector<int>&arr) {
    cout << "acutal: ";
    vector<vector<int>> inds(n+1);
    for(int i=0;i<arr.size();i++) {
        inds[arr[i]].push_back(i);
    }
    int ans = 0;
    for(int i=1;i<=n;i++) {
        vector<vector<pii>>nums(2);
        if (abs(inds[i][0]-inds[i][1])==1)
            continue;
        for(int j=0;j<2;j++) {
            int ii = inds[i][j];
            if (ii-1>=0) {
                nums[j].push_back({arr[ii-1],ii-1});
            }
            if (ii+1<2*n) {
                nums[j].push_back({arr[ii+1],ii+1});
            }
        }
        for(int j=0;j<nums[0].size();j++) {
            for(int z=0;z<nums[1].size();z++) {
                if (nums[0][j].F==nums[1][z].F && nums[0][j].S!=nums[1][z].S) {
                    if (abs(inds[nums[0][j].F][0]-inds[nums[0][j].F][1])!=1)
                        ans++;
                }
            }
        }
    }
    cout << ans/2 << "\n";
}

int main() {
    fast;
    int t = 1;
    //cin >> t;
    while(t--){
        int n=5;
        //cin >> n;
        vector<int> arr(2*n);
        for(int i=0;i<2*n;i++) {
            //cin >> arr[i];
            arr[i]=(i+1)/2 + (i+1)%2;
        }
        random_shuffle(all(arr));
        for(int i=0;i<2*n;i++) {
            //cin >> arr[i];
            cout << arr[i] << " ";
        }
        arr = {1, 2, 4, 5, 4, 3, 3, 1, 2, 5};
        cout << "\n";
        solve(n,arr);
        solve2(n,arr);
    }
    return 0;
}
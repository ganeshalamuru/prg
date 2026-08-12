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


void movediscstogoal(int n,vector<int>&arr,int base,int nongoal, int goal, vector<array<int,3>>& moves) {
    if (n<1)
        return;
    movediscstogoal(n-1-arr[n],arr,base,goal,nongoal,moves);
    moves.push_back({n,base,goal});
    if (n-1-arr[n]==0) {
        movediscstogoal(n-1,arr,base,nongoal,goal,moves);
    } else if (arr[n]==0) {
        movediscstogoal(n-1,arr,nongoal,base,goal,moves);
    } else {
        movediscstogoal(n-1-arr[n],arr,nongoal,goal,base,moves);
        movediscstogoal(n-1,arr,base,nongoal,goal,moves);
    }
}


void solve() {
	int n;
    cin >> n;
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++) {
        cin >> arr[i];
    }
    for(int i=1;i<=n;i++) {
        if (arr[i]>=i) {
            cout << "NO\n";
            return;
        }
    }
    vector<array<int,3>> moves;
    movediscstogoal(n,arr,1,2,3,moves);
    cout << "YES\n";
    cout << moves.size() << "\n";
    for(auto &[id,from,to]:moves) {
        cout << id << " " << from << " " << to << "\n";
    }

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

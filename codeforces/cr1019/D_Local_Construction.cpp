#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define F first
#define S second
const ll mod = 1e9+7;


void solve() {
	int n;
    cin >> n;
    vector<int>arr(n);
    vector<vector<int>>ad(n+1);
    vector<vector<int>> adj(n+1);
    int curmax = INT_MIN;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
        if (arr[i]==-1) {
            curmax=INT_MAX;
        } else {
            curmax=max(curmax,arr[i]);
        }
        if (arr[i]!=-1) {
            if (curmax==arr[i]) {
                adj[arr[i]].push_back(1);
            } else {
                adj[arr[i]].push_back(0);
            }
            ad[arr[i]].push_back(i);
        }
    }
    int oddnum = n,evennum=1;
    vector<int>ans(n,-1);
    for(int i=1;i<=n;i++) {
        if (ad[i].size()==0)
            break;
        if (i%2==1) {
            for(int j=ad[i].size()-1;j>=0;j--) {
                ans[ad[i][j]]=oddnum;
                oddnum--;
            }
        } else {
            for(int j=ad[i].size()-1;j>=0;j--) {
                ans[ad[i][j]]=evennum;
                evennum++;
            }
        }
        if (adj[i][0]==1) {
            int x=0;
            queue<int> qq;
            while(x<adj[i].size() && adj[i][x]==1)
                qq.push(ans[ad[i][x]]),x++;
            x--;
            while(x>=0) {
                ans[ad[i][x]]=qq.front();
                qq.pop();
                x--;
            }
        }
    }
    for(int i=0;i<n;i++) {
        if (ans[i]!=-1) {
            cout << ans[i] << " ";
        } else {
            cout << oddnum << " ";
        }
    }
    cout << "\n";
}


int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}

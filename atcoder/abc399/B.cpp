#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define F first
#define S second
const ll mod = 1e9+7;
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> arr(n,vector<int>(2));
    for(int i=0;i<n;i++)
        cin >> arr[i][0],arr[i][1]=i;
    sort(rall(arr));
    vector<int> rank(n);
    int i=0,curank=1;
    while(i<n) {
        int curscore = arr[i][0];
        int cnt = 0;
        while (i<n && arr[i][0]==curscore) {
            rank[arr[i][1]]=curank, i++,cnt++;
        }
        curank+=cnt;
    }
    for(int j=0;j<n;j++)
        cout << rank[j] << "\n";

}
int main() {
    fast;
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
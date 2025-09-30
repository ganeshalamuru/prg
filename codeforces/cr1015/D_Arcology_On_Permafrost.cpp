#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).end()
#define F first
#define S second
const ll mod = 1e9+7;


void solve() {
	int n,m,k;
    cin >> n >> m >> k;
    vector<int> arr(k);
    for(int i=0;i<k;i++)
        arr[i]=i;
    vector<vector<int>> a(m,arr);
    int rem = n-m*k;
    a.push_back(vector<int>());
    for(int j=0;j<k && rem > 0;j++) {
        a.back().push_back(j);
        rem--;
    }
    int num=k;
    while(rem > 0) {
        for(int i=0;i<a.size() && rem>0;i++) {
            a[i].push_back(num);
            rem--;
        }
        num++;
    }
    for(int i=0;i<a.size();i++) {
        for(int j=0;j<a[i].size();j++) {
            cout << a[i][j] << " ";
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

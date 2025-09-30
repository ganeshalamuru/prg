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
    vector<vector<int>> arr(n,vector<int>(2));
    for(int i=0;i<n;i++) {
        cin >> arr[i][0] >> arr[i][1];
    }
    sort(all(arr));
    vector<set<int,greater<int>>> colpoints;
    vector<int> rowpoints;
    int z=0,oddfreqind=-1;
    while (z<n) {
        int num = arr[z][0];
        rowpoints.push_back(arr[z][0]);
        colpoints.push_back(set<int,greater<int>>());
        while(z<n && num==arr[z][0]) {
            colpoints.back().insert(arr[z][1]);
            z++;
        }
        if (colpoints.back().size()%2==1)
            oddfreqind=rowpoints.size()-1;
    }
    for(int i=0;i<oddfreqind;i++) {
        int diff = rowpoints[i+1]-rowpoints[i];
        auto itr = colpoints[i].begin();
        while(itr!=colpoints[i].end()) {
            int row1 = *itr;
            int val1 = row1-diff;
            if (colpoints[i+1].find(val1)!=colpoints[i+1].end()) {
                colpoints[i+1].erase(val1);
            } else {
                colpoints[i+1].insert(val1);
            }
            itr++;
            int row2 = *itr;
            int val2 = row2-diff;
            if (colpoints[i+1].find(val2)!=colpoints[i+1].end()) {
                colpoints[i+1].erase(val2);
            } else {
                colpoints[i+1].insert(val2);
            }
            itr++;
        }
    }
    for(int i=colpoints.size()-1;i>oddfreqind;i--) {
        int diff = rowpoints[i]-rowpoints[i-1];
        auto itr = colpoints[i].begin();
        while(itr!=colpoints[i].end()) {
            int row1 = *itr;
            int val1 = row1+diff;
            if (colpoints[i-1].find(val1)!=colpoints[i-1].end()) {
                colpoints[i-1].erase(val1);
            } else {
                colpoints[i-1].insert(val1);
            }
            itr++;
            int row2 = *itr;
            int val2 = row2+diff;
            if (colpoints[i-1].find(val2)!=colpoints[i-1].end()) {
                colpoints[i-1].erase(val2);
            } else {
                colpoints[i-1].insert(val2);
            }
            itr++;
        }
    }
    cout << rowpoints[oddfreqind] << " " << *colpoints[oddfreqind].begin() << "\n";


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

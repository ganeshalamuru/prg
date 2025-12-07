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
	int n;
    cin >> n;
    vector<vector<int>> arr(2) ;
    for(int i=0,num;i<n;i++) {
        cin >> num;
        arr[num%2].push_back(num);
    }
    if (arr[0].size()>1) {
        cout << arr[0][0] << " " << arr[0][1] << "\n";
        return;
    }
    if (arr[0].size()==1) {
        int eno = arr[0][0];
        for(int i=0;i<int(arr[1].size());i++) {
            int oddno = arr[1][i];
            if (eno<oddno)
                break;
            int tmp = eno / oddno;
            if (tmp%2==0) {
                cout << oddno << " " << eno << "\n";
                return;
            }
        }
    }
    if (arr[1].size()<=1000) {
        for(int i=0;i<int(arr[1].size());i++) {
            for(int j=i+1;j<int(arr[1].size());j++) {
                int tmp = arr[1][j] / arr[1][i];
                if (tmp%2==1) {
                    cout << arr[1][i] << " " << arr[1][j] << "\n";
                    return;
                }
            }
        }
        cout << -1 << "\n";
        return;
    }
    for(int i=0;i<int(arr[1].size());i++) {
        for(int j=i+1;j<int(arr[1].size());j++) {
            int tmp = arr[1][j] / arr[1][i];
            if (tmp%2==1) {
                cout << arr[1][i] << " " << arr[1][j] << "\n";
                return;
            }
        }
    }
    cout << -1 << "\n";
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

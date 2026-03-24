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
    vector<string> arr(n);
    for(auto &str: arr)
        cin >> str;
    deque<char> ans;
    for(auto ch:arr[0]) {
        ans.push_back(ch);
    }
    // b+s
    // s+b
    for(int i=1;i<n;i++) {
        int x=0,y=0,ssz = int(ans.size())+int(arr[i].size());
        while(x<ssz && y<ssz) {
            char xch='a',ych='a';
            if (x<int(ans.size())) {
                xch=ans[x];
            } else {
                xch=arr[i][x-int(ans.size())];
            }
            if (y<int(arr[i].size())) {
                ych=arr[i][y];
            } else {
                ych = ans[y-int(arr[i].size())];
            }
            if (xch<ych) {
                for(auto ch:arr[i])
                    ans.push_back(ch);
                break;
            } else if (xch>ych) {
                reverse(all(arr[i]));
                for(auto ch:arr[i])
                    ans.push_front(ch);
                break;
            }
            x++,y++;
        }
        if (x==ssz && y==ssz) {
            for(auto ch:arr[i])
                ans.push_back(ch);
        }
    }
    for(auto ch:ans)
        cout << ch;
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

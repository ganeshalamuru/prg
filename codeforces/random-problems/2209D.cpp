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
	int r,g,b;
    cin >> r >> g >> b;
    vector<pair<int,char>>cols{{r,'R'},{g,'G'},{b,'B'}};
    erase_if(cols,[](const auto &a){return a.F==0;});
    sort(all(cols));
    if (cols.size()==1) {
        cout << cols[0].S << "\n";
    } else if (cols.size()==2) {
        string str;
        for(int i=1,sz=cols[0].F;i<=sz;i++) {
            str.push_back(cols[1].S),str.push_back(cols[0].S);
            cols[0].F--,cols[1].F--;
        }
        if (cols[1].F > 0)
            str.push_back(cols[1].S);
        cout << str << "\n";
    } else {
        string str;
        int typ=0;
        while (cols[0].F+cols[1].F>cols[2].F) {
            str.push_back(cols[typ].S);
            cols[typ].F--;
            typ^=1;
        }
        typ^=1;
        for(int j=0;j<=1;j++) {
            for(int i=1;i<=cols[typ].F;i++) {
                str.push_back(cols[2].S),str.push_back(cols[typ].S);
                cols[2].F--;
            }
            typ^=1;
        }
        if (cols[2].F>0)
            str.push_back(cols[2].S);
        cout << str << "\n";
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

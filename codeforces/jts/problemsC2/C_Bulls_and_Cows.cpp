#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define F first
#define S second
#define PB push_back
#define MP make_pair
const ll mod = 1e9+7, N = 2e6+7, M = 2e6+7, INF = INT_MAX/10;
ll powe(ll x, ll y){ x = x%mod, y=y%(mod-1);ll ans = 1;while(y>0){if (y&1){ans = (1ll * x * ans)%mod;}y>>=1;x = (1ll * x * x)%mod;}return ans;}


pair<int,int> compareGuess(string ans, string guess) {
    pair<int,int> bulcows{0,0};
    set<char> ss;
    for(int i=0;i<4;i++) {
        if (ans[i] == guess[i]) {
            bulcows.first++;
            continue;
        }
        ss.insert(ans[i]);
    }
    for(int i=0;i<4;i++) {
        if (ans[i] == guess[i])
            continue;
        if (ss.find(guess[i]) != ss.end())
            bulcows.second++;
    }
    return bulcows;
}
bool allDiff(string num) {
    set<char> ss;
    for(char& ch:num)
        ss.insert(ch);
    return ss.size() == 4;
}
void solve() {
	int n;
    cin >> n;
    vector<string> number(n);
    vector<pair<int,int>> bulcows(n);
    for(int i=0;i<n;i++)
        cin >> number[i] >> bulcows[i].first >> bulcows[i].second;
    vector<string> possibleAns;
    for(int i=100;i<10000 && possibleAns.size() < 2;i++) {
        string ans = to_string(i);
        if (ans.size() < 4)
            ans = "0" + ans;
        if (!allDiff(ans))
            continue;
        bool consistent = true;
        for(int j=0;j<n;j++) {
            auto tempbulcows = compareGuess(ans, number[j]);
            if (tempbulcows != bulcows[j]) {
                consistent = false;
                break;
            }
        }
        if (consistent)
            possibleAns.push_back(ans);
    }
    if (possibleAns.empty()) {
        cout << "Incorrect data\n";
    } else if (possibleAns.size() == 1) {
        cout << possibleAns[0] << "\n";
    } else {
        cout << "Need more data\n";
    }
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}

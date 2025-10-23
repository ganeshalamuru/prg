#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define F first
#define S second


void solve() {
	string s;
    cin >> s;
    vector<int> freq(26,0);
    for(char &ch:s)
        freq[ch-'A']++;
    int n = s.size();
    int maxele = *max_element(all(freq)); 
    if (maxele>(n+1)/2) {
        cout << -1 << "\n";
        return;
    }
    auto posit = [](const auto &x){return x>0;};
    string ans;
    int rem = n;
    while ((*max_element(all(freq)))<(rem+1)/2) {
        auto minitr1 = find_if(all(freq), posit);
        int minind1 = distance(freq.begin(), minitr1);
        auto minitr2 = find_if(minitr1+1,freq.end(), posit);
        int minind2 = distance(freq.begin(),minitr2);
        if (ans.size()>0 && ans.back()==char('A'+minind1)) {
            ans.push_back(char('A'+minind2));
            ans.push_back(char('A'+minind1));
        } else {
            ans.push_back(char('A'+minind1));
            ans.push_back(char('A'+minind2));
        }
        freq[minind1]--,freq[minind2]--;
        rem-=2;
    }
    //cout << "ans " << ans << "\n";
    auto itr = max_element(rall(freq));
    int maxind = 25-distance(freq.rbegin(), itr);
    //cout << "maxind " << maxind << "\n";
    if (rem%2==1) {
        ans.push_back(char('A'+maxind));
        freq[maxind]--;
    }
    int maxcharfreq = freq[maxind];
    freq[maxind]=0;
    auto minitr = find_if(freq.begin(), freq.end(), posit);
    //cout << "ans " << ans <<" "<< char('A'+i)<< "\n";
    if (ans.size()>0 && ans.back()==char('A'+ distance(freq.begin(), minitr))) {
        auto sminitr = find_if(minitr+1,freq.end(), posit);
        ans.push_back(char('A'+distance(freq.begin(), sminitr)));
        ans.push_back(char('A'+maxind));
        maxcharfreq--;
        (*sminitr)--;
    }
    minitr = find_if(freq.begin(), freq.end(), posit);
    while(maxcharfreq>0) {
        ans.push_back(char('A'+distance(freq.begin(), minitr)));
        ans.push_back(char('A'+maxind));
        maxcharfreq--;
        (*minitr)--;
        minitr = find_if(minitr, freq.end(), posit);
    }
    cout << ans << "\n";

}


int main() {
    fast;
    int t = 1;
    //cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}

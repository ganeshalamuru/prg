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
    string s;
    cin >> s;
    if (s.size() == 1) {
        cout << s << "\n";
        return;
    }
    array<int,10> freq{};
    int totsum = 0;
    for(auto &ch:s)
        freq[ch-'0']++,totsum+=(ch-'0');
    
    for(int i=1;i<=9e5;i++) {
        array<int,10> digits{};
        int tmp = i, cursodssum = 0;;
        while(tmp>9) {
            int sod = 0;
            while (tmp>0) {
                digits[tmp%10]++;
                sod+=tmp%10;
                tmp/=10;
            }
            cursodssum+=sod;
            tmp=sod;
        }
        digits[tmp]++;
        cursodssum+=tmp;
        bool possiblesods = true;
        for(int j=0;j<10;j++) {
            if (freq[j]<digits[j]) {
                possiblesods = false;
                break;
            }
        }
        if (possiblesods && totsum-cursodssum == i) {
            for(int j=0;j<10;j++)
                freq[j]-=digits[j];
            string ans;
            int tmp2 = 0;
            for(int j=9;j>=0;j--) {
                for(int times = 1;times<=freq[j];times++) {
                    ans.push_back(char('0'+j));
                }
                tmp2+=j*freq[j];
            }
            while(tmp2>9) {
                int sod = 0;
                ans += to_string(tmp2);
                while (tmp2>0) {
                    digits[tmp2%10]++;
                    sod+=tmp2%10;
                    tmp2/=10;
                }
                tmp2 = sod;
            }
            ans.push_back(char('0'+tmp2));
            cout << ans << "\n";
            return;
        }
        
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

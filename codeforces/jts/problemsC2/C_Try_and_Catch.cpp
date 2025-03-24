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

bool bracketPresent(string &str) {
    return str.find('(') != string::npos;
}

bool catchLine(string &str) {
    return str.find("catch") != string::npos && bracketPresent(str) && str.find('"') != string::npos;
}

bool throwLine(string &str) {
    return str.find("throw") != string::npos && bracketPresent(str) && str.find('"') == string::npos;
}

bool tryLine(string &str) {
    return str.find("try") != string::npos && !bracketPresent(str);
}

bool emptyLine(string &str) {
    return str.find("t") == string::npos;
}

pair<string,string> processCatch(string &str) {
    int s = str.find_first_of('(');
    int e = str.find_first_of(',');
    string excep = str.substr(s+1, e-s-1);
    erase(excep, ' ');
    int qs = str.find_first_of('"');
    int qe = str.find_last_of('"');
    string message = str.substr(qs+1, qe - qs-1);
    return {excep, message};
}

string processThrow(string &str) {
    int s = str.find_first_of('(');
    int e = str.find_last_of(')');
    string excep = str.substr(s+1, e-s-1);
    erase(excep, ' ');
    return excep;
}


int processTryCatch(vector<string> &prog, int i, bool processException, pair<string, string> &excepmsg) {
    int numlines = prog.size();
    if (i >= numlines)
        return numlines;
    int j = i + 1;
    while(j < numlines) {
        if (emptyLine(prog[j])) {
            j++;
            continue;
        }
        if (throwLine(prog[j])) {
            excepmsg.first = processThrow(prog[j]);
            j++;
            continue;
        }
        if (tryLine(prog[j])) {
            if (!excepmsg.first.empty())
                j = processTryCatch(prog, j, false, excepmsg);
            else
                j = processTryCatch(prog, j, true, excepmsg);
            
        }
        if (catchLine(prog[j]))
            break;
    }
    pair<string,string> excepmsgInCatch = processCatch(prog[j]);
    if (processException && excepmsg.first == excepmsgInCatch.first && excepmsg.second.empty())
        excepmsg.second = excepmsgInCatch.second;
    return j+1;
}

void solve() {
	int n;
    cin >> n;
    // end the line after reading the number
    string temp;
    getline(cin,temp);
    vector<string> prog(n);
    for(int i=0;i<n;i++) {
        getline(cin, prog[i]);
    }
    int i=0;
    pair<string, string> excepmsg = {"",""};
    while(i<n) {
        if (emptyLine(prog[i])) {
            i++;
            continue;
        }
        if (throwLine(prog[i])) {
            excepmsg.first = processThrow(prog[i]);
            break;
        }
        int e = processTryCatch(prog, i, true, excepmsg);
        if (!excepmsg.first.empty()) {
            break;
        }
        i=e;
    }
    if (excepmsg.second.empty())
        excepmsg.second = "Unhandled Exception";
    cout << excepmsg.second << "\n";
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}

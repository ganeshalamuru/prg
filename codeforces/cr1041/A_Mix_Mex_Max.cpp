#include <bits/stdc++.h>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define F first
#define S second
#include <windows.h> // Required for GetSystemInfo and SYSTEM_INFO
#include <psapi.h>

void solve() {
    using namespace std;
	int n;
    cin >> n;
    map<int,int> mp;
    int zerocnt = 0;
    for(int i=0,x;i<n;i++) {
        cin >>x;
        if (x!=-1)
            mp[x]++;
        zerocnt+=(x==0);
    }
    if (zerocnt>0) {
        cout << "NO\n";
    } else if (mp.size()>1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }

}


int main() {
    int t = 1;
    std::cin >> t;
    while(t--){
    	solve();
    }
    int arr[2]={1,1};
    std::cout << (&arr[0]) << " " << (&arr[1]) << "\n";

    PROCESS_MEMORY_COUNTERS pmc;
    if (GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc))) {
        std::cout << "Page Fault Count: " << pmc.PageFaultCount << std::endl;
    }
    return 0;
}

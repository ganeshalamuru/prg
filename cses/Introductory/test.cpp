#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define F first
#define S second
struct My16ByteStruct {
    unsigned char bytes[16];
};


int main() {

    ll a = 1ll<<53;
    ll b = a + 1;
    double c = a, d = b,x=37.0l,inff = 3.0;
    cout << a << " " << b << "\n";
    cout << bitset<64>(a) << "\n" << bitset<64>(b)<<"\n" << bitset<64>(37) << "\n";
    cout << fixed << setprecision(53)<< c << "\n" << d << "\n";
    cout << bitset<64>((bit_cast<unsigned long long>(c))) << "\n";
    cout << bitset<64>((bit_cast<unsigned long long>(d))) << "\n";
    cout << bitset<64>((bit_cast<unsigned long long>(x))) << "\n";
    cout << bitset<64>((bit_cast<unsigned long long>(inff))) << "\n";
    cout << int(0b10000110100)-1023 << "\n";
    long double y = a,z=3.0;
    unsigned char* it = reinterpret_cast<unsigned char*>(&z);
    int szs = sizeof(z);
    for (int i = szs-1; i>=0; i--) {
    // std::cout
    //     << "byte "
    //     << i
    //     << '\t'
    //     << std::bitset<CHAR_BIT>(it[i])
    //     << '\t'
    //     << std::hex << int(it[i])
    //     << '\t'
    //     << std::dec << int(it[i])
    //     << '\n';
    cout << std::bitset<CHAR_BIT>(it[i]);
    }
    cout << "\n";
    cout << y + z << "\n";
    return 0;
}

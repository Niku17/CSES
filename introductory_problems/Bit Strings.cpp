#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;

    long long mod = 1e9 + 7;
    long long ans = 1;
    long long base = 2;

    while (n > 0) {
        if (n % 2 == 1)
            ans = (ans * base) % mod;

        base = (base * base) % mod;
        n /= 2;
    }

    cout << ans;

    return 0;
}
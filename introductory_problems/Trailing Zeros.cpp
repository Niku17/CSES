#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;

    long long count = 0;

    while (n > 0) {
        n /= 5;
        count += n;
    }

    cout << count;

    return 0;
}
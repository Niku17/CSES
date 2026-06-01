#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;

    int freq[26] = {0};

    for (char c : s)
        freq[c - 'A']++;

    int odd = 0;

    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2)
            odd++;
    }

    if (odd > 1) {
        cout << "NO SOLUTION";
        return 0;
    }

    string left = "", mid = "";

    for (int i = 0; i < 26; i++) {
        left += string(freq[i] / 2, 'A' + i);

        if (freq[i] % 2)
            mid = char('A' + i);
    }

    string right = left;
    reverse(right.begin(), right.end());

    cout << left + mid + right;
}
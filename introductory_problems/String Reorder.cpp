#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(int rem, vector<int>& freq, int cur) {
    int mx = 0;

    for (int i = 0; i < 26; i++) {
        mx = max(mx, freq[i]);
    }

    return mx <= (rem + 1) / 2 ;
}

int main() {
    string s;
    cin >> s;

    int n = s.size();

    vector<int> freq(26, 0);

    for (char ch : s) {
        freq[ch - 'A']++;
    }

    string ans = "";
    char last = '\0';

    for (int pos = 0; pos < n; pos++) {

        for (int j = 0; j < 26; j++) {

            char c = 'A' + j;

            if (freq[j] == 0 || c == last)
                continue;

            freq[j]--;

            if (isPossible(n - pos - 1, freq, j)) {
                ans += c;
                last = c;
                break;
            }

            freq[j]++;
        }
    }

    if ((int)ans.size() == n)
        cout << ans;
    else
        cout << -1;

    return 0;
}
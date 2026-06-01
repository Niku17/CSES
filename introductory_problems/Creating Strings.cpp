#include <iostream>
#include <string>
#include <vector>
using namespace std;
void generatePermutations(string& current, int n, int freq[], vector<string>& result) {
    if (current.length() == n) {
        result.push_back(current);
        return;
    }
    for (int i = 0; i < 26; ++i) {
        if (freq[i] > 0) {
            freq[i]--;
            current.push_back(i + 'a');
            
            generatePermutations(current, n, freq, result);
            
            current.pop_back();
            freq[i]++;
        }
    }
}
int main() {
    string s;
    cin >> s ; 
    int freq[26] = {0};
    for (char c : s) {
        freq[c - 'a']++;
    }
    vector<string> result;
    string current = "";
    generatePermutations(current, s.length(), freq, result);
    cout << result.size() << endl;
    for (const string& perm : result) {
        cout << perm << endl;
    }

    return 0;
}
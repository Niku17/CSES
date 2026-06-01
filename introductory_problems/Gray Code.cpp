#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> solve(int n) {
    if (n == 1)
        return {"0", "1"};

    vector<string> dum = solve(n - 1);

    vector<string> dum2 = dum;
    reverse(dum2.begin(), dum2.end());

    vector<string> ans;

    for (auto s : dum)
        ans.push_back("0" + s);

    for (auto s : dum2)
        ans.push_back("1" + s);

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<string> ans = solve(n);
    
    for (auto s : ans)
        cout << s << endl;

    return 0;
}
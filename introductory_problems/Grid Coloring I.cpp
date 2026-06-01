
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int n , m ;
    cin >> n >> m ;

    vector<string> grid(n);

    for(int i = 0 ; i < n ; i++){
        cin >> grid[i];
    }

    vector<string> ans = grid;

    for(int i = 0 ; i < n ; i++){

        for(int j = 0 ; j < m ; j++){

            for(char c = 'A' ; c <= 'D' ; c++){

                if(c == grid[i][j])
                    continue;

                if(i > 0 && ans[i-1][j] == c)
                    continue;

                if(j > 0 && ans[i][j-1] == c)
                    continue;

                ans[i][j] = c;
                break;
            }
        }
    }

    for(auto &s : ans){

        cout << s << "\n";
    }
}
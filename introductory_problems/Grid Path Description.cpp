#include <bits/stdc++.h>
using namespace std;
int ans = 0 ; 
string s;

bool visited[7][7];

bool in_bound(int r, int c) {
    return r >= 0 && r < 7 && c >= 0 && c < 7;
}
void  solve( int r , int c , int steps ,  int i ){
    if( r == 6 && c == 0){
        if(steps == 48 ) ans++; 
        return ; 
    }
   bool left  = !in_bound(r, c - 1) || visited[r][c - 1];
    bool right = !in_bound(r, c + 1) || visited[r][c + 1];
    bool up    = !in_bound(r - 1, c) || visited[r - 1][c];
    bool down  = !in_bound(r + 1, c) || visited[r + 1][c];
 
    // corridor pruning
    if (up && down &&
        in_bound(r, c - 1) && !visited[r][c - 1] &&
        in_bound(r, c + 1) && !visited[r][c + 1])
        return;
 
    if (left && right &&
        in_bound(r - 1, c) && !visited[r - 1][c] &&
        in_bound(r + 1, c) && !visited[r + 1][c])
        return;

     visited[r][c] = 1 ;
    if (in_bound(r + 1, c) &&
    !visited[r + 1][c] &&
    (s[i] == 'D' || s[i] == '?')) {
    solve(r + 1, c, steps + 1, i + 1);
}

if (in_bound(r - 1, c) &&
    !visited[r - 1][c] &&
    (s[i] == 'U' || s[i] == '?')) {
    solve(r - 1, c, steps + 1, i + 1 );
}

if (in_bound(r, c + 1) &&
    !visited[r][c + 1] &&
    (s[i] == 'R' || s[i] == '?')) {
    solve(r, c + 1, steps + 1, i + 1);
}

if (in_bound(r, c - 1) &&
    !visited[r][c - 1] &&
    (s[i] == 'L' || s[i] == '?')) {
    solve(r, c - 1, steps + 1, i + 1);
}
    
    visited[r][c] = 0 ; 
    return ;
    
}

int main() {
     cin >> s;
 
    solve(0, 0, 0 , 0);
 
    cout << ans << '\n';
}
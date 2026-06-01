#include<iostream>
#include<vector>
#include<unordered_map>
#define ll long long 
using namespace std ;
ll ans = 0  ; 
void solve( int i , int j ,  int queens , unordered_map<int,bool>&row , unordered_map<int,bool>&col , unordered_map<int,bool>&diag1 , unordered_map<int,bool>&diag2 , vector<vector<char>>&board){

    if( queens == 8 ) { ans++; return ; }
    if( i >= 8 ) return ;

    int ni = (j == 7) ? i+1 : i ;
    int nj = (j == 7) ? 0 : j+1 ;

    int dg1 = ( i + j) ;
    int dg2 = ( i - j ) ;

    if( board[i][j] == '.' && !row[i] && !col[j] && !diag1[dg1] && !diag2[dg2] ){
        row[i] = 1 ; col[j] = 1 ; diag1[dg1] = 1 ; diag2[dg2] = 1 ; 
        solve( ni , nj , queens + 1 , row , col , diag1 , diag2 , board) ; 
        row[i] = 0 ; col[j] = 0 ; diag1[dg1] = 0 ; diag2[dg2] = 0 ; 
    }

    
    solve( ni , nj , queens , row , col , diag1 , diag2 , board) ; 
}

int main(){
    vector<vector<char>>board( 8 ,  vector<char>( 8 , '.'));
    for( int i = 0 ; i < 8 ; i++ )
        for( int j = 0 ; j < 8 ; j++ )
               cin>>board[i][j] ;
    unordered_map<int, bool>row, col, diag1, diag2 ;
    solve( 0 , 0 , 0 , row , col , diag1 , diag2 , board ) ;
    cout << ans ;
}
#include<iostream>
#include<vector>
#define ll long long 
using namespace std ; 
ll ans = 2e10 ; 
ll total = 0 ; 
void solve( int idx , ll s ,  vector<ll>&a) {
    if( idx  >= a.size() ) {
        ans = min( abs(total -2*s) , ans  ) ;
        return ;
    };
    solve( idx + 1  ,  a[idx] + s   , a   ) ;
    solve( idx + 1 , s , a) ;
    return ;
}
int main(){
    int n ;
    cin >> n ;
    vector<ll>a( n , 0) ;
    for( int i = 0 ; i < n ; i++ ){
        cin>>a[i] ;
    }
    for( int i = 0 ; i < n ; i++ ){
        total+= a[i] ;
    }
     solve( 0 , 0 ,  a) ;
     cout<< ans ;
}
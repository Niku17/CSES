#include<iostream>
using namespace std ;
int main(){
    int n ; 
    cin >> n ;
    int xr = 0 ;
    for( int i = 0 ; i < n - 1 ; i++){
        int x ;
        cin >> x ;
        xr = xr^x ;
    }

    for( int i = 1 ; i <= n ; i++){
        xr = xr^i ;
    }
    cout << xr ;
    return 0;
}

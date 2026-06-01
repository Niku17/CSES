#include<iostream>
#include<vector>
using namespace std ;
int main(){
    int n ; 
    cin >> n ;
    if( n <= 3 && n > 1) cout << "NO SOLUTION" ;
    else {
    vector<int>ans(n , 0);
    int ele = 2 ; 
    for( int i = 0 ; i < n/2 ; i++){
        ans[i] = ele;
        ele+=2;
    }
    ele = 1 ; 
    for( int i = n/2 ; i < n ; i++){
        ans[i] = ele;
        ele+=2;
    }
    for( int i= 0 ; i < n ; i++ ){
        cout<<ans[i] << " " ;
    }
    }
    
    return 0;
}

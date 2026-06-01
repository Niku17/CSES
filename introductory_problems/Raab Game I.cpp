#include<iostream>
#include<vector>
#include<unordered_map>
#define ll long long 
using namespace std ;
int main(){
    int t ; 
    cin >> t ;
    while(t--){
        int n , a , b ;
        cin >> n >> a >> b ;
        if( a == 0 && b == 0) {
            cout<<"YES"<<endl ;
            for( int i = 1 ; i <= n ; i++ ){
                cout<<i<<" " ;
            }
            cout<<endl ;
            for( int i = 1 ; i <= n ; i++ ){
                cout<<i<<" " ;
            }
            
        }
        else if( a*b == 0 || a + b > n ) cout << "NO" ;
        else {
            int equal = n - ( a + b) ;
            int rem = n - equal ;
            vector<int>A,B;
            for( int i = 1 ; i <= n ; i++ ){
                A.push_back(i) ;
            } 
            int l = 1 + a  ;
            while(b--){
                B.push_back(l);
                l++;
            }
            
            
            for( int i =  1 ; i <= a ; i++ ){
                B.push_back(i) ;
            }
            for( int i =  rem + 1  ; i <= n ; i++ ){
                B.push_back(i) ;
            }
            cout<<"YES"<<endl;
            for( int  i = 0 ; i < A.size() ; i++ ){
                cout << A[i] <<" " ;
            }
            cout<<endl;
            for( int  i = 0 ; i < A.size() ; i++ ){
                cout << B[i] <<" " ;
            } 
        }
        cout<<endl;
    }
}
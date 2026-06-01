#include<iostream>
using namespace std ;
int main(){
   string s ;
   cin>>s ;
   int n = s.size() ; 
   int ans = 0  ; 
   int r = 0 ;
   while( r < n) {
    char c = s[r] ;
    int cnt = 0 ; 
    while(s[r] == c){
        cnt++;
        r++;
    }
    ans = max( ans , cnt) ;
   }
    cout<< ans ; 
   
   return 0;
}

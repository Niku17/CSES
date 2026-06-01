#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std ;
int main(){
    long long  n ; 
    cin >> n ;
    long long sum = n * ( n + 1 ) / 2 ; 
    if ( sum % 2 == 1 ) cout << "NO";
    else{
        cout << "YES" << endl ;
        vector<int>ans1, ans2 ;
        long long diff = sum/2 ; 
        long long ptr = n ;
        while(diff != 0 ){
        if( ptr <= diff){
                    ans1.push_back(ptr);
                    diff-=ptr ;
            ptr--;
                }
                else{
                    ans2.push_back(ptr) ;
                    ptr--;
                }
        }
        
    while(ptr!=0){
       ans2.push_back(ptr) ;
                    ptr--; 
    }
    cout << ans1.size() << endl ;
    for( int i = 0 ; i < ans1.size() ; i++){
     cout<<ans1[i] << " " ;
    }
    cout<<endl;
    cout << ans2.size() << endl ;
    for( int i = 0 ; i < ans2.size() ; i++){
     cout<<ans2[i] << " " ;
    }

}
    return 0;
}

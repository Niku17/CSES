#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using i128 = __int128_t;

ll binexp(ll a , ll b){

    ll res = 1;

    while(b){

        if(b & 1) res *= a;

        a *= a;
        b >>= 1;
    }

    return res;
}

int main(){

    int q ;
    cin >> q;

    while(q--){

        ll k ;
        cin >> k;

        i128 sum = 0 ;
        int pos = 1 ;

        for( int i = 1 ; i <= 18 ; i++ ){

            sum += (i128)9 * binexp(10,i-1) * i ;
            pos = i ;

            if( sum >= k ) break ;
        }

        for( int i = 1 ; i < pos ; i++ ){

            k -= 9LL * binexp(10,i-1) * i ;
        }

        ll pos_of_number = (k + pos - 1) / pos ;
        ll pos_inside_no = (k - 1) % pos ;

        ll number = binexp(10,pos-1) + pos_of_number - 1 ;

        string s = to_string(number);

        cout << s[pos_inside_no] << "\n";
    }
}
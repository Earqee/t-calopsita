#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <limits.h>
#include <math.h>
#include <iomanip>

#define pb push_back
#define pp pop_back
#define mp make_pair
#define lwb lower_bound
#define upb upper_bound
#define all(E) E.begin(), E.end()
#define e_min min_element
#define e_max max_element 
#define bin_s binary_search 
#define ff find

using namespace std;
typedef long int ll;
typedef vector<ll> vct;
typedef vector< vct > vvct;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector< vii > ADL;
typedef bitset<1 << 8> VL;

int main() {
    vct books, sol; 
    ll it, min, diff_min, price, N, M;
    
    while(cin >> N) {
        for(ll i = 0; i < N; i++) {
            cin >> price;
            books.pb(price);
        }
        cin >> M;
        sort(all(books));
        for(ll i = 0, diff_min = INT_MAX; i < N; i++) {
            min = M - books.at(i);
            it = lwb(all(books), min) - books.begin();
            if(it != books.size() && it != i) {
                if(books.at(it) == min) {
                    min = abs(books.at(i) - books.at(it));
                    if(min < diff_min) {
                        diff_min = min;
                        sol.clear();
                        sol.pb(books.at(i)); sol.pb(books.at(it));
                    }                
                }
            }
        }
        printf("Peter should buy books whose prices are %ld and %ld.\n\n", sol.at(0), sol.at(1));
        books.clear();
    }   
    return 0;
}
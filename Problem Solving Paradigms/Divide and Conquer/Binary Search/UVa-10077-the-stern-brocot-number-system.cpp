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
    ll last_num_R, last_den_R,
       last_num_L, last_den_L;
    ll temp_last_num, temp_last_den;
    ll N, D, c_num, c_den;

    do {
        cin >> N >> D;
        if(N != 1 || D != 1) {
            c_num = 1; c_den = 1;
            last_num_L = 0; last_den_L = 1;
            last_num_R = 1; last_den_R = 0;
            if(N != D) {
                while(c_num != N || c_den != D) {
                    if(c_num/(c_den*1.0) < N/(D*1.0)) {
                        temp_last_num = c_num;
                        temp_last_den = c_den;
                        c_num += last_num_R;
                        c_den += last_den_R;
                        last_num_L = temp_last_num;
                        last_den_L = temp_last_den;
                        cout << 'R';
                    } else if (c_num/(c_den*1.0) > N/(D*1.0)) {
                        temp_last_num = c_num;
                        temp_last_den = c_den;
                        c_num += last_num_L;
                        c_den += last_den_L;
                        last_num_R = temp_last_num;
                        last_den_R = temp_last_den;
                        cout << 'L';
                    }
                } 
            } else cout << 'I';
            cout << endl;
        }
    } while(N != 1 || D != 1);   
   return 0;
}
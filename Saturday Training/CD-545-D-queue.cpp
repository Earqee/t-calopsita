#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define pb push_back
#define pp pop_back
#define lwb lower_bound
#define upb upper_bound
#define all(E) E.begin(), E.end()
#define e_min min_element
#define e_max max_element 
#define bin_s binary_search //bool
#define ff find

using namespace std;
typedef long int ll;
typedef vector<ll> vct;
typedef vector< vct > vvct;

ll f_n(vct & vctN) {
    ll sum, count, vctNsize;
    vct vctNsum; vct::iterator it;    
    sort(all(vctN));
    sum = count = 0; vctNsize = vctN.size();    
    for(ll i = 0; i < vctNsize; i++) {
        vctNsum.pb(sum);
        if(vctNsum.at(i) <= vctN.at(i)) {
            count++;
            sum += vctN.at(i);
        }
    }  
    return count;
}

int main() {
    vct vctN;
    ll num, N; cin >> N;    
   for(ll i = 0; i < N; i++) {
        cin >> num;
        vctN.pb(num);
    }    
    cout << f_n(vctN);
    return 0;
}
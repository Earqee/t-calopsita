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

ll f_n(vct &vctN, ll const & b) {
    vct::iterator it;
    it = upb(all(vctN), b);
    return it - vctN.begin();
}

int main(){
    vct vctN;
    ll num, N, Q; cin >> N;
   for(ll i = 0; i < N; i++) {
        cin >> num;
        vctN.pb(num);
    }
    cin >> Q;
    sort(all(vctN));
    for(ll i = 0; i < Q; i++) {
        cin >> num;
        cout << f_n(vctN, num) << endl;
    }
    return 0;
}

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

int main(){
    vct vctN, vctM; vct::iterator it;
    ll num, N, M; cin >> N;
    vctN.pb(0);
    for(ll i = 0; i < N; i++) {
        cin >> num;
        num += vctN.at(i);
        vctN.pb(num);
    }
    cin >> M;
    for(ll i = 0; i < M; i++) {
        cin >> num;
        it = lwb(all(vctN), num);
        cout << it - vctN.begin() << endl;
    }
    return 0;
}
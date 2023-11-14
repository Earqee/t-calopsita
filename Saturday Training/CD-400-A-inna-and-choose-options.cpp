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

int x[] = {1, 2, 3, 4, 6, 12};
int y[] = {12, 6, 4, 3, 2, 1};

bool make_sol(ll l, ll c, string str, vct &sol) {
    char M[l + 1][c + 1]; ll k = 0;
    for(ll i = 0; i < l; i++)
        for(ll j = 0; j < c; j++)
            M[i][j] = str.at(k++);
    for(ll j = 0; j < c; j++) {
        for(ll i = 0; i < l; i++) {
            if(M[i][j] != 'X')
                break;
            if(i + 1 == l)
                return true;
        }
        if(j + 1 == c)
            return false;
    }
    return false;
}

int main() {
    string str; vct sol;

    ll count, N; cin >> N;    
    
    for(ll i = 0; i < N; i++) {
        cin >> str;
        count = 0; sol.clear();
        for(ll k = 0; k < 6; k++) {
            if(make_sol(x[k], y[k], str, sol)) {
                count++;
                sol.pb(x[k]); sol.pb(y[k]);
            }
        }
        cout << count;
        for(ll k = 0; k + 1 < sol.size(); k+=2)
            cout << " " << sol.at(k) << "x" << sol.at(k + 1);
            cout << endl;
    }
    return 0;
}


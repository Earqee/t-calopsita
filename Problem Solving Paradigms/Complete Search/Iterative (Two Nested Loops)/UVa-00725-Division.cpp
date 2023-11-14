#include <bits/stdc++.h>

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
typedef long long ll;
typedef vector<ll> vct;
typedef vector< vct > vvct;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector< vii > ADL;
typedef bitset<1 << 20> VL;

int main() {
    ll N;
    bool first = true;
    while(cin >> N, N != 0) {
        bool has_solution = false;
        if(!first)
            cout << endl;
        first = false;
        for(ll fghij = 1234; fghij*N <= 98765; fghij++) {
            ll abcde = N*fghij;
            ll used = (fghij < 10000);
            ll check = abcde;
            while(check) {
                used |= 1 << (check % 10);
                check /= 10;
            }
            check = fghij;
            while(check) {
                used |= 1 << (check % 10);
                check /= 10;
            }
            if(used == (ll) (1<<10)-1) {
                has_solution = true;
                printf("%lld / %.5lld = %lld\n", abcde, fghij, N);
            }
        }
        if(!has_solution)
            printf("There are no solutions for %lld.\n", N);
    }
}

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
    ll T, N, L, input;
    vct values(6), drawn(76);
    vvct table(6);

    cin >> T;
    for(ll i = 1; i <= T; i++) {
        cin >> N >> L;
        drawn.assign(76, 0);
        for(ll j = 0; j < N; j++) {
            cin >> input;
            drawn[input] = j+1;
        }
        if(i - 1)
            printf("\n");
        printf("Case %lld:\n", i);
        for(ll j = 0; j < 4; j++)
            cin >> values[j];
        while(L--) {
            for(ll j = 0; j < 5; j++) {
                table[j].resize(6);
                for(ll k = 0; k < 5; k++) {
                    cin >> input;
                    if(drawn[input])
                        table[j][k] = drawn[input];
                    else
                        table[j][k] = 0;
                }
            }

            bool corners = (table[0][0] != 0 && table[4][4] != 0 &&
                    table[0][4] != 0 && table[4][0] != 0);
            if(corners && table[0][0] < 36 && table[4][0] < 36 &&
                    table[0][4] < 36 && table[4][4] < 36)
                corners = true;
            else
                corners = false;
            bool midline = true;
            for(ll j = 0; j < 5 ; j++)
                if(!table[2][j] || table[2][j] > 40)
                    midline = false;
            bool diagonals = true;
            for(ll j = 0; j < 5; j++)
                if(!table[j][j] || !table[j][4-j] ||
                        table[j][j] > 45 || table[j][4-j] > 45)
                    diagonals = false;
            bool all = true;
            for(ll j = 0; j < 5; j++)
                for(ll k = 0; k < 5; k++)
                    if(!table[j][k])
                        all = false;
            ll ans = (corners ? values[0] : 0) + (midline ? values[1] : 0) +
                        (diagonals ? values[2] : 0) + (all ? values[3] : 0);

            cout << ans << endl;
        }
    }
    return 0;
}

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
typedef long int ll;
typedef vector<ll> vct;
typedef vector< vct > vvct;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector< vii > ADL;
typedef bitset<1 << 20> VL;

ll gdc(ll a, ll b) {return b==0?a:gdc(b, a%b);}

int main() {
    ll T, N, M;
    cin >> T;
    for(ll i = 0; i < T; i++) {
        cin >> N >> M;
        ll gdci = gdc(N, M);
        if(N == M)
            printf("Case %ld: %ld", i+1, 2);
        else
            printf("Case %ld: %ld", i+1, N/gdci + M/gdci);
        cout << endl;
    } return 0;
}


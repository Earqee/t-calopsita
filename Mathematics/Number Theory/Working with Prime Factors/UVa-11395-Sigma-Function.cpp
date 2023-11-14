//Ask yourself when sigma is even or odd
//Tip: Take off amount of ODD sigmas numbers from result

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

#define MAX ((ll)1e12+2)

vct odd_ls;

void GenSquares() {
    ll sqrtN = sqrt(MAX)+1;
    for(ll i = 1; i < sqrtN; i++)
        odd_ls.pb(i*i), odd_ls.pb(2*i*i);
    sort(all(odd_ls));
    return;
}

int main() {
    ll N; GenSquares();
    while(cin >> N, N != 0)
        printf("%lld\n", N - (upb(all(odd_ls), N) - odd_ls.begin()));
    return 0;
}

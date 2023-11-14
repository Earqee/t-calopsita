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
    bool frt = true;
    vct arr(53);
    while(cin >> N, N != 0) {
        if(!frt)
            printf("\n");
        frt = false;
        for(ll i = 0; i < N; i++)
            cin >> arr[i];
        for(ll i = 0; i < N - 5; i++)
            for(ll j = i+1; j < N - 4; j++)
                for(ll k = j+1; k < N - 3; k++)
                    for(ll l = k+1; l < N - 2; l++)
                        for(ll r = l+1; r < N - 1; r++)
                            for(ll s = r+1; s < N; s++)
                                printf("%lld %lld %lld %lld %lld %lld\n",
                                        arr[i], arr[j], arr[k], arr[l], arr[r], arr[s]);
    }
    return 0;
}

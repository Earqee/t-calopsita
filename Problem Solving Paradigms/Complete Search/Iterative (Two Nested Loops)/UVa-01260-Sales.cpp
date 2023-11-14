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
    ll T, N, input;
    vct A(1010);
    cin >> T;
    while(T--) {
        cin >> N;
        ll sum = 0;
        for(ll i = 0; i < N; i++) {
            cin >> input;
            A[i] = input;
            ll amount = 0;
            for(ll j = i - 1; j >= 0; j--) {
                if(A[j] <= A[i])
                    amount++;
                if(j == 0)
                    sum += amount;
            }
        }
        cout << sum << endl;
    }
}

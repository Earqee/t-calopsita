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

ll arr[12];

//If you look from a  non obvious angle
//Recursive backtracking is not necessary

int main() {
    ll M, N;
    while(cin >> M >> N) {
        ll sum = 0;
        for(ll i=4; i>=0; i--) {
            if(i*M < (5-i)*N) {
                for(ll j=0; j<i; j++) {
                    arr[j]=M;
                    sum += arr[j];
                }
                for(ll j=i; j<5; j++) {
                    arr[j]=-N;
                    sum += arr[j];
                }
                break;
            }
        }
        for(ll i=5; i<12; i++) {
            arr[i] = arr[i-5];
            sum += arr[i];
        }
        if(sum > 0)
            cout << sum << endl;
        else cout << "Deficit" << endl;
    }
    return 0;
}


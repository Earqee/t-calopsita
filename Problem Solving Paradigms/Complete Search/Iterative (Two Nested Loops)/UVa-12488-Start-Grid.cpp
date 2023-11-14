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
    vct st(25), fin(25);
    ll N;
    while(cin >> N) {
        ll movem = 0;
        for(ll i = 0; i < N; i++)
            cin >> st[i];
        for(ll i = 0; i < N; i++)
            cin >> fin[i];
        for(ll i = N-1; i >= 0; i--) {
            if(st[i] != fin[i]) {
                ll stop = i;
                for(ll j = i+1; j < N; j++)
                    if(fin[j] == st[i])
                        stop = j;
                for(ll j = i; j < stop; j++)
                    swap(st[j], st[j+1]);
                movem += stop - i;
                if(stop - i)
                    i = N;
            }
        }
        cout << movem << endl;
    }
    return 0;
}

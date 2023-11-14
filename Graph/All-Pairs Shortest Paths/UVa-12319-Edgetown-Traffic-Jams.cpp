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
typedef bitset<1 << 8> VL;

vvct imin_d, fmin_d;

void FW(vvct &min_d) {
    for(ll i = 0; i < min_d.size(); i++)
        min_d[i][i] = 0;

    for(ll k = 0; k < min_d.size(); k++) {
        for(ll i = 0; i < min_d.size(); i++) {
            for(ll j = 0; j < min_d.size(); j++) {
                min_d[i][j] = min(min_d[i][j], min_d[i][k] + min_d[k][j]);
            }
        }
    }
}

int main() {
    ll N, v1, v2, A, B;
    string my_string;
    while(cin >> N, N != 0) {
        getchar();
        imin_d.resize(N);
        fmin_d.resize(N);
        for(ll i = 0; i < N; i++) {
            imin_d[i].assign(N, 1e7);
            fmin_d[i].assign(N, 1e7);
        }
        for(ll i = 0; i < N; i++) {
            getline(cin, my_string);
            istringstream ss(my_string);
            ss >> v1;
            while(ss >> v2) {
                ll u = v1-1, v = v2-1;
                //UVa sucks
                //If u put imin_d[v][u] = 1 here, u get WA
                //By context imin_d[v][u] is also true
                imin_d[u][v] = 1;
            }
        }
        for(ll i = 0; i < N; i++) {
            getline(cin, my_string);
            istringstream ss(my_string);
            ss >> v1;
            while(ss >> v2) {
                ll u = v1-1, v = v2-1;
                fmin_d[u][v] = 1;
            }
        }
        cin >> A >> B;
        FW(imin_d), FW(fmin_d);
        bool pos = true;
        for(ll i = 0; i < N; i++)
            for(ll j = 0; j < N; j++) {
                if(fmin_d[i][j] > imin_d[i][j]*A+B)
                    pos = false;
            }
        if(pos) cout << "Yes";
        else cout << "No";
        cout << endl;
    }
    return 0;
}


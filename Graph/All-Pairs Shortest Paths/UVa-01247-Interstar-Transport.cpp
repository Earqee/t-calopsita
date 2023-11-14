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
typedef vector<vct> vvct;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector< vii > ADL;
typedef bitset<1 << 8> VL;

#define MAXX ('Z'-'A'+1)

vvct min_cost;
vvct nnext, path_size;

void FloydWarshall() {
    for(ll i = 0; i < min_cost.size(); i++)
        min_cost[i][i] = 0;
    for(ll k = 0; k < min_cost.size(); k++) {
        for(ll i = 0; i < min_cost.size(); i++) {
            for(ll j = 0; j < min_cost.size(); j++) {
                if(min_cost[i][j] > min_cost[i][k] + min_cost[k][j] ||
                        (min_cost[i][j] == min_cost[i][k] + min_cost[k][j] &&
                        path_size[i][j] > path_size[i][k] + path_size[k][j])) {
                    min_cost[i][j] = min_cost[i][k] + min_cost[k][j];
                    nnext[i][j] = nnext[i][k];
                    path_size[i][j] = path_size[i][k] + path_size[k][j];
                }
            }
        }
    }
    return;
}

void printPath(ll source, ll dest) {
    ll current = source;
    while(current != dest) {
        printf("%c ", current + 'A');
        current = nnext[current][dest];
    }
    printf("%c", current + 'A');
    return;
}

int main() {
    ll S, P, N, cost;
    char v1, v2;
    while(cin >> S >> P) {
        //Alloc
        nnext.resize(MAXX), path_size.resize(MAXX), min_cost.resize(MAXX);
        for(ll i = 0; i < MAXX; i++) {
            min_cost[i].assign(MAXX, INT_MAX);
            nnext[i].assign(MAXX, -1);
            path_size[i].assign(MAXX, INT_MAX);
        }
        //Read
        for(ll i = 0; i < P; i++) {
            cin >> v1 >> v2 >> cost;
            ll u = v1 -'A';
            ll v = v2 -'A';
            min_cost[u][v] = min_cost[v][u] = cost;
            path_size[u][v] = path_size[v][u] = 1;
            nnext[u][v] = v, nnext[v][u] = u;
        }
        //Compute
        FloydWarshall();
        //Answer Queries
        cin >> N;
        for(ll i = 0; i < N; i++) {
            if(i) cout << endl;
            cin >> v1 >> v2;
            printPath(v1-'A', v2-'A');
        }
        cout << endl;
    }
    return 0;
}


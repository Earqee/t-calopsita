#include <bits/stdc++.h>

#define EMPTY (-1)
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

vvct graph;
int  *visited, *color;
int CC_count[2]; enum col{WHITE, BLACK};
int isBipartite;

void dfs(int A) {
    visited[A] = 1;
    CC_count[color[A]]++;
    int v;
    for(int i = 0; i < graph[A].size(); i++) {
        v = graph[A][i];
        if(color[v] == EMPTY) {
            color[v] = 1 - color[A];
            if(!visited[v]) dfs(v);
        } else if(color[v] == color[A]) {
            isBipartite = 0;
        }
    }
}

int main() {
    int T, N, P, enemy, answer;
    cin >> T;
    for(int t = 0; t < T; t++) {
        cin >> N;
        graph.clear(), graph.resize(N);
        visited = (int*) calloc(N, sizeof(int));
        color = (int*) malloc(N * sizeof(int));
        for(int i = 0; i < N; i++)
            color[i] = EMPTY;
        answer = 0;
        for(int n = 0; n < N; n++) {
            cin >> P;
            for(int p = 0; p < P; p++) {
                cin >> enemy;
                if(enemy - 1 < N) {
                graph[n].pb(enemy - 1);
                graph[enemy - 1].pb(n);
                }
            }
        }
        for(int i = 0; i < N; i++) {
            if(!visited[i]) {
                isBipartite = 1;
                CC_count[WHITE] = CC_count[BLACK] = 0;
                color[i] = 0;
                dfs(i);
                if(isBipartite)
                    answer += max(CC_count[WHITE], CC_count[BLACK]);
            }
        }
        cout << answer << endl;
        free(visited), free(color);
    }
}

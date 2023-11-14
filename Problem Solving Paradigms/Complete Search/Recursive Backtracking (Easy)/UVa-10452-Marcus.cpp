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
typedef vector<char> vct;
typedef vector< vct > vvct;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector< vii > ADL;
typedef bitset<1 << 20> VL;

ll dx[] = {-1, 0, 0};
ll dy[] = {0, -1, 1};
string words[] = {"forth", "left", "right"};
ll comp[] = {'I', 'E', 'H', 'O', 'V', 'A', '#'};

vvct lab, vis;

bool valid(ll i, ll j) {
    return i >= 0 && i < lab.size() &&
        j >= 0 && j < lab[0].size();
}

void solve(ll i, ll j, ll r) {
    for(ll k=0; k<3; k++) {
        if(valid(i+dx[k], j+dy[k]) &&
            !vis[i+dx[k]][j+dy[k]] &&
            lab[i+dx[k]][j+dy[k]] == comp[r]) {
            if(lab[i][j] != '@')
                cout << ' ';
            vis[i+dx[k]][j+dy[k]] = 1;
            cout << words[k];
            solve(i+dx[k], j+dy[k], r+1);
        }
    }
}

int main() {
    ll T, M, N;
    string str;
    cin >> T;
    while(T--) {
        cin >> M >> N;
        getchar();
        lab.resize(M), vis.resize(M);
        for(ll i=0; i<M; i++) {
           getline(cin, str);
           lab[i].resize(N), vis[i].assign(N, 0);
           for(ll k=0; k<N; k++)
               lab[i][k] = str[k];
        }
        for(ll i=0; i<N; i++)
            if(lab[M-1][i] == '@')
                solve(M-1, i, 0);
        cout << endl;
    }
    return 0;
}

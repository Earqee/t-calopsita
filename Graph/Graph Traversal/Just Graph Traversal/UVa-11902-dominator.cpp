#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <limits.h>
#include <math.h>
#include <list>
#include <iomanip>

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
typedef int ll;
typedef pair<ll, ll> ii; 
typedef vector< ii > vii;
typedef vector<vii> AdjList;  
typedef bitset<1<<8> MarkedList;
typedef vector<vector<ll> > List; 

AdjList adjlist;
MarkedList visited, can_go, possible;
ll N, M, save;
ll **ma, **dom;    
vector<ll> queue;
bool found;

void alloc() {
    ma = new ll*[M]; dom = new ll*[M];
    for(ll i = 0; i < M; i++) {
        ma[i] = new ll[M]();
        dom[i] = new ll[M]();
    } return;
}

void reset() {
    visited.set(), visited.flip();
    can_go.set(); save = found = 0;
    return; 
}

void print() {    
    for(ll i = 0; i < M; i++) {
        for(ll j = 0; j < 2*M + 1; j++) {
            if(j == 0 || j + 1 == 2*M + 1) cout << '+';
            else cout << '-';
        }
        cout << endl;
        cout << '|';
        for(ll j = 0; j < M; j++) {
            if(dom[i][j]) cout << "Y|";
            else cout << "N|";
        }
        cout << endl;
    }
    for(ll i = 0; i < 2*M + 1; i++) {
        if(i == 0 || i + 1 == 2*M + 1) cout << '+';
        else cout << '-';
    }   
    cout << endl; return;
}

void bfs(ll u, ll k) {
    if(can_go[u]) {
        visited[u] = 1;
        if(u == k) found = true;
        for(ll j = 0; j < adjlist[u].size() && !found; j++) {
            ll cur = adjlist[u][j].first;
            if(!visited[cur] && can_go[u]) 
                bfs(cur, k);
        }
    }
}

int main() {  
    cin >> N; ll num;
    for(ll r = 0; r < N; r++) {
        cin >> M;
        adjlist.resize(1 << 8);
        adjlist.clear();
        alloc(); reset();

        for(ll k = 0; k < M; k++) {
            for(ll j = 0; j < M; j++) {
                cin >> num;
                if(num) adjlist[k].pb(make_pair(j,0));
            }
        }
        save = 1; bfs(0, -1);
        for(ll k = 0; k < visited.size(); k++) {
            possible.set(k, visited[k]);
        } 
        
        for(ll k = 0; k < M; k++) {
            if(possible[k]) {
                for(ll j = 0; j < M; j++) {
                    reset(), can_go.set(j, 0), bfs(0, k);
                    if(!visited[k]) dom[j][k] = 1;
                }
            }
        }     
        printf("Case %d:\n", r + 1), print();
        delete[] ma, delete[] dom;
     }
    return 0;
}
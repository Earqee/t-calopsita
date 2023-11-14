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

#define pb push_back
using namespace std;
typedef char ch;
typedef pair<ch, ch> ii; 
typedef vector< ii > vii;
typedef vector<vii> AdjList;  
typedef bitset<1<<20> MarkedList;
typedef long long unsigned int li;

vector<char> ans;
AdjList adjlist;
MarkedList candy;
li K, cont;
bool trapped;

bool read() {
    char N, M;
    adjlist.resize(1 << 10);
    while(cin >> N, N != '#') 
        while(cin >> M, M != ';') {
            if(M == '.') return true;
            if(M != ':') adjlist[N].pb(make_pair(M, '0'));
    } return false;
}

int main() {
    char i_min, i_the; li j;    
    while(read()) {
        while(cin >> i_min, i_min == ' ');
        while(cin >> i_the, i_min == ' ');
        cin >> K; 
        candy.set(); candy.flip(); 

        for(li j = 0, cont = K, trapped = false; !trapped; ) {
            if(adjlist[i_min].size()) {
                if(!candy[adjlist[i_min][j].first] && adjlist[i_min][j].first != i_the) {
                    i_the = i_min;
                    i_min = adjlist[i_min][j].first;
                    j = 0;
                    if(!(--cont)) {
                        candy.set(i_the, true);
                        ans.pb(i_the);
                        cont = K;
                    } continue;
                } else if (j + 1 == adjlist[i_min].size()) {
                        ans.pb(i_min);
                        trapped = true;
                } else j++;
            } else {
                ans.pb(i_min);
                trapped = true;
            }
        }    

        for(li i = 0; i < ans.size(); i++) {
            if(i) cout << ' ';
            if(i + 1 == ans.size()) cout << '/';
            cout << ans.at(i);
        }
        ans.clear(); adjlist.clear(); trapped = false;
        cout << endl;
    }
    return 0;
}

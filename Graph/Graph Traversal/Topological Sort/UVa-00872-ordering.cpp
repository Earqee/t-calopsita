#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <limits.h>
#include <math.h>
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
typedef vector < string > vvct;
typedef pair<char, char> ii;
typedef vector<ii> vii;
typedef bitset<1 << 8> VL;

bool printed_something;

bool can_place(string &answer, vvct &cannot, char A) {
    int cannot_size = cannot[A].size();
    int answer_size = answer.size();
    for(int i = 0; i < cannot_size; i++) {
        for(int j = 0; j < answer_size; j++)
            if(cannot[A][i] == answer[j]) return false;
    }
    return true;
}

void mount(string &list, string &answer, vvct &cannot, VL &used) {
    char curr;
    if(answer.size() == list.size()) {
        for(int j = 0; j < answer.size(); j++) {
            if(j) cout << ' ';
            cout << answer[j];
        } cout << endl;
        printed_something = true;
    } else {
        for(int i = 0; i < list.size(); i++) {
            curr = list[i];
            if(!used[curr] && can_place(answer, cannot, curr)) {
                answer.pb(curr);
                used[curr] = 1;
                mount(list, answer, cannot, used);
                used[curr] = 0;
                answer.pp();
            }
        }
    }
}

int main() {
    string list, answer;
    VL used; vvct cannot;
    char M, N;
    int C; cin >> C; getchar();
    for(int i = 0; i < C; i++) {
        if(i) cout << endl;
        printed_something = false;
        list.clear(), cannot.clear(), used.reset();
        cannot.resize('Z' + 1);
        getchar();
        while(scanf("%c", &N), N != '\n')
            if(N >= 'A' && N <= 'Z') list.pb(N);
        sort(all(list));
        while(scanf("%c", &N), N != '\n') {
            if(N >= 'A' && N <= 'Z') {
                while(scanf("%c", &M), M == '<');
                cannot[N].pb(M);
            }
        }

        mount(list, answer, cannot, used);
        if(!printed_something) cout << "NO" << endl;
    }
}


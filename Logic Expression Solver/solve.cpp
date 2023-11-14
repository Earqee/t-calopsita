//Copyright 2018, Thiago José, All rights reserved;

#include <bits/stdc++.h>

#define pb push_back
using namespace std;
typedef vector<unsigned> vct;
typedef unsigned bit;

bit X, Y;
string entry;

void eval(unsigned m) {
    for(int i = 0; i < entry.size(); i++)
        if(entry[i] == '(')
            for(int j = i; i < entry.size(); j++)
                if(entry[j] == ')') {
                    entry.erase(entry.begin() + i);
                    entry.erase(entry.begin() + j - 1);
                    eval(i);
                    break;
                }

    vct answer; char oper; bit flip = 0;
    if(entry.size() >= 3) {
        while(answer.size() < 2) {
            if(entry[m] == '~') {
                flip = !flip;
            } else {
                if(entry[m] == '1') answer.pb(1);
                else if(entry[m] == '0') answer.pb(0);
                else if(entry[m] == 'X') answer.pb(X);
                else if(entry[m] == 'Y') answer.pb(Y);
                else oper = entry[m];
                if((entry[m] == '1' || entry[m] =='0' ||
                   entry[m] == 'X' || entry[m] == 'Y') && flip) {
                    answer.back() = !answer.back();
		    flip = !flip;
		}
            }
            entry.erase(entry.begin() + m);
        }
        unsigned AND =  answer.front() && answer.back(),
                 OR  =  answer.front() || answer.back(),
                 NAND = (answer.front() == answer.back() ? 1 : 0),
                 NOR  = (answer.front() != answer.back() ? 1 : 0),
                 IMP = (!answer.front()) || answer.back(),
                 SSE = (((!answer.front()) || answer.back()) && ((!answer.back()) || answer.front()));
        if(oper == '.') entry.insert(m, to_string(AND));
        else if(oper == '+') entry.insert(m, to_string(OR));
        else if(oper == '&') entry.insert(m, to_string(NAND));
        else if(oper == '|') entry.insert(m, to_string(NOR));
        else if(oper == '>') entry.insert(m, to_string(IMP));
        else if(oper == '=') entry.insert(m, to_string(SSE));
    } else {
        if(entry.size() == 2) {
            entry.erase(entry.begin()+m);
            flip = 1;
        }
        if(entry[m] == '1') answer.pb(1);
        else if(entry[m] == '0') answer.pb(0);
        else if(entry[m] == 'X') answer.pb(X);
        else if(entry[m] == 'Y') answer.pb(Y);
        if(flip) {
            entry[m] = !answer.front() + '0';
        } else entry[m] = answer.front() + '0';
    }
    return;
}

void printTable(string &entry) {
    cout << endl << "Truth table: " << endl;
    unsigned result, entry_size = entry.size();
    string backup(entry), spaces, barrier;
    for(int i = 0; i < entry.size()/2; i++)
        spaces.pb(' ');
    for(int i = 0; i < 12 + entry_size; i++) barrier.pb('#');
    cout << barrier << endl << "# X |" << " Y | " << entry << " #" << endl << barrier << endl;
    for(int i = 0; i <= 1 ; i++)
        for(int j = 0; j <= 1; j++) {
            X = i, Y = j;
            eval(0);
            if(entry.front() == '1') result = 1;
            else result = 0;
            cout << "# " << (1-i?'F':'V') << " | " << (1-j?'F':'V') << " | "
                 << spaces << (1-result?'F':'V') << spaces << " #" << endl;
            entry = backup;
        }
    cout << barrier << endl;
    return;
}

int main() {
    char key;
    cout << "Copyright 2018, Thiago José, All rights reserved ~ github.com/thiagoj0se" << endl
         << "Attention! Give procedence to everything! All expressions need to be put inside brackets. Ex: ((X+Y).X)" << endl
         << "Guide: . is AND, + is OR, ~ is NOT, & is XAND, | is XOR, > is IMP, = is SSE" << endl
         << "Only expressions with X and Y! ~ Ex: (((X.~Y)+X).((~X&Y)+X)) is correct!" << endl;
    cout << endl << "Enter your expression: ";
    while(scanf("%c", &key), key != '\n') {
        if(key != ' ') entry.pb(key);
    }
    printTable(entry);
    return 0;
}


#include <bits/stdc++.h>
#include <ilcplex/ilocplex.h>
#define E 1e-7
using namespace std;
ILOSTLBEGIN

int main() {

    try {
        IloEnv env;
        IloModel model(env);
        IloCplex blackBox(model);

        long worktime, days;
        cin >> worktime >> days;
        long day[days];
        for(long i=0;i<days;i++)
            cin >> day[i];

        IloIntVarArray x(env, days, 0, IloInfinity);

        for(long i=0; i<days;i++) {
            IloExpr expr(env);
            for(long j=0;j<worktime;j++)
                expr += x[(i-j)%worktime];
            model.add(expr>=day[i]);
        }

        IloExpr obj(env);
        for(long i=0;i<days;i++)
            obj+=x[i];
        model.add(IloMinimize(env, obj));

        if(blackBox.solve() == IloTrue)
            cout << "Opt: " << blackBox.getObjValue() << endl;
        else
            printf("No solution.");
        env.end();
    }
    catch(IloException &e) {
        cerr << "Exception: " << e << endl;
    }

    return 0;
}



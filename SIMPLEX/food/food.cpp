#include <bits/stdc++.h>
#include <ilcplex/ilocplex.h>
using namespace std;
ILOSTLBEGIN

int main() {

    try {
        IloEnv env;
        IloModel model(env);
        IloCplex blackBox(model);
        IloIntVar x(env, 0, IloInfinity);
        IloIntVar y(env, 0, IloInfinity);
        long C[2], E[2], V[2], Q[2];
        for(long i=0;i<2;i++)
            cin >> C[i] >> E[i] >> V[i] >> Q[i];

        model.add(IloExpr(C[0]*x + C[1]*y) <= Q[0]);
        model.add(IloExpr(E[0]*x + E[1]*y) <= Q[1]);

        model.add(IloMaximize(env, (V[0]-C[0]-E[0])*x + (V[1]-C[1]-E[1])*y));

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



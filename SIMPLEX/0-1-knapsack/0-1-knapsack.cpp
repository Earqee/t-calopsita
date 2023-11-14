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

        long N, C;
        cin >> N >> C;
        long v[N], w[N];
        for(long i=0;i<N;i++)
            cin >> v[i] >> w[i];

        IloBoolVarArray x(env, N);

        IloExpr expr;
        for(long i=0;i<N;i++)
            expr += w[i]*x[i];
        model.add(expr <= C);

        IloExpr obj;
        for(long i=0;i<N;i++)
            obj+=v[i]*x[i];
        model.add(IloMaximize(env, obj));

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



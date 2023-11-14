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

        long facts, conts;
        cin >> facts >> conts;
        long fact[facts], cont[conts];
        for(long i=0; i<facts; i++)
            cin >> fact[i];
        for(long j=0; j<cont; j++)
            cin >> fact[j];
        long C[facts][conts];
        for(long i=0;i<facts;i++)
            for(long j=0;j<facts;j++)
                cin >>C[i][j];

        IloArray<IloIntVarArray> x(env, facts);
        for(long i=0;i<facts;i++)
            x[i]=IloIntVarArray(end, conts, 0, IloInfinity);

        for(long i=0;i<facts;i++) {
            IloExpr expr(env);
            for(long j=0; j<conts;j++)
                expr += x[i][j];
            model.add(expr <= fact[i]);
        }
        for(long j=0;j<conts;j++) {
            IloExpr expr(env);
            for(long i=0;i<facts;i++)
                expr += x[i][j];
            model.add(expr == cont[j]);
        }

        IloExpr obj(env);
        for(long i=0;i<facts; i++)
            for(long j=0;j<conts;j++)
                obj+=C[i][j]*x[i][j];
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



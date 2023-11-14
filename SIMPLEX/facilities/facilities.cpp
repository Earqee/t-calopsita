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

        long centers, clients, bigM=0;
        cin >> centers >> clients;
        long C[centers], F[centers][clients];
        for(long i=0;i<centers;i++)
            cin>>C[i];
        for(long i=0;i<centers;i++)
            for(long j=0;j<clients;j++) {
                cin>>F[i][j];
                bigM=max(bigM, F[i][j]*clients);
            }

        IloBoolVarArray x(env, centers);
        IloArray<IloBoolVarArray> y(env, centers);
        for(long i=0;i<centers;i++)
            y[i] = IloBoolVarArray(env, clients);

        for(long j=0;j<clients;j++) {
            IloExpr expr(env);
            for(long i=0;i<centers;i++)
                expr += y[i][j];
            model.add(expr == 1);
        }

        for(long i=0;i<centers;i++) {
            IloExpr expr(env);
            for(long j=0;j<clients;j++)
                expr+=y[i][j];
            model.add(expr <= bigM);
        }

        IloExpr obj(env);
        for(long i=0;i<centers;i++)
            obj+=C[i]*x[i];
        for(long i=0;i<centers;i++)
            for(long j=0;j<clients;j++)
                obj += F[i][j]*y[i][j];

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



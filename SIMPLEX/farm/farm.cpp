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

        long farms, cultures;
        cin >> farms >> cultures;
        struct T1 { double A, W; };
        struct T2 { double maxA, WpA, L; };
        T1 farm[farms];
        T2 culture[cultures];
        for(long i=0; i<farms; i++)
            cin >> farm[i].A >> farm[i].W;
        for(long j=0;j<cultures;j++)
            cin>>culture[j].maxA>>culture[j].WpA>>culture[j].L;

        IloArray<IloNumVarArray> x(env, farms);
        for(long i=0; i<cultures; i++)
            x[i]=IloNumVarArray(env, cultures, 0, IloInfinity);

        for(long i=0; i<farms; i++) {
            IloExpr expr(env);
            for(long j=0; j<cultures; j++)
                expr += x[i][j];
            model.add(expr <= farm[i].A);
        }
        for(long j=0;j<cultures;j++) {
            IloExpr expr(env);
            for(long i=0;i<farms;i++)
                expr += x[i][j];
            model.add(expr <= culture[j].maxA);
        }
        for(long i=0;i<farms;i++) {
            IloExpr expr(env);
            for(long j=0;j<cultures;j++)
                expr += culture[j].WpA*x[i][j];
            model.add(expr <= farm[i].W);
        }
        IloExpr exprS(env);
        for(long j=0; j<cultures; j++)
            exprS += x[0][j];
        exprS /= farm[0].A;
        for(long i=1;i<farms;i++) {
            IloExpr expr(env);
            for(long j=0; j<cultures; j++)
                expr += x[i][j];
            model.add(expr == exprS);
        }
        IloExpr obj(env);
        for(long j=0; j<cultures; j++)
            for(long i=0; i<farms; i++)
                obj+=culture[j].L*x[i][j];
        model.add(IloMaximize(env, obj));

        if(blackBox.solve()==IloTrue)
            cout<<"Opt: "<<blackBox.getObjValue()<<endl;
        else
            printf("No solution.");
        env.end();
    }
    catch(IloException &e) {
        cerr << "Exception: " << e << endl;
    }

    return 0;
}



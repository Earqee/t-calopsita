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

        long vit, ing;
        cin >> vit >> ing;
        long Q[vit][ing], minQ[vit], price[ing];
        for(long i=0;i<vit;i++)
            cin >> minQ[i];
        for(long j=0;j<ing;j++)
            cin>> price[j];
        for(long i=0;i<vit;i++)
            for(long j=0;j<ing;j++)
                cin >> Q[i][j];

        IloIntVarArray x(env, ing, 0, IloInfinity);

        for(long i=0;i<vit;i++) {
            IloExpr expr(env);
            for(long j=0;j<ing;j++)
                expr += Q[i][j]*x[j];
            model.add(expr>=minQ[i]);
        }

        IloExpr obj(env);
        for(long i=0;i<ing;i++)
            obj+=price[i]*x[i];
        model.add(IloMinimize(env, obj));

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



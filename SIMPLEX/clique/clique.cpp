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

        long N, M, in, out;
        cin >> N >> M;
        long P[N][M] = {0};
        for(long j=0;j<M;j++) {
            cin >> in >> out;
            P[in][out]=P[out][in]=1;
        }

        IloBoolVarArray x(env, N);

        #define V (N)

        for(long i=0;i<V; i++)
            for(long j=i+1;j<V;j++)
                if(!P[i][j])
                    model.add(x[i] + x[j] <= 1);

        IloExpr obj;
        for(long i=0;i<V;i++)
            obj+=x[i];
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



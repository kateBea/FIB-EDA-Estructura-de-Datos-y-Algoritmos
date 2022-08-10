//TASK ORDERING     P16249

#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

typedef vector< vector<int> > graph;

int main()
{
    int n;
    while (cin >> n) {
        //contenedores de mis tareas
        vector<string> nom_tareas(n);
        map<string, int> pos_tareas;


        //lectura de la serie de strings
        for (int i = 0; i < n; ++i) {
            string s; cin >> s;
            nom_tareas[i] = s;
            pos_tareas[s] = i;
        }

        //defino grafo de n vertices
        graph g(n);
        int m; cin >> m;

        //este vector contabiliza cuantos arcos apuntan al vertice en
        //posicion i-esima (dependencias)
        vector<int> ge(n, 0);

        //genero mi grafo dirigido
        //aañado solo una dependencia (no hay que añaadir arco en direccion contraria)
        for (int i = 0; i < m; ++i) {
            string x, y;
            cin >> x >> y;
            g[pos_tareas[x]].push_back(pos_tareas[y]);
            ++ge[pos_tareas[y]];
        }

        //vector que contiene la salida
        vector<string> output; 

        //gurdo las tareas que ya puedo realizar en esta cola
        priority_queue<string, vector<string>, greater<string>> Q;

        for (int i = 0; i < n; ++i) {
            if (ge[i] == 0) Q.push(nom_tareas[i]);
        }

        while (not Q.empty()) {
            string s = Q.top();
            Q.pop();
            output.push_back(s);
            int u = pos_tareas[s];
            for (unsigned int j = 0; j < g[u].size(); ++j) {
                int v = g[u][j];
                if (--ge[v] == 0) Q.push(nom_tareas[v]);
            }
        }

        if (output.size() == n) { //hay solucion
            for (auto i : output) cout << i;
            cout << endl;
        }
        else cout << "NO VALID ORDERING" << endl;

    }
}
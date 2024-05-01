#include <iostream.h>
#include <fstream.h>

#define INF 9999
#define V 5

int G[V][V] = {
    {0, 3, 0, 3, 0},
    {3, 0, 0, 0, 4},
    {0, 0, 0, 2, 1},
    {3, 3, 2, 0, 0},
    {0, 4, 1, 0, 0}
};

int main() {
    int num_edge = 0;
    int mst_vertex[V];
    for (int i = 0; i < V; i++) {
        mst_vertex[i] = 0;
    }
    mst_vertex[0] = 1;
    int x, y;
    char ch;

    cout << "The Minimum Spanning Tree as per Prim's Algorithm:" << endl;
    cout << "Edge : Weight" << endl;
    
    while (num_edge < V - 1) {
        int min = INF;
        x = 0;
        y = 0;

        for (int i = 0; i < V; i++) {
            if (mst_vertex[i]) {
                for (int j = 0; j < V; j++) {
                    if (!mst_vertex[j] && G[i][j] && min > G[i][j]) {
                        min = G[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        cout << x << " - " << y << " : " << G[x][y] << endl;
        mst_vertex[y] = 1;
        num_edge++;
    }

    ifstream file("cstring.txt");
    if (!file) {
        cout << "Error opening file!";
        return 1;
    }

    while (file.get(ch)) {
        cout.put(ch);
    }
    file.close();

    return 0;
}

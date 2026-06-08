#include <iostream>
using namespace std;

class GraphMatrix {
private:
    int** adjMatrix;
    int vertices;

public:
    GraphMatrix(int v) {
        vertices = v;
        adjMatrix = new int*[vertices];
        for (int i = 0; i < vertices; i++) {
            adjMatrix[i] = new int[vertices];
            for (int j = 0; j < vertices; j++) {
                adjMatrix[i][j] = 0;
            }
        }
    }

    void addEdge(int i, int j) {
        adjMatrix[i][j] = 1;
        adjMatrix[j][i] = 1;
        cout << "Edge added between " << i << " and " << j << endl;
    }

    void removeEdge(int i, int j) {
        adjMatrix[i][j] = 0;
        adjMatrix[j][i] = 0;
        cout << "Edge removed between " << i << " and " << j << endl;
    }

    void display() {
        cout << "\nAdjacency Matrix:\n   ";
        for (int i = 0; i < vertices; i++) {
            cout << i << " ";
        }
        cout << endl;

        for (int i = 0; i < vertices; i++) {
            cout << i << "  ";
            for (int j = 0; j < vertices; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    ~GraphMatrix() {
        for (int i = 0; i < vertices; i++) {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    }
};

int main() {
    int vertices, edges, u, v;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    GraphMatrix g(vertices);

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter " << edges << " edges (format: u v):" << endl;
    for (int i = 0; i < edges; i++) {
        cout << "Edge " << i + 1 << ": ";
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.display();

    cout << "\nEnter edge to remove (format: u v): ";
    cin >> u >> v;
    g.removeEdge(u, v);
    g.display();

    return 0;
}

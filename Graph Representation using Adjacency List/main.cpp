#include <iostream>
#include <list>
using namespace std;

class Graph {
private:
    int n;
    list<int>* adj;

public:
    Graph(int v) {
        n = v;
        adj = new list<int>[v];
    }

    void add(int i, int j) {
        adj[i].push_back(j);
        adj[j].push_back(i);
        cout << "Added: " << i << "-" << j << endl;
    }

    void remove(int i, int j) {
        adj[i].remove(j);
        adj[j].remove(i);
        cout << "Removed: " << i << "-" << j << endl;
    }

    void show() {
        cout << "\nAdjacency List:\n";
        for (int i = 0; i < n; i++) {
            cout << i << ": ";
            for (int x : adj[i]) {
                cout << x << " ";
            }
            cout << endl;
        }
    }

    void DFS(int start) {
        bool* vis = new bool[n];
        for (int i = 0; i < n; i++) vis[i] = false;

        cout << "DFS: ";
        DFShelp(start, vis);
        cout << endl;

        delete[] vis;
    }

    void DFShelp(int v, bool vis[]) {
        vis[v] = true;
        cout << v << " ";

        for (int x : adj[v]) {
            if (!vis[x]) {
                DFShelp(x, vis);
            }
        }
    }

    void BFS(int start) {
        bool* vis = new bool[n];
        for (int i = 0; i < n; i++) vis[i] = false;

        list<int> q;
        vis[start] = true;
        q.push_back(start);

        cout << "BFS: ";
        while (!q.empty()) {
            int v = q.front();
            q.pop_front();
            cout << v << " ";

            for (int x : adj[v]) {
                if (!vis[x]) {
                    vis[x] = true;
                    q.push_back(x);
                }
            }
        }
        cout << endl;

        delete[] vis;
    }

    ~Graph() {
        delete[] adj;
    }
};

int main() {
    int v, e, x, y, start;

    cout << "Vertices: ";
    cin >> v;

    Graph g(v);

    cout << "Edges: ";
    cin >> e;

    cout << "Enter edges:\n";
    for (int i = 0; i < e; i++) {
        cout << i+1 << ": ";
        cin >> x >> y;
        g.add(x, y);
    }

    g.show();

    cout << "\nStart vertex for DFS/BFS: ";
    cin >> start;
    g.DFS(start);
    g.BFS(start);

    cout << "\nRemove edge: ";
    cin >> x >> y;
    g.remove(x, y);
    g.show();

    return 0;
}

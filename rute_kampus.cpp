#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <string>
#include <cctype>
using namespace std;

class Graph
{
private:
    int V;
    vector<vector<int>> adjMatrix;

public:
    Graph(int jumlahVertex)
    {
        V = jumlahVertex;
        adjMatrix.resize(V, vector<int>(V, 0));
    }

    void addEdge(int i, int j, int weight)
    {
        if (i >= 0 && i < V && j >= 0 && j < V)
        {
            adjMatrix[i][j] = weight;
            adjMatrix[j][i] = weight;
        }
        else
        {
            cout << "Index nonvalid" << endl;
        }
    }

    void printAdjMatrix()
    {
        cout << "  ";
        for (int i = 0; i < V; i++)
            cout << char('A' + i) << " ";
        cout << endl;

        for (int i = 0; i < V; i++)
        {
            cout << char('A' + i) << " ";
            for (int j = 0; j < V; j++)
            {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void bfs(int startVertex)
    {
        vector<bool> visited(V, false);
        queue<int> titikVisit;

        visited[startVertex] = true;
        titikVisit.push(startVertex);

        cout << "BFS dari " << char('A' + startVertex) << " : ";
        while (!titikVisit.empty())
        {
            int currentVertex = titikVisit.front();
            titikVisit.pop();
            cout << char('A' + currentVertex) << " ";

            for (int i = 0; i < V; i++)
            {
                if (adjMatrix[currentVertex][i] != 0 && !visited[i])
                {
                    visited[i] = true;
                    titikVisit.push(i);
                }
            }
        }
        cout << endl;
    }

    void dfs(int startVertex)
    {
        vector<bool> visited(V, false);
        cout << "DFS dari " << char('A' + startVertex) << " : ";
        dfsUntil(startVertex, visited);
        cout << endl;
    }

    void dfsUntil(int currentVertex, vector<bool> &visited)
    {
        visited[currentVertex] = true;
        cout << char('A' + currentVertex) << " ";

        for (int i = 0; i < V; i++)
        {
            if (adjMatrix[currentVertex][i] != 0 && !visited[i])
            {
                dfsUntil(i, visited);
            }
        }
    }

    void dijkstra(int source, int tujuan)
    {
        vector<int> distance(V, INT_MAX);
        vector<int> previous(V, -1);
        vector<bool> visited(V, false);
        distance[source] = 0;

        for (int i = 0; i < V; i++)
        {
            int u = -1;

            for (int j = 0; j < V; j++)
            {
                if (!visited[j] && (u == -1 || distance[j] < distance[u]))
                {
                    u = j;
                }
            }

            if (u == -1 || distance[u] == INT_MAX)
                break;

            visited[u] = true;

            for (int v = 0; v < V; v++)
            {
                if (adjMatrix[u][v] != 0 && !visited[v])
                {
                    int newDistance = distance[u] + adjMatrix[u][v];

                    if (newDistance < distance[v])
                    {
                        distance[v] = newDistance;
                        previous[v] = u;
                    }
                }
            }
        }

        if (distance[tujuan] == INT_MAX)
        {
            cout << "Rute ke " << char('A' + tujuan) << " tidak ditemukan" << endl;
            return;
        }

        vector<int> path;
        for (int v = tujuan; v != -1; v = previous[v])
            path.push_back(v);

        cout << "Rute         : ";
        for (int i = path.size() - 1; i >= 0; i--)
        {
            cout << char('A' + path[i]);
            if (i > 0) cout << " -> ";
        }
        cout << endl;
        cout << "Total jarak  : " << distance[tujuan] << endl;
    }
};

int bacaVertex(string pesan)
{
    char c;
    while (true)
    {
        cout << pesan;
        cin >> c;
        c = toupper(c);
        if (c >= 'A' && c <= 'F')
            return c - 'A';
        cout << "Vertex tidak valid (A-F)" << endl;
    }
}

int main()
{
    Graph graph(6);

    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 2, 2);
    graph.addEdge(1, 2, 1);
    graph.addEdge(1, 3, 5);
    graph.addEdge(1, 4, 3);
    graph.addEdge(2, 3, 8);
    graph.addEdge(2, 4, 6);
    graph.addEdge(3, 4, 2);
    graph.addEdge(3, 5, 4);
    graph.addEdge(4, 5, 3);

    int pilihan;
    do
    {
        cout << "\n=== PENCARIAN RUTE KAMPUS ===" << endl;
        cout << "1. Tampilkan adjacency matrix" << endl;
        cout << "2. BFS" << endl;
        cout << "3. DFS" << endl;
        cout << "4. Dijkstra (rute terpendek)" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih : ";
        cin >> pilihan;

        if (pilihan == 1)
            graph.printAdjMatrix();
        else if (pilihan == 2)
            graph.bfs(bacaVertex("Vertex awal (A-F) : "));
        else if (pilihan == 3)
            graph.dfs(bacaVertex("Vertex awal (A-F) : "));
        else if (pilihan == 4)
        {
            int awal = bacaVertex("Vertex awal (A-F)   : ");
            int tujuan = bacaVertex("Vertex tujuan (A-F) : ");
            graph.dijkstra(awal, tujuan);
        }

        system("pause");
        system("cls");
    } while (pilihan != 0);

    return 0;
}

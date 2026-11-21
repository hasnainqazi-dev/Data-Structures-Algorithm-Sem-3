#include<iostream>
#include<list>
using namespace std;

class ListGraph
{
public:
    int V;
    list<pair<int, int>>* adj;
    ListGraph(int V)
    {
        this->V = V;
        adj = new list<pair<int, int>>[V];
    }
    void addEdge(int u, int v, int w)
    {
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    ~ListGraph()
    {
        delete[] adj;
    }
};
void BFS(ListGraph& g, int start)
{
    bool* visited = new bool[g.V];
    for (int i = 0; i < g.V; i++)
        visited[i] = false;
    list<int> q;           
    visited[start] = true;
    q.push_back(start);
    while (!q.empty())
    {
        int u = q.front();
        q.pop_front();
        cout << char('A' + u) << " ";

        for (pair<int, int> p : g.adj[u])
        {
            int v = p.first;
            if (!visited[v])
            {
                visited[v] = true;
                q.push_back(v);
            }
        }
    }
    cout << endl;
    delete[] visited;
}
void DFSUtil(ListGraph& g, int u, bool visited[])
{
    visited[u] = true;
    cout << char('A' + u) << " ";

    for (pair<int, int> p : g.adj[u])
    {
        int v = p.first;
        if (!visited[v])
            DFSUtil(g, v, visited);
    }
}
void DFS(ListGraph& g, int start)
{
    bool* visited = new bool[g.V];
    for (int i = 0; i < g.V; i++)
        visited[i] = false;

    DFSUtil(g, start, visited);
    cout << endl;
    delete[] visited;
}

int main()
{
    ListGraph graph(6);

    graph.addEdge(0, 1, 3);   
    graph.addEdge(0, 3, 3);   
    graph.addEdge(0, 5, 6);  
    graph.addEdge(1, 3, 1);   
    graph.addEdge(1, 4, 3);  
    graph.addEdge(2, 4, 2);  
    graph.addEdge(2, 5, 3);   
    graph.addEdge(3, 4, 1);  
    graph.addEdge(3, 5, 2);  
    graph.addEdge(4, 5, 5);   

    cout << "--- Graph Traversals ---" << endl << endl;
    cout << "BFS Traversal starting from A: ";
    BFS(graph, 0);
    cout << endl << "DFS Traversal starting from A: ";
    DFS(graph, 0);

    return 0;
}
#include<iostream>
#include<list>
using namespace std;

class graph
{
private:
    int v;
    list<int>* l;

public:
    graph(int v)
    {
        this->v = v;
        l = new list<int>[v];
    }

    void addedge(char u, char v)
    {
        int idxU = u - 'A';
        int idxV = v - 'A';

        l[idxU].push_back(idxV);
        l[idxV].push_back(idxU);
    }

    void printadjlist()
    {
        for (int i = 0; i < v; i++)
        {
            char vertex = 'A' + i;
            cout << vertex << " : ";

            for (int neigh : l[i])
            {
                char neighVertex = 'A' + neigh;
                cout << neighVertex << " ";
            }
            cout << endl;
        }
    }

    ~graph()
    {
        delete[] l;
    }
};

int main()
{
    graph g(6);

    g.addedge('A', 'B');
    g.addedge('A', 'D');
    g.addedge('A', 'F');
    g.addedge('B', 'D');
    g.addedge('B', 'E');
    g.addedge('D', 'E');
    g.addedge('D', 'F');
    g.addedge('E', 'F');
    g.addedge('E', 'C');
    g.addedge('F', 'C');

    cout << "Graph Adjacency List:" << endl;
    g.printadjlist();

    return 0;
}

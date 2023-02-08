#include<iostream>
#include <list>
#include <limits.h>

using namespace std;

class Graph

{

    int V;    
    list<int>* adj; 
    bool isCyclicUtil(int v, bool visited[], int parent);

public:
    Graph(int V);   
    void addEdge(int v, int w);   
    bool isTree();   
    bool isForest(); 
};



Graph::Graph(int V)

{
    this->V = V;
    adj = new list<int>[V];
}



void Graph::addEdge(int v, int w)

{
    adj[v].push_back(w); 
    adj[w].push_back(v); 
}


bool Graph::isCyclicUtil(int v, bool visited[], int parent)

{
    visited[v] = true;

    list<int>::iterator i;

    for (i = adj[v].begin(); i != adj[v].end(); ++i)

    {
        if (!visited[*i])

        {
            if (isCyclicUtil(*i, visited, v))
                return true;
        }
        
        else if (*i != parent)

            return true;

    }

    return false;

}




bool Graph::isTree()

{
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    if (isCyclicUtil(0, visited, -1))
        return false;
    for (int u = 0; u < V; u++)
        if (!visited[u])
            return false;
    return true;
}

bool Graph::isForest()
{
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    if (isCyclicUtil(0, visited, -1))
        return false;
    for (int u = 0; u < V; u++)
        if (!visited[u])
            if (isCyclicUtil(u, visited, -1))
                return false;
}

struct edge
{
    friend istream& operator>> (istream& in, edge& p)
    {
        cin >> p.from;
        cin >> p.to;
        return in;
    }
    int from;
    int to;
};

int main()
{
    setlocale(LC_ALL, "UKRAINIAN");
    int N, M;
    cout << "Уведiть кiлькiсть вершин графу: ";
    cin >> N;
    cout << "Уведiть кiлькiсть ребер графу: ";
    cin >> M;
    cout << "Уведiть ребра графу.\n";
    edge* fromTo = new edge[M];
    for (int i = 0; i < M; i++)
    {
        cin >> fromTo[i];
    }

    bool** graph = new bool* [N];
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            graph[i] = new bool[N] {};
        }
    }
    for (int i = 0; i < M; i++)
    {
        /*for (int j = 0; j < N; j++)
        {
            
        }*/
        graph[fromTo[i].from-1][fromTo[i].to-1]=1;
    }

    cout << "Матриця сумiжностi вершин графу розмiром " << N << "x" << N << ":\n";
    for (int i = 0; i < N+1; i++)
    {
        for (int j = 0; j < N + 1; j++)
        {
            //cout.width(5);
            if (i == 0 && j == 0)
            {
                cout << "\t";
                continue;
            }
            if (i == 0)
            {
                cout << j << "\t";
                continue;
            }
            if (j == 0)
            {
                cout << "    " <<  i << "\t";
                continue;
            }
            cout << graph[i-1][j-1] << "\t";
        }
        cout << endl;
    }

    Graph g(N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (graph[i][j])
            {
                g.addEdge(i, j);
            }
        }
    }

    cout << endl;
    if (g.isTree())
        cout << "Граф є деревом\n";
    else
        if (g.isForest())
            cout << "Граф є лiсом\n";
        else
            if (!g.isTree() && !g.isForest())
                cout << "Граф не є деревом чи лiсом\n";
    return 0;
}
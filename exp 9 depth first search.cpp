// DEPTH FIRST SEARCH
#include <iostream>
using namespace std;
const int MAX = 100;

class graphnode
{
    int vertex;
    graphnode *next;

public:
    graphnode(int n = 0)
    {
        vertex = n;
        next = NULL;
    }
    friend class listgraph;
};

class listgraph
{
    graphnode *list[MAX];
    int n;

public:
    listgraph(int nov)
    {
        n = nov;
        for (int j = 0; j < n; j++)
            list[j] = NULL;
    }
    void create();
    void display();
    void DFS(int vertex, bool visited[]);
};

void listgraph::create()
{
    int i, j;
    graphnode *temp, *newnode;
    char ans;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << "\nIs there an edge between vertex " << i + 1 << " and " << j + 1 << "? (y/n): ";
            cin >> ans;
            if (ans == 'y')
            {
                newnode = new graphnode(j + 1);

                if (list[i] == NULL)
                    list[i] = temp = newnode;
                else
                {
                    temp->next = newnode;
                    temp = newnode;
                }
            }
        }
    }
}

void listgraph::display()
{
    graphnode *temp;
    int i;
    for (i = 0; i < n; i++)
    {
        cout << endl;
        cout << "Vertex " << i + 1 << "->";
        temp = list[i];
        while (temp != NULL)
        {
            cout << "v" << temp->vertex << "->";
            temp = temp->next;
        }
        cout << "NULL";
    }
}

void listgraph::DFS(int vertex, bool visited[])
{
    visited[vertex - 1] = true;
    cout << "v" << vertex << " ";

    graphnode *temp = list[vertex - 1];
    while (temp != NULL)
    {
        int adjVertex = temp->vertex;
        if (!visited[adjVertex - 1])
        {
            DFS(adjVertex, visited);
        }
        temp = temp->next;
    }
}

int main()
{
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;
    listgraph g(n);
    g.create();
    cout << "Adjacency List representation of the graph:" << endl;
    g.display();

    bool visited[MAX];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    cout << "\nDFS Traversal of the graph: ";
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            g.DFS(i + 1, visited);
        }
    }
    
    return 0;
}



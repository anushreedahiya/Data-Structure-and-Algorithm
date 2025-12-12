#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph {
private:
    int V; // Number of vertices
    vector<list<int> > adj; // Adjacency list

public:
    Graph(int v) : V(v), adj(v) {}

    void addEdge(int u, int v) {
        // Add an edge from vertex u to vertex v
        adj[u].push_back(v);
    }

    void display() {
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << " -> ";
            for (int neighbor : adj[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }

    void insertNode(int v) {
        if (v >= 0 && v < V) {
            adj.push_back(list<int>());
            V++;
            cout << "Vertex " << V - 1 << " inserted successfully!" << endl;
        } else {
            cout << "Invalid vertex for insertion!" << endl;
        }
    }

    void deleteNode(int v) {
        if (v >= 0 && v < V) {
            adj.erase(adj.begin() + v);
            for (auto &neighbors : adj) {
                neighbors.remove(v);
            }
            V--;
            cout << "Vertex " << v << " deleted successfully!" << endl;
        } else {
            cout << "Invalid vertex for deletion!" << endl;
        }
    }
};

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;
    Graph g(V);

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Add Edge\n";
        cout << "2. Display Graph\n";
        cout << "3. Insert Node\n";
        cout << "4. Delete Node\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int u, v;
                cout << "Enter source vertex: ";
                cin >> u;
                cout << "Enter destination vertex: ";
                cin >> v;
                g.addEdge(u, v);
                cout << "Edge added from " << u << " to " << v << endl;
                break;
            }
            case 2:
                cout << "Graph:\n";
                g.display();
                break;
            case 3: {
                int insertVertex;
                cout << "Enter the vertex to insert: ";
                cin >> insertVertex;
                g.insertNode(insertVertex);
                break;
            }
            case 4: {
                int deleteVertex;
                cout << "Enter the vertex to delete: ";
                cin >> deleteVertex;
                g.deleteNode(deleteVertex);
                break;
            }
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 5);

    return 0;
}













/*
#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int MAX = 10;
class graphnode
{
    string vertexData;
    graphnode* next;
public:
    graphnode(const string& data = "") : vertexData(data), next(NULL) {}
    const string& getVertexData() const
	{
        return vertexData;
    }

    graphnode* getNext() const
	{
        return next;
    }

    friend class listgraph;
};


class listgraph
{
    graphnode* list[MAX];
    int n; // number of vertices
    string vertexData[MAX]; // store vertex data

public:
    listgraph(int nov) : n(nov)
	{
        for (int j = 0; j < n; j++)
            list[j] = NULL;
    }

    void inputVertexData();
    void create();
    void display();
    void insertNode(int v);
    void deleteNode(int v);
    void DFS(int startVertex, vector<bool>& visited);
};

void listgraph::inputVertexData()
{
    for (int i = 0; i < n; i++)
	{
        cout << "Enter data for vertex " << i + 1 << ": ";
        cin >> vertexData[i];
    }
}


void listgraph::create()
{
    graphnode* temp, *newnode;
    string ans;
    for (int i = 0; i < n; i++)
	{
        for (int j = 0; j < n; j++)
		{
            cout << "\nIs there an edge between vertex " << i + 1 << " and " << j + 1 << "? (y/n): ";
            cin >> ans;
            if (ans == "y")
			{
                newnode = new graphnode(vertexData[j]);

                // Attach newnode to list i
                if (list[i] == NULL)
                    list[i] = temp = newnode;
                else {
                    temp->next = newnode;
                    temp = newnode;
                }
            } 
        }
    }
}

void listgraph::display()
{
    graphnode* temp;
    for (int i = 0; i < n; i++)
	{
        cout << endl;
        cout << "Vertex " << i + 1 << " (" << vertexData[i] << ") -> ";
        temp = list[i];
        while (temp != NULL)
		{
            cout << temp->getVertexData() << " -> ";
            temp = temp->getNext();
        }
        cout << "NULL";
    }
    cout << endl;
}

void listgraph::insertNode(int v)
{
    if (v >= 0 && v < n)
	{
        string data;
        cout << "Enter data for vertex to insert: ";
        cin >> data;
        graphnode* newNode = new graphnode(data);
        newNode->next = list[v];
        list[v] = newNode;
    }
	else
	{
        cout << "Invalid vertex for insertion!" << endl;
    }
}

void listgraph::deleteNode(int v)
{
    if (v >= 0 && v < n)
	{
        if (list[v] != NULL)
		{
            graphnode* temp = list[v];
            list[v] = list[v]->getNext();
            delete temp;
            cout << "Vertex " << v + 1 << " deleted successfully!" << endl;
        }
		else
		{
            cout << "Vertex " << v + 1 << " not found!" << endl;
        }
    }
	else
	{
        cout << "Invalid vertex for deletion!" << endl;
    }
}

void listgraph::DFS(int startVertex, vector<bool>& visited) {
    visited[startVertex] = true;
    cout << "v" << startVertex + 1 << " -> ";

    graphnode* temp = list[startVertex];
    while (temp != NULL) {
        int neighbor = temp->getVertex() - 1;
        if (!visited[neighbor]) {
            DFS(neighbor, visited);
        }
        temp = temp->getNext();
    }
}

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;
    listgraph g(n);
    g.inputVertexData(); // Input vertex data once
    g.create();
    cout << "Graph created:\n";
    g.display();

    vector<bool> visited(n, false);

    int choice;
    do {
        cout << "\n\nMenu:\n";
        cout << "1. Insert Node\n";
        cout << "2. Delete Node\n";
        cout << "3. Display Graph\n";
        cout << "4. DFS Traversal\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int insertVertex;
                cout << "Enter the vertex to insert: ";
                cin >> insertVertex;
                g.insertNode(insertVertex - 1);
                cout << "After insertion:\n";
                g.display();
                break;
            }
            case 2: {
                int deleteVertex;
                cout << "Enter the vertex to delete: ";
                cin >> deleteVertex;
                g.deleteNode(deleteVertex - 1);
                cout << "After deletion:\n";
                g.display();
                break;
            }
            case 3:
                cout << "Graph:\n";
                g.display();
                break;
            case 4:
                cout << "DFS Traversal starting from vertex 1:\n";
                g.DFS(0, visited);
                cout << "END" << endl;
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 5);

    return 0;
}

*/




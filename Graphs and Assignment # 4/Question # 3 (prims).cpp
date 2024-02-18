#include <iostream>
using namespace std;

const int infinite = 999999; // for Infinity

struct node;
struct edgeWithWeight;

struct edgeWithWeight
{
    char dest;
    int weight;
    struct edgeWithWeight *link;
};

struct node
{
    node *next;
    char name;
    edgeWithWeight *adj;
    int distance;     // Key value used in Prim's algorithm
    char parent; // Parent node used in Prim's algorithm
    bool visited;
} * start = NULL;

struct node *find(char item)
{
    node *ptr = start;
    while (ptr != NULL)
    {
        if (item == ptr->name)
            return ptr;
        else
            ptr = ptr->next;
    }
    return NULL;
}

void insert_node(char node_name)
{
    node *tmp, *ptr;
    tmp = new node;
    tmp->name = node_name;
    tmp->next = NULL;
    tmp->adj = NULL;
    tmp->distance = infinite; // Initialize key values to infinity
    tmp->parent = '\0';  // Initialize parent values to NULL
    tmp->visited = false;

    if (start == NULL)
        start = tmp;
    else
    {
        ptr = start;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = tmp;
    }
}

void insert_edge_with_weight(char u, char v, int weight)
{
    node *locu, *locv;
    edgeWithWeight *ptr, *tmp;

    locu = find(u);
    locv = find(v);

    if (locu == NULL)
    {
        cout << "Source node not present, first insert node " << u << endl;
        return;
    }
    if (locv == NULL)
    {
        cout << "Destination node not present, first insert node " << v << endl;
        return;
    }

    tmp = new edgeWithWeight;
    tmp->dest = v;
    tmp->weight = weight;
    tmp->link = NULL;

    if (locu->adj == NULL)
        locu->adj = tmp;
    else
    {
        ptr = locu->adj;
        while (ptr->link != NULL)
            ptr = ptr->link;
        ptr->link = tmp;
    }

    tmp = new edgeWithWeight; // Add the reverse edge for an undirected graph
    tmp->dest = u;
    tmp->weight = weight;
    tmp->link = NULL;

    if (locv->adj == NULL)
        locv->adj = tmp;
    else
    {
        ptr = locv->adj;
        while (ptr->link != NULL)
            ptr = ptr->link;
        ptr->link = tmp;
    }
}

void prim(char startNodeName)
{
    struct node *startNode = find(startNodeName);

    if (startNode == NULL)
    {
        cout << "Source node not found in the graph." << endl;
        return;
    }

    // Resetting the key values for all nodes in the graph
   struct node *ptr = start;
    while (ptr != NULL)
    {
        ptr->distance = infinite;
        ptr->parent = '\0';
        ptr->visited = false;
        ptr = ptr->next;
    }

    // Set distance of the start node to 0
    startNode->distance = 0;

    cout << "Prim's Minimum Spanning Tree:" << endl;
    cout << "------------------------------" << endl;

    while (startNode != NULL)
    {
        // Find the node with the minimum distance value
       	struct node *current = NULL;
        int mindistance = infinite;

        struct node *tempPtr = start;
        while (tempPtr != NULL)
        {
            if (!tempPtr->visited && tempPtr->distance < mindistance)
            {
                mindistance = tempPtr->distance;
                current = tempPtr;
            }
            tempPtr = tempPtr->next;
        }

        if (current == NULL)
        {
            // All remaining nodes are unreachable
            break;
        }

        current->visited = true;

        struct edgeWithWeight *tempEdge = current->adj;
        while (tempEdge != NULL)
        {
            struct node *adjNode = find(tempEdge->dest);
            if (!adjNode->visited && tempEdge->weight < adjNode->distance)
            {
                adjNode->distance = tempEdge->weight;
                adjNode->parent = current->name;
            }
            tempEdge = tempEdge->link;
        }

        // Print the edge in the minimum spanning tree
        if (current->parent != '\0')
        {
            cout << "Edge: " << current->parent << " - " << current->name << " Weight: " << current->distance << endl;
        }
    }
}

int main()
{
    int choice;
    char node, origin, destin;
    int weight;

    while (true)
    {
        cout << "1.Insert a node\n";
        cout << "2.Insert an edge\n";
        cout << "3.Delete a node\n";
        cout << "4.Delete an edge\n";
        cout << "5.Display\n";
        cout << "6.Perform Prim's algorithm\n";
        cout << "7.Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter a node to be inserted: ";
            cin >> node;
            insert_node(node);
            break;
        case 2:
            cout << "Enter an edge to be inserted: ";
            cin >> origin >> destin;
            cout << "Enter the weight of the edge: ";
            cin >> weight;
            insert_edge_with_weight(origin, destin, weight);
            break;
        case 3:
            cout << "Enter a node to be deleted: ";
            cin >> node;
            // Handle deletion of node and associated edges
            // (You can implement this part based on your requirements)
            break;
        case 4:
            cout << "Enter an edge to be deleted: ";
            cin >> origin >> destin;
            // Handle deletion of edge
            // (You can implement this part based on your requirements)
            break;
        case 5:
            // Display function can be implemented based on your requirements
            break;
        case 6:
            cout << "Enter the source node for Prim's algorithm: ";
            cin >> origin;
            prim(origin);
            break;
        case 7:
            exit(0);
        default:
            cout << "Invalid choice. Please enter a valid option.\n";
            break;
        }
    }
    return 0;
}


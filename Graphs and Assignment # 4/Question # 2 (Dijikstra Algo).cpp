#include <iostream>

using namespace std;

const int infinite = 999999;   // for Infinity 

struct edgeWithWeight;

struct node
{
    node *next;
    char name;
    struct edgeWithWeight *adj;
    int distance;
    bool visited;

} *start = NULL;

struct edgeWithWeight
{
    char dest;
    int weight;
    struct edgeWithWeight *link;
};

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
    tmp->distance = infinite; 

    if (start == NULL)
    {
        start = tmp;
	}
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
}
void dijkstra(char startNodeName, char endNodeName)
{
    struct node *startNode = find(startNodeName);
    struct node *endNode   = find(endNodeName);

    if (startNode == NULL || endNode == NULL)
    {
        cout << "Source or destination node not found in the graph." << endl;
        return;
    }

    // Resetting the distance values for all nodes in the graph
    struct node *ptr = start;
    while (ptr != NULL)
    {
        ptr->distance = INT_MAX;
        ptr = ptr->next;
        
    }

    // Set distance of the source node to 0
    startNode->distance = 0;
    

    cout << "Dijkstra's Shortest Path:" << endl;
    cout << "--------------------------" << endl;

    while (startNode != NULL)
    {
        // Find the node with the minimum distance value
        struct node *current = NULL;
        int minDistance = infinite;

        struct node *tempPtr = start;
        while (tempPtr != NULL)
        {
            if (!tempPtr->visited && tempPtr->distance < minDistance)
            {
                minDistance = tempPtr->distance;
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

        edgeWithWeight *tempEdge = current->adj;
        while (tempEdge != NULL)
        {
            node *adjNode = find(tempEdge->dest);
            if (!adjNode->visited && (current->distance + tempEdge->weight) < adjNode->distance)
            {
                adjNode->distance = current->distance + tempEdge->weight;
            }
            tempEdge = tempEdge->link;
        }

        // If the destination node is reached, break the loop
        if (current == endNode)
        {
            break;
        }
    }

    if (endNode->distance == infinite)
    {
        cout << "No path exists between " << startNodeName << " and " << endNodeName << endl;
    }
    else
    {
        cout << "Shortest distance from " << startNodeName << " to " << endNodeName << ": " << endNode->distance << endl;
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
        cout << "6.Perform Dijkstra's algorithm\n";
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
//        case 3:
//            cout << "Enter a node to be deleted: ";
//            cin >> node;
//            // Handle deletion of node and associated edges
//            // (You can implement this part based on your requirements)
//            break;
//        case 4:
//            cout << "Enter an edge to be deleted: ";
//            cin >> origin >> destin;
//            // Handle deletion of edge
//            // (You can implement this part based on your requirements)
//            break;
//        case 5:
//            display();
//            break;
        case 6:
            cout << "Enter the source node for Dijkstra's algorithm: ";
            cin >> origin;
            cout << "Enter the destination node for Dijkstra's algorithm: ";
            cin >> destin;
            dijkstra(origin, destin);
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


#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#define SIZE 10
using namespace std;
struct Node
	{
		string city = "";
		//Node *next = NULL;
		vector <Node *> neighbours;
		int time = -1;
	};
class Flights
{
	
	
	vector<Node *> nodes;
	public:
	Flights()
	{
		
	}
	
	Node *findNode(string s)
	{
		for(Node* node : nodes) {
            		if (node->city == s) {
            	    	return node;
            		}
            	}
        	
            	return NULL;
	}
	
	
	void addEdges(string s, string d, int time)
	{
		Node *sourceNode = findNode(s);
		Node *destNode = findNode(d);
		
		if(sourceNode && destNode)
		{
			Node *temp = new Node;
			temp->city = d;
			temp->time = time;
			sourceNode->neighbours.push_back(temp);
			//destNode->neighbours.push_back(sourceNode);
		}
		else
		{
			cout<<"\nInvalid Source or Destination\n";
		}
	}
	
	
	void addNode(string city)
	{
		Node *temp = new Node;
		temp->city = city;
		nodes.push_back(temp);
	}
	
	void insert()
	{
		int no;
		string city;
		
		cout<<"Enter Number of Airports : ";
		cin>>no;
		
		
		cout<<"\nEnter City Details\n";
		for(int i=0;i<no;i++)
		{
			cout<<"Enter name of city "<<i<<" : ";
			cin>>city;
			
			addNode(city);
		}
		
		cout<<"\nEnter Number of Flights : ";
		cin>>no;
		
		string source;
		string destination;
		int time;
		for(int i=0;i<no;i++)
		{
			cout<<"\nFlight Information "<<i<<"\n";
			cout<<"Enter Source : ";
			cin>>source;
			cout<<"Enter Destination : ";
			cin>>destination;
			cout<<"Enter Time : ";
			cin>>time;
			addEdges(source,destination,time);
		}
		
	}
	
	void printGraph()
	{
		for(auto node : nodes)
		{
			cout<<node->city<<" ("<<time<<")";
			for(auto neighbour : node->neighbours)
			{
				cout<<"->"<<neighbour->city<<"("<<neighbour->time<<")";
			}
			cout<<"\n";
		}
	}
	
	void bfs()
	{
		const Node* startNode = nodes[0];
		if (!startNode) {
        		std::cout << "Invalid start node.\n";
        	return;
    		}

    		std::queue<const Node*> q;
    		std::set<const Node*> visited;

    		q.push(startNode);
    		visited.insert(startNode);

    		std::cout << "BFS Traversal:\n";

    		while (!q.empty()) {
        		const Node* currNode = q.front();
        		q.pop();

        		std::cout << currNode->city << " (" << currNode->time << ") ";

        			for (const Node* neighbour : currNode->neighbours) {
            				if (visited.find(neighbour) == visited.end()) {
                				visited.insert(neighbour);
                				q.push(neighbour);
            				}
        			}
    		}

    		std::cout << std::endl;
	}
	
};


int main()
{
	Flights n;
	n.insert();
	n.printGraph();
	n.bfs();
}

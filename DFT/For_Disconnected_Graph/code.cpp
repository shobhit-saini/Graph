#include<bits/stdc++.h> 
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////Edge adding section//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int addedge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////Printing of graph////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int print_graph(vector<int>adj[], int V)
{
	int i = 0;
	vector<int>::iterator itr;
	for(i = 0; i < V; i++)
	{
		cout << i;
		for(itr = adj[i].begin(); itr != adj[i].end(); itr++)
		{
			cout << "->" << *itr ;
		}
		cout << "\n";
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////DFT//////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int DFT(vector<int>adj[], int V, int S, int *visited)
{
	vector<int>::iterator itr;
	for(itr = adj[S].begin(); itr != adj[S].end(); itr++)
	{
		if(visited[*itr] == 0)
		{
			visited[*itr] = 1;
			cout << *itr << "\t";
			DFT(adj, V, *itr, visited);
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////Main Function///////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	int V = 0, E = 0, i = 0, u, v, S;
	
	cout << "Enter the Number of vertices:";
	cin >> V;
	
	vector<int> adj[V];
	
	cout << "Enter the Number of Edges:";
	cin >> E;
	
	for(i = 0; i < E; i++)
	{
		cin >> u >> v;
		addedge(adj, u, v);
	}
	
	print_graph(adj, V);
	
	cout << "Enter the starting vertex:";
	cin >> S;
	int visited[V] = {0};
	visited[S] = 1;
	cout << S << "\t";
	DFT(adj, V, S, visited);
	for(i = 0; i < V; i++)
	{
		if(visited[i] == 0)
		{
			visited[i] = 1;
			cout << "\n" << i << "\t";
			DFT(adj, V, i, visited);
		}
	}
}

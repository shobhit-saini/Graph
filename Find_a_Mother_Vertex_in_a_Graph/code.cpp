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
int j = 0;
int DFT(vector<int>adj[], int V, int S, int *visited)
{
	vector<int>::iterator itr;
	for(itr = adj[S].begin(); itr != adj[S].end(); itr++)
	{
		if(visited[*itr] == 0)
		{
			visited[*itr] = 1;
			j++;
		//	cout << *itr << ":" << j << "\t";
			DFT(adj, V, *itr, visited);
		}
	}
	
	if(j == V)
	{
		return 1;
	}
	else 
		return -1;

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////Main Function///////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	int V = 0, E = 0, i = 0, u, v, S, x;
	
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


	for(i = 0; i < V; i++)
	{
		int visited[V] = {0};
		
		visited[i] = 1;
		j = 1;
		//cout << i << ":";
		
		x = DFT(adj,  V, i, visited);
	//	cout<< "\n";
		if(x == 1)
		{
			cout << "Mother found:" << i ;
			return 0;
		}
		x = 0;
	}
	cout << "Mother not found";	
}

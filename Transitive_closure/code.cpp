#include<bits/stdc++.h>
using namespace std;
int addedge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
}
int printgraph(vector<int>adj[], int V)
{
	int i;
	vector<int>:: iterator itr;
	for(i = 0; i < V; i++)
	{
		cout << i;
		for(itr = adj[i].begin(); itr != adj[i].end(); itr++)
		{
			cout << "->" << *itr;
		}
		cout << "\n";
	}
}
int DFS()
{
	
}
int main()
{
	int i, V, E, u, v;
	cout << "Enter the no. of vertices:";
	cin >> V;
	vector<int> adj[V];
	cout << "Enter the no. of edges:";
	cin >> E;
	cout << "Enter the edges from u to v\n";
	for(i = 0; i < E; i++)
	{
		cin >> u >> v;
		addedge(adj, u, v);
	}
	printgraph(adj, V);
	int DFS()
}

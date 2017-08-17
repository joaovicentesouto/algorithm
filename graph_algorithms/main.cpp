#include <iostream>
#include <lemon/list_graph.h>
#include "./code/graph_algorithms.h"

using namespace lemon;
using namespace std;

int main()
{
	ListGraph g;
	ListGraph::Node a = g.addNode();
	ListGraph::Node b = g.addNode();
	ListGraph::Node c = g.addNode();
	ListGraph::Node d = g.addNode();
	ListGraph::Node e = g.addNode();

	ListGraph::EdgeMap<int> cost(g);
	cost[g.addEdge(a,b)] = 3;
	cost[g.addEdge(a,c)] = 14;
	cost[g.addEdge(a,e)] = 2;
	cost[g.addEdge(b,c)] = 6;
	cost[g.addEdge(b,d)] = 10;
	cost[g.addEdge(c,d)] = 2;
	cost[g.addEdge(c,e)] = 10;


	routing::GraphAlgorithms algs(g, cost, 5, 7);

	algs.test();
	cout << endl;
	
	std::vector<std::size_t> *v = algs.dijkstra(a, e);

	// Print da rota
	for (int i = v->size()-1; i > 0; --i)
	{
		cout << (*v)[i] << " -> ";
	}
	cout << (*v)[0] << endl;
	delete v;

	return 0;
}

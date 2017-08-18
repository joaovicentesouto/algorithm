#include <iostream>
#include <lemon/list_graph.h>
#include "./src/graph_algorithms.h"

using namespace lemon;
using namespace std;

int main()
{

        ListGraph graph;

        vector<ListGraph::Node> nodes;
        for (int i = 0; i < 10; ++i)
        {
            nodes[i] = graph.addNode();
        }

        ListGraph::EdgeMap<int> cost(graph);

        cost[graph.addEdge(nodes[0], nodes[1])] = 2;
        cost[graph.addEdge(nodes[0], nodes[2])] = 4;
        cost[graph.addEdge(nodes[1], nodes[4])] = 6;
        cost[graph.addEdge(nodes[2], nodes[3])] = 5;
        cost[graph.addEdge(nodes[3], nodes[6])] = 2;
        cost[graph.addEdge(nodes[4], nodes[6])] = 2;
        cost[graph.addEdge(nodes[5], nodes[6])] = 1;
        cost[graph.addEdge(nodes[6], nodes[7])] = 1;
        cost[graph.addEdge(nodes[6], nodes[8])] = 8;
        cost[graph.addEdge(nodes[7], nodes[9])] = 4;
        cost[graph.addEdge(nodes[8], nodes[9])] = 1;


        routing::GraphAlgorithms algs(graph, cost, 10, 12);
        cout << algs.test();
	
        std::vector<std::size_t> *v = algs.dijkstra(nodes[0], nodes[9]);

	// Print da rota
	for (int i = v->size()-1; i > 0; --i)
	{
		cout << (*v)[i] << " -> ";
	}
	cout << (*v)[0] << endl;
	delete v;

	return 0;
}

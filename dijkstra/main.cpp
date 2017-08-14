#include <iostream>
#include <lemon/list_graph.h>
#include "graph_algorithms.h"

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
	cost[g.addEdge(a,b)] = 1;
	cost[g.addEdge(b,c)] = 1;
	cost[g.addEdge(c,d)] = 1;
	cost[g.addEdge(d,e)] = 1;
	cost[g.addEdge(e,a)] = 10;

	/*int cnt = 1;
	for (ListGraph::EdgeIt e(g); e != INVALID; ++e) {
		cost[e] = cnt++;
	}*/

	routing::GraphAlgorithms algs(g, cost, 5, 5);
	algs.test();
	cout << endl;
	
	std::vector<std::size_t> *v = algs.dijkstra(a, e);

	for (int i = v->size()-1; i > 0; --i)
	{
		cout << (*v)[i] << " -> ";
	}
	cout << (*v)[0] << endl;
	delete v;

	/*ListGraph::Arc a1 = g.direct(e, true);    // a1 is the forward arc
	ListGraph::Arc a2 = g.direct(e, false);   // a2 is the backward arc
	if (a2 == g.oppositeArc(a1))
		std::cout << "a2 is the opposite of a1" << std::endl;

	std::cout << "Edge " << g.id(e) << " connects node "
		<< g.id(g.u(e)) << " and node " << g.id(g.v(e)) << std::endl;
	std::cout << "Arc " << g.id(a2) << " goes from node "
		<< g.id(g.source(a2)) << " to node " << g.id(g.target(a2)) << std::endl;

	for (ListGraph::NodeIt n(g); n != INVALID; ++n) {
		int cnt = 0;
		for (ListGraph::IncEdgeIt e(g, n); e != INVALID; ++e) {
			cnt++;
		}
		std::cout << "deg(" << g.id(n) << ") = " << cnt << std::endl;
	}

	ListGraph::EdgeMap<int> cost(g);
	cost[e] = 10;
	std::cout << cost[e] << std::endl;
	std::cout << cost[a1] << ", " << cost[a2] << std::endl;

	ListGraph::ArcMap<int> arc_cost(g);
	arc_cost[a1] = cost[a1];
	arc_cost[a2] = 2 * cost[a2];
	// std::cout << arc_cost[e] << std::endl;   // this is not valid
	std::cout << arc_cost[a1] << ", " << arc_cost[a2] << std::endl;
	*/

	return 0;
}

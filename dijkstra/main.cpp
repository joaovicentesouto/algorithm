#include <iostream>
#include <lemon/list_graph.h>
#include "dijkstra_algorithm.h"

using namespace lemon;
using namespace std;

int main()
{
	ListDigraph g;

	ListDigraph::Node x = g.addNode();
	ListDigraph::Node y = g.addNode();
	ListDigraph::Node z = g.addNode();
	cout << "x: " << g.id(x) << endl;
	cout << "y: " << g.id(y) << endl;
	cout << "z: " << g.id(z) << endl << endl;

	ListDigraph::Arc  a = g.addArc(x, y);
	ListDigraph::Arc  b = g.addArc(y, z);
	ListDigraph::Arc  c = g.addArc(z, x);
	cout << "a: " << g.id(x) << endl;
	cout << "b: " << g.id(y) << endl;
	cout << "c: " << g.id(z) << endl << endl;

	ListDigraph::NodeMap<char> nodes(g);
	ListDigraph::ArcMap<int> arcs(g);
	char text = 'Z';
	int value = 3;
	
	for (ListDigraph::NodeIt it(g); it != INVALID; ++it)
	{
		nodes[it] = text--;
	}

	text = 'C';
	for (ListDigraph::ArcIt it(g); it != INVALID; ++it)
	{
		arcs[it] = value--;;
	}

	for (ListDigraph::ArcIt it(g); it != INVALID; ++it)
	{
		cout << nodes[g.source(it)] << " |- " << arcs[it] << " -> " << nodes[g.target(it)] << endl;
	}

	/*routing::DijkstraAlgorithm *d = new routing::DijkstraAlgorithm();
	d->test();
	delete d;*/

	return 0;
}

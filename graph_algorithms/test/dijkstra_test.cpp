#include <catch.hpp>
#include <vector>
#include "../src/graph_algorithms.cpp"

using namespace lemon;
using namespace std;

namespace {
class GraphFixture {
public:
    ListGraph mGraph;
    ListGraph::EdgeMap<size_t> mCost;
    ListGraph::NodeMap<pair<size_t, size_t>> mPosition;
    size_t mNodesAmount, mEdgesAmount;

    GraphFixture()
        : mCost(mGraph),
          mPosition(mGraph),
          mNodesAmount(16),
          mEdgesAmount(24)
    {
        vector<ListGraph::Node> nodes;

        for (auto i = 0; i < sqrt(mNodesAmount); ++i)
        {
            for (auto j = 0; j < sqrt(mNodesAmount); ++j)
            {
                nodes.push_back(mGraph.addNode());
                mPosition[nodes[i*sqrt(mNodesAmount)+j]] = make_pair(j,i);
            }
        }

        // Adicionando arestas e ja lhes atribuindo um valor.
        mCost[mGraph.addEdge(nodes[0], nodes[1])] = 2;
        mCost[mGraph.addEdge(nodes[0], nodes[4])] = 1;
        mCost[mGraph.addEdge(nodes[1], nodes[2])] = 3;
        mCost[mGraph.addEdge(nodes[1], nodes[5])] = 3;
        mCost[mGraph.addEdge(nodes[2], nodes[3])] = 4;
        mCost[mGraph.addEdge(nodes[2], nodes[6])] = 3;
        mCost[mGraph.addEdge(nodes[3], nodes[7])] = 3;
        mCost[mGraph.addEdge(nodes[4], nodes[5])] = 2;
        mCost[mGraph.addEdge(nodes[4], nodes[8])] = 1;
        mCost[mGraph.addEdge(nodes[5], nodes[6])] = 3;
        mCost[mGraph.addEdge(nodes[5], nodes[9])] = 2;
        mCost[mGraph.addEdge(nodes[6], nodes[7])] = 3;
        mCost[mGraph.addEdge(nodes[6], nodes[10])] = 2;
        mCost[mGraph.addEdge(nodes[7], nodes[11])] = 2;
        mCost[mGraph.addEdge(nodes[8], nodes[9])] = 1;
        mCost[mGraph.addEdge(nodes[8], nodes[12])] = 2;
        mCost[mGraph.addEdge(nodes[9], nodes[10])] = 1;
        mCost[mGraph.addEdge(nodes[9], nodes[13])] = 2;
        mCost[mGraph.addEdge(nodes[10], nodes[11])] = 1;
        mCost[mGraph.addEdge(nodes[10], nodes[14])] = 2;
        mCost[mGraph.addEdge(nodes[11], nodes[15])] = 1;
        mCost[mGraph.addEdge(nodes[12], nodes[13])] = 3;
        mCost[mGraph.addEdge(nodes[13], nodes[14])] = 3;
        mCost[mGraph.addEdge(nodes[14], nodes[15])] = 2;
    }

    ~GraphFixture()
    {

    }
};
}

TEST_CASE_METHOD(GraphFixture, "Dijkstra: Caminho de custo mínimo 0 -> 15", "[dijkstra]")
{
    routing::GraphAlgorithms g(mGraph, mCost, mPosition, mNodesAmount, mEdgesAmount);

    vector<size_t> *gWay, *correctWay = new vector<size_t>();
    correctWay->push_back(15);
    correctWay->push_back(11);
    correctWay->push_back(10);
    correctWay->push_back(9);
    correctWay->push_back(8);
    correctWay->push_back(4);
    correctWay->push_back(0);

    gWay = g.dijkstra(0, 15);
    REQUIRE(*correctWay == *gWay);

    delete correctWay;
    delete gWay;
}

TEST_CASE_METHOD(GraphFixture, "Dijkstra: Caminho de custo mínimo 0 -> 7", "[dijkstra]")
{
    routing::GraphAlgorithms g(mGraph, mCost, mPosition, mNodesAmount, mEdgesAmount);

    vector<size_t> *gWay, *correctWay = new vector<size_t>();
    correctWay->push_back(7);
    correctWay->push_back(11);
    correctWay->push_back(10);
    correctWay->push_back(9);
    correctWay->push_back(8);
    correctWay->push_back(4);
    correctWay->push_back(0);

    gWay = g.dijkstra(0, 7);
    REQUIRE(*correctWay == *gWay);

    delete correctWay;
    delete gWay;
}

TEST_CASE_METHOD(GraphFixture, "Dijkstra: Exception test", "[dijkstra]")
{
    routing::GraphAlgorithms g(mGraph, mCost, mPosition, mNodesAmount, mEdgesAmount);

    REQUIRE_THROWS(g.dijkstra(2, 20));
}

TEST_CASE_METHOD(GraphFixture, "A-Star: Caminho de custo mínimo 0 -> 15", "[a-star]")
{
    routing::GraphAlgorithms g(mGraph, mCost, mPosition, mNodesAmount, mEdgesAmount);

    vector<size_t> *gWay, *correctWay = new vector<size_t>();
    correctWay->push_back(15);
    correctWay->push_back(11);
    correctWay->push_back(10);
    correctWay->push_back(9);
    correctWay->push_back(8);
    correctWay->push_back(4);
    correctWay->push_back(0);

    gWay = g.aStar(0, 15);
    REQUIRE(*correctWay == *gWay);

    delete correctWay;
    delete gWay;
}

TEST_CASE_METHOD(GraphFixture, "A-Star: Caminho de custo mínimo 0 -> 7", "[a-star]")
{
    routing::GraphAlgorithms g(mGraph, mCost, mPosition, mNodesAmount, mEdgesAmount);

    vector<size_t> *gWay, *correctWay = new vector<size_t>();
    correctWay->push_back(7);
    correctWay->push_back(11);
    correctWay->push_back(10);
    correctWay->push_back(9);
    correctWay->push_back(8);
    correctWay->push_back(4);
    correctWay->push_back(0);

    gWay = g.aStar(0, 7);
    REQUIRE(*correctWay == *gWay);

    delete correctWay;
    delete gWay;
}

#include <lemon/list_graph.h>

using namespace lemon;
using namespace std;

namespace routing {

class DijkstraAlgorithm
{
public:
	DijkstraAlgorithm();
	~DijkstraAlgorithm();

	void test();

private:
	int t{5};
};

}  // namespace routing
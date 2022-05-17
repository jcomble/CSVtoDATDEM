#include <vector>
using namespace std;
class Traffic
{
    
    private:
        vector<int> list_traffic;
    public:
        Traffic(vector<Node> vector_nodes);
        vector<int> get_traffic();
};

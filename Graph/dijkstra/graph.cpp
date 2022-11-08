#include <list>
using namespace std;

class Edge;

class Vertex
{
    public :
        char        name;
        double      distance;
        bool        visited;
        list<Edge*> adjacentEdge;
        Vertex*     predecessor; // parent vertex
                                 //
        Vertex(char name)
        {
            this->name = name;
            this->distance = numeric_limits<double>::infinity();
            this->visited = false;
            this->predecessor = nullptr;
        }

        void    addAdjacentEdge(Edge* e)
        {
            adjacentEdge.push_back(e);
        }
};

// compare distance v1 < v2
class Compare
{
    public :
        bool    operator()(Vertex *v1, Vertex *v2)
        {
            return v1->distance < v2->distance ? true : false;
        }
};

class Edge
{
    public :
        Vertex  *from;
        Vertex  *to;
        int     weight;

        Edge(Vertex* s, Vertex *t, int w)
        {
            this->from = s;
            this->to = t;
            this->weight = w;
        }
};


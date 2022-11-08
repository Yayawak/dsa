#include <iostream>
#include <limits>
#include <queue>
#include "graph.cpp"

class Dijkstra
{
    public :
        Vertex *source;
        priority_queue<Vertex*, vector<Vertex*>, Compare> vertexQueue;

        Dijkstra(Vertex *s)
        {
            this->source = s;
        }

        void    computePath()
        {
            source->distance = 0;
            list<Edge*> :: iterator eit; // iterator to iterate trhouge edges
                                         //
            vertexQueue.push(source);

            while (!vertexQueue.empty())
            {
                Vertex* current_vertex = vertexQueue.top();

                for (Edge* edge : current_vertex->adjacentEdge)
                {
                    Vertex *v = edge->to;

                    if (!v->visited)
                    {
                        if (current_vertex->distance + edge->weight < v->distance)
                        {
                            v->distance = current_vertex->distance + edge->weight;
                            v->predecessor = current_vertex;
                            vertexQueue.push(v);
                        }
                    }
                }
                vertexQueue.pop();
                current_vertex->visited = true;
            }
        }

        list<Vertex*>   shortestPath(Vertex *d)
        {
            list<Vertex*>   shortPath;

            shortPath.push_front(d);
            while (d->predecessor != nullptr)
            {
                shortPath.push_front(d->predecessor);
                d = d->predecessor;
            }
            return shortPath;
        }
};

int     main(void)
{
    Vertex* v[] = {
        new Vertex{'A'},
        new Vertex{'B'},
        new Vertex{'C'}
    };

    Edge*   e[] = {
        new Edge{v[0], v[1], 10},
        new Edge{v[0], v[2], 30},
        new Edge{v[1], v[2], 10},
    };

    v[0]->addAdjacentEdge(e[0]);
    v[0]->addAdjacentEdge(e[1]);
    v[1]->addAdjacentEdge(e[0]);
    v[1]->addAdjacentEdge(e[2]);
    v[2]->addAdjacentEdge(e[1]);
    v[2]->addAdjacentEdge(e[2]);

    Dijkstra dja(v[0]);
    dja.computePath();

    list<Vertex*> shortestPath = dja.shortestPath(v[2]);

    cout << "Shortest path : ";
    for (Vertex* v : shortestPath)
    {
        cout << v->name << " ";
    }

    return (0);
}

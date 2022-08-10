//WEIGHTED SHORTEST PATH (1)        P43859
//TIME LIMIT EXCEEDED

#include <iostream>
#include <utility>
#include <climits>
#include <vector>
#include <queue>

/*graph definitions*/
typedef std::pair<int, double>  arc;        //{node, cost}
typedef std::vector<arc>        adjacents;  //u, v, c such that adjacents[u] is: u -> v with cost c 
typedef std::vector<adjacents>  graph;      //all vertices with its adjacencies

/*compute lenght of shortest path from x to y*/
void shortest_path(const graph& _graph, int x, int y)
{
    std::vector<double> lenght;
    std::priority_queue<arc, std::vector<arc>, std::greater<arc>> next;

    lenght = std::vector<double> (_graph.size(), INT_MAX);  //Initialize distances to infinit

    //starting point is at distance 0
    next.push(std::make_pair(x, 0));
    lenght[x] = 0;

    while (not next.empty())
    {
        arc next_on_line = next.top();
        next.pop();

        for (const auto& it : _graph[next_on_line.first])
        {
            if (lenght[it.first] > lenght[next_on_line.first] + it.second)
            {
                lenght[it.first] = lenght[next_on_line.first] + it.second;
                next.push(std::make_pair(it.first, lenght[it.first]));
            }
        }

    }

    if (lenght[y] == INT_MAX)   std::cout << "no path from " << x << " to " << y << std::endl;
    else                        std::cout << lenght[y] << std::endl;
}

int main(int, char**)
{
    int vertices, arcs, vertex;
    int start_point, target_point;
    graph _graph;
    arc adj;

    while (std::cin >> vertices >> arcs)
    {
        _graph = graph(vertices);
        for (int i = 0; i < arcs; ++i)
        {
            std::cin >> vertex >> adj.first >> adj.second;
            _graph[vertex].push_back(adj);
        }

        std::cin >> start_point >> target_point;
        shortest_path(_graph, start_point, target_point);
    }

    return EXIT_SUCCESS;
}
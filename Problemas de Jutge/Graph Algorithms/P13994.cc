//WEIGHTED SHORTEST PATH(2)		P13994

#include <iostream>
#include <limits>
#include <utility>
#include <vector>
#include <queue>

#define NOT_DEF	-1

/*graph definition*/
typedef std::pair<int, int>		edge; //cost, vertex
typedef std::vector<edge>		adjacents;
typedef std::vector<adjacents>	graph;

void shortest_path(const graph& _graph, int v_source, int v_target)
{
	int nodes;
	std::vector<int>	path;
	std::vector<bool>	visited;
	std::vector<int>	cost;
	std::priority_queue<edge, std::vector<edge>, std::greater<edge>> next;

	nodes	= _graph.size();
	path	= std::vector<int>(nodes, NOT_DEF);
	visited = std::vector<bool>(nodes, false);
	cost	= std::vector<int>(nodes, std::numeric_limits<int>::max());

	cost[v_source] = 0;
	next.push({ 0, v_source });

	while (not next.empty())
	{
		int temp = next.top().second;
		next.pop();
		if (not visited[temp])
		{
			visited[temp] = true;
			for (const auto& it : _graph[temp])
			{
				if (cost[it.second] > cost[temp] + it.first)
				{
					cost[it.second] = cost[temp] + it.first;
					path[it.second] = temp;
					next.push({ cost[it.second], it.second });
				}
			}
		}
	}

	if (cost[v_target] == std::numeric_limits<int>::max())
	{
		std::cout << "no path from " << v_source << " to " << v_target << std::endl;
		return;
	}

	std::vector<int> res_path;
	while (path[v_target] != -1)
	{
		res_path.push_back(v_target);
		v_target = path[v_target];
	}
	res_path.push_back(v_source);

	//for formating purposes
	std::cout << res_path[res_path.size() - 1];
	res_path.pop_back();

	while (res_path.size())
	{
		std::cout << ' ' << res_path[res_path.size() - 1];
		res_path.pop_back();
	}

	std::cout << std::endl;

}

int main(int, char**)
{
	int vertices, edges, vertex;
	graph _graph;
	edge _input;
	while (std::cin >> vertices >> edges)
	{
		_graph = graph(vertices);
		for (int i = 0; i < edges; ++i)
		{
			std::cin >> vertex >> _input.first >> _input.second;
			std::swap(_input.first, _input.second);
			_graph[vertex].push_back(_input);
		}
		int x, y; std::cin >> x >> y;
		shortest_path(_graph, x, y);
	}


	return EXIT_SUCCESS;
}

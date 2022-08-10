//TOPOLOGICAL SORT      P14952

#include <iostream>
#include <vector>
#include <queue>
#include <list>

/*definition of graph*/
typedef std::vector<std::list<int>> graph;

/*simply overload of cout to prints lists*/
std::ostream& operator<<(std::ostream& _cout, const std::list<int>& topo)
{
    int _size = topo.size();
    std::list<int>::const_iterator it;

    it = topo.begin();
    for (int i = 0; i < _size; ++i, ++it)
    {
        if (i <= _size - 2)    
            std::cout << *it << ' ';
        else std::cout << *it;
    }
    return _cout;
}

/*provides a topologic sort of n tasks*/
std::list<int> topo_sort(const graph& _graph)
{
    /*NOTE: important to use priority queue with proper intitialization*/
    /*Need to keep track of which task comes before. Using simple queue/stack*/
    /*Simply makes it so that we pick whatever first task was pushed*/

    unsigned int                                                    g_size;
    std::vector<int>                                                entry_grade;
    std::priority_queue<int, std::vector<int>, std::greater<int>>   next;
    std::list<int>                                                  ret_val;

    g_size = _graph.size();
    entry_grade = std::vector(g_size, 0);

    /*we set correct entry grades of each vertex*/
    for (unsigned int i = 0; i < g_size; ++i)
        for (const auto adjacent : _graph[i])
            ++entry_grade[adjacent];

    for (unsigned int i = 0; i < g_size; ++i)
        if (entry_grade[i] == 0) next.push(i);

    /*DFS traversing*/
    while (not next.empty())
    {
        int vertex = next.top();
        next.pop();
        ret_val.push_back(vertex);
        for (auto adj : _graph[vertex])
            if (--entry_grade[adj] == 0)
                next.push(adj);
    }

    return ret_val;
}

int main(int, char**)
{
    int n_tasks;
    int m_pairs;
    std::pair<int, int> edge;

    while (std::cin >> n_tasks >> m_pairs)
    {   
        graph my_graph;
        my_graph = graph(n_tasks, std::list<int>());

        /*read pairs that indicate tasks order*/
        for (int i = 0; i < m_pairs; ++i)
        {
            std::cin >> edge.first >> edge.second;
            my_graph[edge.first].push_back(edge.second);
        }   

        std::list<int> ret1 = topo_sort(my_graph);

        std::cout << topo_sort(my_graph) << std::endl;

    }
    
    return EXIT_SUCCESS;
}
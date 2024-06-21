#pragma once
#include <iostream>
#include <string>
#include <list>
#include <queue>
#include <unordered_map>
#include <set>


using namespace std;

class graph
{
private:
	unordered_map<string, list<pair<string, int>>> adj_list;
public:
	void addEdge(string, string, int);
	void print();
	void dijkstras(string, string, int&);
};
void graph::addEdge(string vertex1, string vertex2, int weight)
{
	adj_list[vertex1].push_back(make_pair(vertex2, weight));
	adj_list[vertex2].push_back(make_pair(vertex1, weight));
}
void graph::print()
{
	cout << "\n";
	for (auto i : adj_list)
	{
		cout << " " << i.first << " -> ";
		for (auto j : i.second)
			cout << " (" << j.first << " , " << j.second << ") ";
		cout << endl;
	}
	cout << "\n";
}
void graph::dijkstras(string source, string destination, int& d)
{
	unordered_map<string, int>distance;
	string dest;
	for (auto i : adj_list)
		distance[i.first] = INT_MAX;

	set<pair<int, string>> node;

	distance[source] = 0;
	node.insert(make_pair(0, source));
	int temp = 0;
	while (!node.empty())
	{
		auto temp = *(node.begin());
		string source = temp.second;

		int node1 = temp.first;
		node.erase(node.begin());

		for (auto i : adj_list[source])
		{
			if (node1 + i.second < distance[i.first])
			{
				dest = i.first;
				auto final = node.find(make_pair(distance[dest], dest));

				if (final != node.end())
					node.erase(final);

				distance[dest] = node1 + i.second;
				node.insert(make_pair(distance[dest], dest));
			}
		}
		for (auto i : distance)
		{
			if (i.first == destination)
				d = i.second;
		}
	}
}
/////////////////////////////////////////////////////////////////////////////

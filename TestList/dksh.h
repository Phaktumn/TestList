#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;
#define INF INT_MAX //Infinity

class prioritize
{
public:
	bool operator ()(pair<int, int>&p1, pair<int, int>&p2) const
	{
		return p1.second>p2.second;
	}
};

template<class T>
class Graph
{
private:
	int sz = 10001;
	vector<pair<int, int> > a[];
	int dis[];
	bool vis[] = { 0 };

public:
	Graph(int size, T node)
	{
		a[sz];
		dis[sz];
		vis[sz];

		a->push_back(make_pair(node, rand() % 100));
	}
	void Dijkstra(T source, int n);
};

template <class T>
void Graph<T>::Dijkstra(T source, int n)
{
	for (int i = 0; i<sz; i++) //Set initial distances to Infinity
		dis[i] = INF;
	priority_queue<pair<T, int>, vector<pair<T, int> >, prioritize> pq;
	pq.push(make_pair(source, dis[source] = 0));
	while (!pq.empty())
	{
		pair<int, int> curr = pq.top();
		pq.pop();
		int cv = curr.first, cw = curr.second;
		if (vis[cv]) continue;
		vis[cv] = true;
		for (int i = 0; i < a[cv].size(); i++)
		{
			if (!vis[a[cv][i].first] && a[cv][i].second + cw < dis[a[cv][i].first])
			{
				pq.push(make_pair(a[cv][i].first, (dis[a[cv][i].first] = a[cv][i].second + cw)));
			}
		}
	}
}


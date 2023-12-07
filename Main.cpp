#include <iostream>
#include <vector>
#include "Graph/Graph.h"

#define MATRIX_SIZE_ROWS 7
#define MATRIX_SIZE_COLUMNS 7

void SetupGraph(Graph& graph)
{
	// first island
	graph.AddLand(0, 1);
	graph.AddLand(1, 0);
	graph.AddLand(1, 1);
	graph.AddLand(2, 1);
	// second island
	graph.AddLand(1, 6);
	// third island
	graph.AddLand(3, 4);
	graph.AddLand(4, 4);
	// fourth island
	graph.AddLand(5, 1);
	// fifth island
	graph.AddLand(6, 3);
	graph.AddLand(6, 4);
}

int main()
{
	Graph graph(MATRIX_SIZE_ROWS, MATRIX_SIZE_COLUMNS);
	graph.Initialize();
	SetupGraph(graph);

	std::cout << "The island count = " << graph.CountIslands() << '\n';
	std::cout << "The minimum island size = " << graph.GetMinimumIslandSize() << '\n';

	return 0;
}
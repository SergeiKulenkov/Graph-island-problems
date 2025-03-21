#include <iostream>
#include "Graph/Graph.h"

constexpr int gridSize = 7;

///////////////

void SetupGraph(std::vector<int>& landCells)
{
	// column numer (x), row number (y)
	// first island
	landCells.emplace_back(0 + gridSize * 1);
	landCells.emplace_back(1 + gridSize * 0);
	landCells.emplace_back(1 + gridSize * 1);
	landCells.emplace_back(2 + gridSize * 1);
	// second island
	landCells.emplace_back(1 + gridSize * 6);
	// third island
	landCells.emplace_back(3 + gridSize * 4);
	landCells.emplace_back(4 + gridSize * 4);
	// fourth island
	landCells.emplace_back(5 + gridSize * 1);
	// fifth island
	landCells.emplace_back(6 + gridSize * 3);
	landCells.emplace_back(6 + gridSize * 4);
}

void Run(Graph& graph)
{
	std::cout << "The island count = " << graph.CountIslands() << '\n';
	std::cout << "The minimum island size = " << graph.GetMinimumIslandSize() << '\n';
}

int main()
{
	std::vector<int> landCells;
	SetupGraph(landCells);

	Graph graph(gridSize, landCells);
	Run(graph);

	return 0;
}
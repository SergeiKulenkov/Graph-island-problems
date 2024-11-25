#pragma once
#include <vector>
#include "Cell.h"

class Graph
{
public:
	Graph();

	Graph(const int size, const std::vector<int>& landCells);

	// adds land at specified grid position
	void AddLand(const int columnNumber, const int rowNumber);

	// uses BFS to count islands
	int CountIslands();

	// uses BFS to find minimum island's size
	int GetMinimumIslandSize();

private:
	void ResetSearchData();

	// explores an island using BFS and returns true when an island is explored
	bool ExploreBreadthFirst(const int columnNumber, const int rowNumber);

	// explores an island using BFS and returns its size
	int ExploreSizeBreadthFirst(const int columnNumber, const int rowNumber);

	//////////

	int m_GridSize;
	std::vector<Cell> m_Cells;
	std::vector<bool> m_Visited;
};
#pragma once
#include <vector>
#include <string>

class Graph
{
public:
	Graph();
	Graph(int numberOfRows, int numberOfColumns);

	// fills all cells with water, optionally can change the size of the matrix
	void Initialize(int numberOfRows = 0, int numberOfColumns = 0);

	// adds land at specified matrix position
	void AddLand(int rowNumber, int columnNumber);

	// uses BFS, returns island count
	int CountIslands();

	// uses BFS, returns the minimum island's size
	int GetMinimumIslandSize();

private:
	// explores an island using BFS and returns true when an island is explored
	bool ExploreBreadthFirst(int rowNumber, int columnNumber, std::vector<std::vector<bool>>& visited);

	// explores an island using BFS and returns its size
	int ExploreSizeBreadthFirst(int rowNumber, int columnNumber, std::vector<std::vector<bool>>& visited);

	//////////

	std::vector<std::vector<std::string>> adjacencyMatrix;
};
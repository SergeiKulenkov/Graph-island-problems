#include "Graph.h"

#define WATER "Water"
#define LAND "Land"

Graph::Graph()
{
	// by default initialize as 1x1 and set to water
	adjacencyMatrix.resize(1, std::vector<std::string>(1));
	adjacencyMatrix[0][0] = WATER;
}

Graph::Graph(int numberOfRows, int numberOfColumns)
{
	adjacencyMatrix.resize(numberOfRows, std::vector<std::string>(numberOfColumns));
}

void Graph::Initialize(int numberOfRows, int numberOfColumns)
{
	if ((numberOfRows != 0) && (numberOfColumns != 0))
	{
		adjacencyMatrix.resize(numberOfRows, std::vector<std::string>(numberOfColumns));
	}

	for (int rowIndex = 0; rowIndex < adjacencyMatrix.size(); rowIndex++)
	{
		for (int columnIndex = 0; columnIndex < adjacencyMatrix[0].size(); columnIndex++)
		{
			adjacencyMatrix[rowIndex][columnIndex] = WATER;
		}
	}
}

void Graph::AddLand(int rowNumber, int columnNumber)
{
	adjacencyMatrix[rowNumber][columnNumber] = LAND;
}

bool Graph::ExploreBreadthFirst(int rowNumber, int columnNumber, std::vector<std::vector<bool>>& visited)
{
	bool explored = false;
	const bool isRowInbounds = ((rowNumber >= 0) && (rowNumber < adjacencyMatrix.size()));
	const bool isColumnInbounds = ((columnNumber >= 0) && (columnNumber < adjacencyMatrix[0].size()));

	if (isRowInbounds && isColumnInbounds && !visited.at(rowNumber).at(columnNumber) &&
		(adjacencyMatrix[rowNumber][columnNumber] == LAND))
	{
		visited.at(rowNumber).at(columnNumber) = true;
		ExploreBreadthFirst(rowNumber - 1, columnNumber, visited);
		ExploreBreadthFirst(rowNumber + 1, columnNumber, visited);
		ExploreBreadthFirst(rowNumber, columnNumber - 1, visited);
		ExploreBreadthFirst(rowNumber, columnNumber + 1, visited);
		explored = true;
	}

	return explored;
}

int Graph::ExploreSizeBreadthFirst(int rowNumber, int columnNumber, std::vector<std::vector<bool>>& visited)
{
	int size = 0;
	const bool isRowInbounds = ((rowNumber >= 0) && (rowNumber < adjacencyMatrix.size()));
	const bool isColumnInbounds = ((columnNumber >= 0) && (columnNumber < adjacencyMatrix[0].size()));

	if (isRowInbounds && isColumnInbounds && !visited.at(rowNumber).at(columnNumber) &&
		(adjacencyMatrix[rowNumber][columnNumber] == LAND))
	{
		size = 1;
		visited.at(rowNumber).at(columnNumber) = true;
		size += ExploreSizeBreadthFirst(rowNumber - 1, columnNumber, visited);
		size += ExploreSizeBreadthFirst(rowNumber + 1, columnNumber, visited);
		size += ExploreSizeBreadthFirst(rowNumber, columnNumber - 1, visited);
		size += ExploreSizeBreadthFirst(rowNumber, columnNumber + 1, visited);
	}

	return size;
}

int Graph::CountIslands()
{
	int count = 0;
	std::vector<std::vector<bool>> visited;
	visited.resize(adjacencyMatrix.size(), std::vector<bool>(adjacencyMatrix[0].size()));

	for (int rowIndex = 0; rowIndex < adjacencyMatrix.size(); rowIndex++)
	{
		for (int columnIndex = 0; columnIndex < adjacencyMatrix[0].size(); columnIndex++)
		{
			if (!visited[rowIndex][columnIndex])
			{
				if (ExploreBreadthFirst(rowIndex, columnIndex, visited))
				{
					count++;
				}
			}
		}
	}

	return count;
}

int Graph::GetMinimumIslandSize()
{
	int minSize = INT_MAX;
	int size = 0;
	std::vector<std::vector<bool>> visited;
	visited.resize(adjacencyMatrix.size(), std::vector<bool>(adjacencyMatrix[0].size()));

	for (int rowIndex = 0; rowIndex < adjacencyMatrix.size(); rowIndex++)
	{
		for (int columnIndex = 0; columnIndex < adjacencyMatrix[0].size(); columnIndex++)
		{
			if (!visited[rowIndex][columnIndex])
			{
				size = ExploreSizeBreadthFirst(rowIndex, columnIndex, visited);
				if ((size > 0) &&
					(size < minSize))
				{
					minSize = size;
				}
			}
		}
	}

	return minSize;
}
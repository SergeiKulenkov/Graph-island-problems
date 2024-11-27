#include "Graph.h"

Graph::Graph()
{
	// by default initialize as 1x1 and set to water
	m_Cells.emplace_back(CellType::Water);
	m_GridSize = 1;
}

Graph::Graph(const int size, const std::vector<int>& landCells)
{
	m_GridSize = size;
	m_Cells.resize(m_GridSize * m_GridSize);
	for (int index = 0; index < m_Cells.size(); index++)
	{
		m_Cells[index].ChangeType(CellType::Water);
	}

	for (const int index : landCells)
	{
		m_Cells[index].ChangeType(CellType::Land);
	}

	m_Visited.resize(m_Cells.size(), false);
}

void Graph::ResetSearchData()
{
	std::fill(m_Visited.begin(), m_Visited.end(), false);
}

void Graph::AddLand(const int columnNumber, const int rowNumber)
{
	if (columnNumber + m_Cells.size() * rowNumber < m_Cells.size())
	{
		m_Cells[columnNumber + m_Cells.size() * rowNumber].ChangeType(CellType::Land);
	}
}

bool Graph::ExploreBreadthFirst(const int columnNumber, const int rowNumber)
{
	bool explored = false;
	const bool isRowInbounds = ((rowNumber >= 0) && (rowNumber < m_GridSize));
	const bool isColumnInbounds = ((columnNumber >= 0) && (columnNumber < m_GridSize));

	if (isRowInbounds && isColumnInbounds && !m_Visited[columnNumber + m_GridSize * rowNumber] &&
		(m_Cells[columnNumber + m_GridSize * rowNumber].GetType() == CellType::Land))
	{
		m_Visited[columnNumber + m_GridSize * rowNumber] = true;
		ExploreBreadthFirst(columnNumber - 1, rowNumber);
		ExploreBreadthFirst(columnNumber + 1, rowNumber);
		ExploreBreadthFirst(columnNumber, rowNumber - 1);
		ExploreBreadthFirst(columnNumber, rowNumber + 1);
		explored = true;
	}

	return explored;
}

int Graph::ExploreSizeBreadthFirst(const int columnNumber, const int rowNumber)
{
	int size = 0;
	const bool isRowInbounds = ((rowNumber >= 0) && (rowNumber < m_GridSize));
	const bool isColumnInbounds = ((columnNumber >= 0) && (columnNumber < m_GridSize));

	if (isRowInbounds && isColumnInbounds && !m_Visited[columnNumber + m_GridSize * rowNumber] &&
		(m_Cells[columnNumber + m_GridSize * rowNumber].GetType() == CellType::Land))
	{
		size = 1;
		m_Visited[columnNumber + m_GridSize * rowNumber] = true;
		size += ExploreSizeBreadthFirst(columnNumber - 1, rowNumber);
		size += ExploreSizeBreadthFirst(columnNumber + 1, rowNumber);
		size += ExploreSizeBreadthFirst(columnNumber, rowNumber - 1);
		size += ExploreSizeBreadthFirst(columnNumber, rowNumber + 1);
	}

	return size;
}

int Graph::CountIslands()
{
	ResetSearchData();
	int count = 0;

	for (int cellIndex = 0; cellIndex < m_Cells.size(); cellIndex++)
	{
		if (!m_Visited[cellIndex])
		{
			if (ExploreBreadthFirst(cellIndex % m_GridSize, cellIndex / m_GridSize))
			{
				count++;
			}
		}
	}

	return count;
}

int Graph::GetMinimumIslandSize()
{
	ResetSearchData();
	int minSize = INT_MAX;
	int size = 0;

	for (int cellIndex = 0; cellIndex < m_Cells.size(); cellIndex++)
	{
		if (!m_Visited[cellIndex])
		{
			size = ExploreSizeBreadthFirst(cellIndex % m_GridSize, cellIndex / m_GridSize);
			if ((size > 0) &&
				(size < minSize))
			{
				minSize = size;
			}
		}
	}

	return minSize;
}
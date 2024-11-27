#pragma once

enum CellType
{
	None = 0,
	Water = 1,
	Land = 2,
};

class Cell
{
public:
	Cell() : m_Type(CellType::None)
	{ }

	Cell(CellType type) : m_Type(type)
	{ }

	void ChangeType(CellType type) { m_Type = type; }

	CellType GetType() const { return m_Type; }

private:
	CellType m_Type;
};
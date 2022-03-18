#include "VectorMatrix.h"

void VectorMatrix::SetUp(unsigned inputAmountPoints)
{
	amountPoints = inputAmountPoints;
	xMedian = 0;
	points.clear();
	points.reserve(amountPoints);
}
bool VectorMatrix::TryShow()
{
	if (points.empty()) { return false; }
	for (int i = 0; i < amountPoints; i++)
	{
		printf("Point%i(%i; %i)\n", i+1, points[i][0], points[i][1]);
	}
	return true;
}

float VectorMatrix::GetMedian()
{
	if (points.size() == 0) { return 0; }
	if (xMedian == 0) { CalculatingMedian(); }
	return xMedian;
}
unsigned VectorMatrix::GetAmountCoords()
{
	return amountCoords;
}

bool VectorMatrix::TryAddPoint(vector<unsigned> point)
{
	if (OnOneLine(point)) { return false; }

	points.push_back(point);
	Sort(0, points.size() - 1);
	return true;
}
bool VectorMatrix::OnOneLine(vector<unsigned> point)
{
	unsigned end = points.size() > 0 ? points.size() - 1 : 0;
	for (int i = 0; i < end; i++)
	{
		for (int j = 0; j < amountCoords; j++)
			if (points[i][j] == point[j]) { return true; }
	}

	return false;
}

void VectorMatrix::CalculatingMedian()
{
	if (amountPoints % 2 == 0)
	{
		unsigned mid = amountPoints / 2;
		xMedian = (points[mid][0] + points[mid + 1][0]) / 2;
	}
	else
	{
		unsigned mid = amountPoints / 2;
		xMedian = points[mid][0];
	}
}
void VectorMatrix::Sort(unsigned start, unsigned end)
{
	for (int i = start; i < end; i++)
		if (points[end][0] < points[i][0]) { swap(points[end][0], points[i][0]); }
}
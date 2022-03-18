#include <vector>
#include <ctime>
#pragma once

using namespace std;

class VectorMatrix
{
public:
	void SetUp(unsigned inputAmountPoints);
	bool TryShow();
	float GetMedian();
	unsigned GetAmountCoords();

	bool TryAddPoint(vector<unsigned> point);

private:
	float xMedian = 0;

	unsigned const amountCoords = 2;
	unsigned amountPoints = 0;
	vector<vector<unsigned>> points;

	bool OnOneLine(vector<unsigned> point);

	void CalculatingMedian();
	void Sort(unsigned start, unsigned end);
};


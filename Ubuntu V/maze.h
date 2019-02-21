#pragma once
const int M=8;
const int N=7;

class Cell
{
public:
	Cell();
	void Draw(int i, int j);
	bool getTop();
	bool getBottom();
	bool getLeft();
	bool getRight();
	void SetBottom(bool state);
	void SetTop(bool state);
	void SetRight(bool state);
	void SetLeft(bool state);
	void SetVisited(bool state);
	bool GetVisited();
private:
	bool mLeft, mTop, mRight, mBottom;
	bool mVisited;
};

class Maze
{
public:
	Maze();
	void Init();
	int getStart();
	int getEndX();
	int getEndY();
	int getM();
	int getN();
	void removeTopWall(double x_in, double y_in, bool bool_in);
	void removeBottomWall(double x_in, double y_in, bool bool_in);
	void removeRightWall(double x_in, double y_in, bool bool_in);
	void removeLeftWall(double x_in, double y_in, bool bool_in);
	void Draw();
	void RemoveWallsR(int i, int j);
	bool isValid(int i_in, int j_in);
	bool isItWall(double x_in, double y_in, double radius_in);

private:
	Cell mCells[M][N];
	int mStartI;
	int mEndI;
};

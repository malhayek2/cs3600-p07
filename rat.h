#ifndef _RAT_H_
#define _RAT_H_
#include "maze.h"

class Rat
{
public:
	Rat();
	~Rat();
	void setMaze(Maze *maze_in);
	double getX();
	double getY();
	double getRad();
	double getRed();
	double getGreen();
	double getBlue();
	void setX(double x_in);
	void setY(double y_in);
	void setRadius(double radius_in);
	void setRed(double red_in);
	void setGreen(double green_in);
	void setBlue(double blue_in);
	void Init(double start_x_in);
	void Reset(double start_x_in);
	void jEnd(double end_x_in, double end_y_in);
	void randomJump(int xRange, int yRange);
	void move();
	void Draw();
	double getDirection();
	void setDirection(double dir_in);
	void spinLeft();
	void spinRight();
	void goLeft();
	void goRight();
private:
	double rRed, rGreen, rBlue;
	double sizeX, sizeY, rRadius;
	double mDirection;
	double spinSpeed;
	double mSpeed;
	Maze *mMaze;
};


#endif

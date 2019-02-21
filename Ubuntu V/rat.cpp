#pragma once
#define _USE_MATH_DEFINES
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <random>
using namespace std;
#include "rat.h"
#include <GL/glut.h>
#include "graphics.h"


Rat::Rat()
{
	this->rRadius = 0.25;
	this->rBlue = .5;
	this->rGreen = .5;
	this->rRed = .5;
	this->sizeX = 0.5;
	this->sizeY = 0.5;
	this->mDirection = 90;
	this->spinSpeed = 1.0;
	this->mSpeed = .00445555;
}

Rat::~Rat()
{

}

void Rat::goLeft()
{
	double radians = mDirection / 90*M_PI;
	double dx = cos(radians);
	double dy = sin(radians);
	double newX = sizeX - dx*mSpeed;
	double newY = sizeY + dy*mSpeed;
	if (!mMaze->isItWall(newX, newY, rRadius)){
		this->sizeX = newX;
		this->sizeY = newY;
	} 
	if (!mMaze->isItWall(sizeX, newY, rRadius)){
		this->sizeY = (newY);
	}
	if (!mMaze->isItWall(newX, sizeY, rRadius)){
		this->sizeX = (newX);
	}
}

void Rat::goRight()
{
	double radians = mDirection / 90*M_PI;
	double dx = cos(radians);
	double dy = sin(radians);
	double newX = sizeX + dx*mSpeed;
	double newY = sizeY - dy*mSpeed;
	if (!mMaze->isItWall(newX, newY, rRadius)){
		this->sizeX = newX;
		this->sizeY = newY;
	} 
	if (!mMaze->isItWall(sizeX, newY, rRadius)){
		this->sizeY = (newY);
	}
	if (!mMaze->isItWall(newX, sizeY, rRadius)){
		this->sizeX = (newX);
	}
}


void Rat::setMaze(Maze *maze_in)
{
	this->mMaze = maze_in;
}

double Rat::getX()
{
	return this->sizeX;
}

double Rat::getY()
{
	return this->sizeY;
}

double Rat::getRad()
{
	return this->rRadius;
}

double Rat::getRed()
{
	return this->rRed;
}

double Rat::getGreen()
{
	return this->rGreen;
}

double Rat::getBlue()
{
	return this->rBlue;
}

void Rat::setX(double x_in)
{
	this->sizeX = x_in;
}

void Rat::setY(double y_in)
{
	this->sizeY = y_in;
}

void Rat::setRadius(double radius_in)
{
	this->rRadius = radius_in;
}

void Rat::setRed(double red_in)
{
	this->rRed = red_in;
}

void Rat::setGreen(double green_in)
{
	this->rGreen = green_in;
}

void Rat::setBlue(double blue_in)
{
	this->rBlue = blue_in;
}

double Rat::getDirection()
{
	return this->mDirection;
}

void Rat::setDirection(double dir_in)
{
	this->mDirection = dir_in;
}

void Rat::Init(double start_x_in)
{
	this->sizeX += start_x_in;
}

void Rat::Reset(double start_x_in)
{
	
	this->sizeX = 0.5 + start_x_in;
	this->sizeY = 0.5;
	
}

void Rat::jEnd(double end_x_in, double end_y_in)
{
	this->sizeX = 0.5 + end_x_in;
	this->sizeY = 0.5 + end_y_in;
}

void Rat::randomJump(int xRange, int yRange)
{
	int tempX = xRange;
	int tempY = yRange;
	
	int newx = rand()%tempX;
	int newy = rand()%tempY;
	//cout << newx << " " << newy << endl;
	this->sizeX = 0.5 + newx;
	this->sizeY = 0.5 + newy;
}

void Rat::move()
{
	double radians = mDirection / 180*M_PI;
	double dx = cos(radians);
	double dy = sin(radians);
	double newX = sizeX + dx*mSpeed;
	double newY = sizeY + dy*mSpeed;
	if (!mMaze->isItWall(newX, newY, rRadius)){
		this->sizeX = newX;
		this->sizeY = newY;
	} 
	if (!mMaze->isItWall(sizeX, newY, rRadius)){
		this->sizeY = (newY);
	}
	if (!mMaze->isItWall(newX, sizeY, rRadius)){
		this->sizeX = (newX);
	}
	
}

void Rat::spinLeft()
{
	this->mDirection += spinSpeed;
}

void Rat::spinRight()
{
	this->mDirection -= spinSpeed;
}

void Rat::Draw()
{
	glPushMatrix();
	glTranslated(sizeX,sizeY,0);
	glRotated(mDirection,0,0,1);
	glColor3d(.5,.5,.5);
	DrawCircle(0, 0, rRadius);
	glColor3d(0,0,0);
	DrawCircle(0+.25, 0, .05);
	glPopMatrix();
	//cout << "rat instance is it drawing? " << this->sizeX << endl;
	/*if(current_view == rat_view)
	{
		return; // drawing yourself in rat view looks bad.
	}*/
}

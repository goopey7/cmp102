//Copyright Sam Collier 2022

#include "MyRobot.h"

MyRobot::MyRobot(Room* room)
	: room(room)
{
}

MyRobot::~MyRobot()
{
}

void MyRobot::move(int n)
{
	for(int i=n;i>0;i--)
	{
		if(Robot::obstacle_ahead(room))
			return;
		Robot::move();
	}
}

void MyRobot::back()
{
	switch(Robot::get_dir())
	{
		case NORTH:
			Robot::setY(Robot::get_ypos()+1);
			break;
		case SOUTH:
			Robot::setY(Robot::get_ypos()-1);
			break;
		case EAST:
			Robot::setX(Robot::get_xpos()-1);
			break;
		case WEST:
			Robot::setX(Robot::get_xpos()+1);
			break;
		default:
			break;
	}
}

bool MyRobot::goTo(int x,int y)
{
	if(room->isObstacle(x,y))
		return false;
	Robot::setX(x);
	Robot::setY(y);
	return true;
}


//Copyright Sam Collier 2022
#pragma once

#include "Robot.h"

class MyRobot : public Robot
{
	public:
		MyRobot(Room* room);
		~MyRobot();

		void move(int n);
		void back();
		bool goTo(int x,int y);

	private:
		Room* room;
		
};


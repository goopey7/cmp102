#include <iostream>
#include "GraphicsManager.h"	
#include "MyRobot.h"

//Ponter reference to classes
Room* room;
MyRobot* robby;
GraphicsManager *picture;

int main()

{
	room = new Room(2);
	robby = new MyRobot(room);
	picture = new GraphicsManager(room, robby);

	// Speed of the render delay in milliseconds
	picture->setDrawDelay(250);
	picture->draw();

	robby->move(5);
	picture->draw();

	robby->right();
	picture->draw();

	// won't move 15 entirely since obstacle in the way
	robby->move(15);
	picture->draw();

	for(int i=0; i<5; i++)
	{
		robby->back();
		picture->draw();
	}

	if(!robby->goTo(0,0))
		std::cout << "Tile unreachable\n";
	else picture->draw();

	if(robby->goTo(10,10))
		picture->draw();
	else std::cout << "Tile unreachable\n";

	//End of Instructions for Robby
	std::cin.get();
}

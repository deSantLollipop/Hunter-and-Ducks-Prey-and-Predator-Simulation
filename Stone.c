#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>//without this my visual studio don't want to recognise normaly 'bool'

//There is lake, where are ducks and huter, simulation of hunting game.
{
	int a;
};

struct Duck //ducks has health, ability to fly away and damage they get
{
	bool flyable;
	int hp;
	int getdamage;
	struct duck *next;// somehow i have to create a list or massive of ducks, and fill it randomly
}first;

struct Hunter //hunter has his own health and damage
{
	int hp;
	int damage;
};

struct Duck MallardDuck = {true,100,0}; //each type of ducks have their parameters
struct Duck RedHatDuck  = {true,120,0};
struct Duck RubberDuck  = {false, 200, 20};



int main()
{
	//struct Duck mas[] or some list


system("pause");
return 0;
}


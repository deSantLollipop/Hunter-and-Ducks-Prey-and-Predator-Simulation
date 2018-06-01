#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
//There is lake, where are ducks and huter, simulation of hunting game.
struct Lake
{
	int a;
};

struct Duck //ducks has health, ability to fly away and damage they get
{
	bool flyable;
	int hp;
	int getdamage;
	struct duck *next;
}first;

struct Hunter //hunter has his own health and damage
{
	int hp;
	int damage;
};

struct Duck MallardDuck = {true,100,0}; 
struct Duck RedHatDuck  = {true,120,0};
struct Duck RubberDuck  = {false, 200, 20};



int main()
{
	//struct Duck mas[]


sustem("pause");
return 0;
}


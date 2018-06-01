#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

struct Lake
{
	int a;
};

struct Duck
{
	bool flyable;
	int hp;
	int getdamage;
	struct duck *next;
}first;

struct Hunter
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


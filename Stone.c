#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h> // It seems that you may not need on other computer this library

struct Hunter
{
	bool alive;
	int hp;
	int getdamage;
};

struct Hunter Robbin = {true, 500, 0 }; // the hunter himself

struct Duck {       // main structure for ducks with set parametrs

	bool alive;
	bool flyable;
	int hp;
	int getdamage;
	char type[3];
};

struct Duck RedHatDuck = { true, true,  80, 0, "rdh" };
struct Duck MallardDuck = { true, true,  70, 0, "mlr" };
struct Duck RubberDuck =  { true, false, 200, 0, "rbr" };

struct Duck ducks[20]; // array of structures (max 20, in my point of view 20 ducks for one small lake is enough)


int DuckArray(int i, int typd, int rhtcount, int rbrcount, int mlrcount, int numd)
{
	int DHP = 0;
	for (i = 0; i<numd; i++)
	{
		typd = rand() % 3; // randomly chooses type of duck
		if (typd == 0)
		{
			ducks[i] = RedHatDuck;
			rhtcount++;
			DHP += ducks[i].hp;
		}
		if (typd == 1)
		{
			ducks[i] = MallardDuck;
			mlrcount++;
			DHP += ducks[i].hp;
		}
		if (typd == 2)
		{
			ducks[i] = RubberDuck;
			rbrcount++;
			DHP += ducks[i].hp;
		}

		if (i == (numd - 1))
		{
			printf("Ducks in total : %d\n", numd);
			printf("RedhatDucks : %d\n", rhtcount);
			printf("MallarDucks : %d\n", mlrcount);
			printf("RubberDucks : %d\n", rbrcount);
		}
	}
	return DHP;
}


int main()
{
	srand(time(NULL));
	int i = 0, typd = 0, rhtcount = 0, rbrcount = 0, mlrcount = 0;
	int numd = rand() % 21;  //randomly choose number of ducks
	int DHP = DuckArray(i,typd,rhtcount,rbrcount,mlrcount,numd);
	//printf("DHP = %d", DHP);


	system("pause");
	return 0;
}

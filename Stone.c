#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h> // It seems that you may not need on other computer this library

struct Hunter
{
	bool alive;
	int hp;
	int dmg;
};

struct Hunter Robbin = {true, 500, 50 }; // the hunter himself

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

void Start()
{
	srand(time(NULL));

	int i = 0, typd = 0, rhtcount = 0, rbrcount = 0, mlrcount = 0, crit = 11, shotnum; //typd - duck type;		xxxcount - each type counters;	crit - critical hit;	stotnum - shot counter
	
	int numd = rand() % 21;  //randomly choose number of ducks
	int r;


	
	int DHP = DuckArray(i, typd, rhtcount, rbrcount, mlrcount, numd); //HP of all ducks & duckarray creation
	//printf("DHP = %d", DHP);

	printf("Hunter has %d HP and %d DMG \n", Robbin.hp, Robbin.dmg);
	printf("-----------------------------------------------------------------------------------------------------------------");

	printf("Hunter is shooting \n");

	while (DHP > 0)
	{
		r = rand() % 9;
		if (r > 3)
		{
			ducks[i].hp -= Robbin.dmg;
			crit--;
			shotnum++;
			printf("Possible critical hit= %d %", 100 / r);
			printf("Hunter shot number = %d ", shotnum);
			break;
		}
		else
			switch (r)
			{
			case 0:
				printf("Possible critical hit= %d %", 100 / (crit - 1));
				ducks[i].hp -= Robbin.dmg * 2;
				printf("Critical damage x2!");
				shotnum++;
				crit = 10;
				printf("Hunter shot number = %d ", shotnum);
			case 1:
				ducks[i].hp -= Robbin.dmg;
				crit--;
				shotnum++;
				printf("Possible critical hit= %d %", 100 / r);
				printf("Hunter shot number = %d ", shotnum);
				break;
			case 2:
				ducks[i].hp -= Robbin.dmg;
				crit--;
				shotnum++;
				printf("Possible critical hit= %d %", 100 / r);
				printf("Hunter shot number = %d ", shotnum);
				break;
			case 3:
				ducks[i].hp -= Robbin.dmg;
				crit--;
				shotnum++;
				printf("Possible critical hit= %d %", 100 / r);
				printf("Hunter shot number = %d ", shotnum);
				break;
			default:
				printf("Something is wrong.");
				break;
			}

				if (Robbin.hp <= 0)
				{
					printf("Duck won!!!");
					break;
				}
				else if (DHP <= 0)
				{
					printf("Hunter won!!!");
					break;
				}
		
				i++;
	}
}






int main()
{
	


	system("pause");
	return 0;
}

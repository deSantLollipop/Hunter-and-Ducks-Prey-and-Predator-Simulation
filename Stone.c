#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h> // It seems that you may not need on other computer this library

struct Hunter
{
	bool alive;
	double hp;
	double dmg;
};

struct Hunter Robbin = {true, 500.0, 80.0 }; // the hunter himself

struct Duck {       // main structure for ducks with set parametrs


	bool here;
	bool alive;
	bool flyable;
	double hp;
	double dmg;
	char type[3];
};

struct Duck RedHatDuck =  { true, true, true,  120.0, 0.0, "rdh" };
struct Duck MallardDuck = { true, true, true, 130.0, 0.0, "mlr" };
struct Duck RubberDuck =  { true, true, false, 200.0, 20.0, "rbr"};

struct Duck ducks[10]; // array of structures (max 20, in my point of view 20 ducks for one small lake is enough)


int DuckArray(int i, int typd, int rhtcount, int rbrcount, int mlrcount, int numd)
{
	int DHP = 0;
	for (i = 0; i < numd; i++)
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

	int i = 0, j, r = 0, r1 = 0, r0, typd = 0, rhtcount = 0, rbrcount = 0, mlrcount = 0, crit = 11, shotnum = 0, dklive = 0, dkill = 0; //typd - duck type;		xxxcount - each type counters;	crit - critical hit;	stotnum - shot counter;		dklive - number of allive ducks;	dkill- kill counter;
	char s[3];
	//int numd = rand() % 19;  //randomly choose number of ducks
	int numd = 10;
	dklive = numd;


	int DHP = DuckArray(i, typd, rhtcount, rbrcount, mlrcount, numd); //HP of all ducks & duckarray creation
	printf("\nDHP = %d\n", DHP);
	printf("Hunter has %.f HP and %.f DMG \n", Robbin.hp, Robbin.dmg);
	printf("---------------------------------------------------------------\n");
	printf("Press  <-'ENTER    to start the hunt ... \n");
	scanf("%c", s);


	while (DHP > 0)
	{

		r0 = 2;//rand() % 3 + 1;             //hunter has from 1 to 3 shots  

		for (j=0; j < r0; j++)
		{
			if (ducks[i].alive == false)
				i++;

			r = rand() % 9;
			if (r > 3)
			{

				r1 = rand() % 4;
				printf("Possible critical hit= %d % \n", 100 / crit);
				if (r1 == 0)												// possibility of critical hit is 0.2
				{
					ducks[i].hp -= Robbin.dmg + Robbin.dmg*(crit / 100.0);
					printf("duck [%d] hp = %.f \n", i, ducks[i].hp);
					crit = rand() % 10 + 1;
					shotnum++;
					printf("Hunter shot number = %d \n", shotnum);
					printf("---------------------------------------------------------------\n");

				}
				else
				{
					ducks[i].hp -= Robbin.dmg;
					printf("duck [%d] hp = %.f \n", i, ducks[i].hp);
					crit = rand() % 10 + 1;
					shotnum++;
					printf("Hunter shot number = %d \n", shotnum);
					printf("---------------------------------------------------------------\n");
				}
			}
			else
			{
				switch (r)
				{
				case 0:
					printf("Possible critical hit= %d % \n", 100 / 2);
					ducks[i].hp -= Robbin.dmg * 2;
					printf("Critical damage x2!\n");
					printf("duck [%d] hp = %.f \n", i, ducks[i].hp);
					shotnum++;
					crit = 10;
					printf("Hunter shot number = %d \n", shotnum);
					printf("---------------------------------------------------------------\n");
					break;
				case 1:
					printf("Possible critical hit= %d % \n", 100 / crit);
					crit = rand() % 10 + 1;
					printf("duck [%d] hp = %.f \n", i, ducks[i].hp);
					shotnum++;
					printf("Hunter missed, but duck still here\n");
					printf("Hunter shot number = %d \n", shotnum);
					printf("---------------------------------------------------------------\n");
					break;
				case 2:
					printf("Possible critical hit= %d % \n", 100 / crit);
					crit = rand() % 10 + 1;
					printf("duck [%d] hp = %.f \n", i, ducks[i].hp);
					shotnum++;
					if (ducks[i].flyable == true)
					{
						printf("Hunter missed, duck flew away ..\n");
						ducks[i].here = false;
					}
					printf("Hunter shot number = %d \n", shotnum);
					printf("---------------------------------------------------------------\n");
					break;
				case 3:
					printf("Possible critical hit= %d % \n", 100 / crit);
					crit = rand() % 10 + 1;
					printf("duck [%d] hp = %.f \n", i, ducks[i].hp);
					shotnum++;
					if (ducks[i].flyable == false)
					{
						printf("Ricochet hited hunter...\n");
						Robbin.hp -= 30 + 20 * (10 / crit);
						printf("Robbin HP = %d", Robbin.hp);
					}
					printf("Hunter shot number = %d \n", shotnum);
					printf("---------------------------------------------------------------\n");
					break;
				default:
					printf("Something is wrong.\n");
					break;
				}
			}

			if (ducks[i].hp <= 0)
			{
				ducks[i].alive = false;
				i++;
				dkill++;
				dklive -= dkill;
				if ((dkill > (numd/2 + 3)) && (shotnum<=10) )
				{
					printf("Hunter won!!! %d / %d \n", dkill, numd);
					return 0;
				}
				else if((shotnum>25)&& (dklive>=numd/2))
				{
					printf("Ducks won!!! %d alive ducks\n", dklive);

				}
				break;

			}
			if (Robbin.hp <= 0)
			{
				Robbin.alive = false;
				printf("Ducks won!!! %d alive ducks\n", dklive);
				return 0;
			}
			else if (ducks[i].here == false)	//if duck flew away priviously, hunter starts shooting next
			{
				i++;
				break;
			}
		}
	
		i++; //next duck
	}
}

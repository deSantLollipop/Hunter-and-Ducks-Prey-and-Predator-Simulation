#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>//without this my visual studio don't want to recognise normaly 'bool'

//There is lake, where are ducks and huter, simulation of hunting game.
//{
//	int a;
//};

struct Hunter 
{
	int hp;
	int damage;
};

struct Duck {
	bool flyable;
	int hp;
	int getdamage;	
	/*struct Duck *next;*/
}/**first*/;

	struct Duck MallardDuck = {true,100,0}; 
	struct Duck RedHatDuck  = {true,120,0};
	struct Duck RubberDuck  = {false, 200, 20};


void DuckList()
{

	int i, typd;
	int numd = rand() %50;

	struct Duck ducks[50];


	for(i=0; i<numd; i++)
	{
	//	ducks[i] = {};
	}

	//struct Duck *tmpf=first;
    //for(i=1; i<list_size; i++){
	//struct Duck *temp=(struct Duck *)malloc(sizeof(struct Duck));
	//temp->n=liczba;
	//tmpf->next=temp;
    //temp->next=NULL;
    //tmpf=temp;}

}

int main()
{
	srand(time(NULL));
	//struct Duck mas[] or some list


system("pause");
return 0;
}





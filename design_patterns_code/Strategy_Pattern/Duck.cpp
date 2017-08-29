#include "Duck.h"
#include <iostream>
using namespace std;

void Duck::performFly()
{
	flyBehavior->fly();
}

void Duck::performQuack()
{
	quackBehavior->quack();
}

void FlyWithWings::fly()
{
	cout<<"I am flying"<<endl;
}

void FlyNoWay::fly()
{
	cout<<"I can not fly"<<endl;
}

void Quack::quack()
{
	cout<<"quack"<<endl;
}

void MuteQuack::quack()
{
	cout<<"silence"<<endl;
}

void Squeak::quack()
{
	cout<<"squeak"<<endl;
}

MallardDuck::MallardDuck()
{
	flyBehavior = new FlyWithWings();
	quackBehavior = new Quack();
}

MallardDuck::~MallardDuck()
{
	if(flyBehavior != NULL)
	{
		delete flyBehavior;
		flyBehavior = NULL;
	}
	if(quackBehavior != NULL)
	{
		delete quackBehavior;
		quackBehavior = NULL;
	}
}

void MallardDuck::display()
{
	cout<<"I am a Mallard Duck"<<endl;
}


int main()
{
	Duck *mallard = new MallardDuck();
	mallard->performFly();
	mallard->performQuack();
	mallard->display();
}
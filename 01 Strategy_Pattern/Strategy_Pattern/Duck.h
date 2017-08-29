#pragma once

//������Ϊ
class FlyBehavior
{
public:
	virtual void fly() = 0;
};

class FlyWithWings :public FlyBehavior
{
public:
	virtual void fly();
};

class FlyNoWay : public FlyBehavior
{
public:
	virtual void fly();
};

//������Ϊ
class QuackBehavior
{
public:
	virtual void quack() = 0;
};

class Quack : public QuackBehavior
{
public:
	virtual void quack();
};

class MuteQuack : public QuackBehavior
{
public:
	virtual void quack();
};

class Squeak : public QuackBehavior
{
public:
	virtual void quack();
};

//Ѽ�ӻ���
class Duck
{
public:
	virtual void performFly();
	virtual void performQuack();
	virtual void display() = 0;
	FlyBehavior* flyBehavior;
	QuackBehavior* quackBehavior;
};

class MallardDuck : public Duck
{
public:
	MallardDuck();
	~MallardDuck();
	void display();
};
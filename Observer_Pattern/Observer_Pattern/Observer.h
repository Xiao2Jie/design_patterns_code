#include <vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
class Observer;
class DisplayElement;
class Subject;
class CurrentHumidityDisplay;
class CurrentPressureDisplay;
class CurrentTempDisplay;

//三个虚基类
class Observer
{
public:
	virtual void update(float temp, float humidity, float pressure) = 0;
};

class  DisplayElement
{
public:
	virtual void display() = 0;
};

class Subject
{
public:
	virtual void registerObserver(Observer *obj) = 0;
	virtual void removeObserver(Observer *obj) = 0;
	virtual void notifyObserver() = 0;

};

//主题的继承类
class WeatherData : public Subject
{
public:
	virtual void registerObserver(Observer *obj);
	virtual void removeObserver(Observer *obj);
	virtual void notifyObserver();
	void setMeasurements(float temperature, float humidity, float pressure);
private:
	vector<Observer*> m_observers;
	float m_temperature;
	float m_humidity;
	float m_pressure;
};

//观察者的继承类
class CurrentTempDisplay : public Observer, public DisplayElement
{
public:
	CurrentTempDisplay(Subject *sub);
	virtual void update(float temp, float humidity, float pressure);
	virtual void display();

private:
	float m_temperature;
	Subject *m_sub;
};

class CurrentHumidityDisplay : public Observer, public DisplayElement
{
public:
	CurrentHumidityDisplay(Subject *sub);
	virtual void update(float temp, float humidity, float pressure);
	virtual void display();

private:
	float m_humidity;
	Subject *m_sub;
};

class CurrentPressureDisplay : public Observer, public DisplayElement
{
public:
	CurrentPressureDisplay(Subject *sub);
	virtual void update(float temp, float humidity, float pressure);
	virtual void display();

private:
	float m_pressure;
	Subject *m_sub;
};
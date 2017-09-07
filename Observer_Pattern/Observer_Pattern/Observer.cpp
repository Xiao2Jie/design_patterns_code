#include "Observer.h"
#include<iostream>
using namespace std;


void WeatherData::registerObserver(Observer *obj)
{
	m_observers.push_back(obj);
}

void WeatherData::removeObserver(Observer *obj)
{
	for(int i = 0; i< m_observers.size(); ++i)
	{
		if(m_observers[i] == obj)
		{
			m_observers.erase(m_observers.begin()+i);
		}
	}
}

void WeatherData::notifyObserver()
{
	for(int i = 0; i< m_observers.size(); ++i)
	{
		m_observers[i]->update(m_temperature, m_humidity, m_pressure);
	}
}

void WeatherData::setMeasurements(float temperature, float humidity, float pressure)
{
	m_temperature = temperature;
	m_humidity = humidity;
	m_pressure = pressure;
	notifyObserver();
}

CurrentTempDisplay::CurrentTempDisplay(Subject *sub)
{
	m_sub = sub;
	m_sub->registerObserver(this);
}

void CurrentTempDisplay::update(float temp, float humidity, float pressure)
{
	m_temperature = temp;
	display();
}

void CurrentTempDisplay::display()
{
	cout<<"Current Temperature is : "<< m_temperature<<endl;
}

CurrentHumidityDisplay::CurrentHumidityDisplay(Subject *sub)
{
	m_sub = sub;
	m_sub->registerObserver(this);
}

void CurrentHumidityDisplay::update(float temp, float humidity, float pressure)
{
	m_humidity = humidity;
	display();
}

void CurrentHumidityDisplay::display()
{
	cout<<"Current Humidity is : "<< m_humidity<<endl;
}

CurrentPressureDisplay::CurrentPressureDisplay(Subject *sub)
{
	m_sub = sub;
	m_sub->registerObserver(this);
}

void CurrentPressureDisplay::update(float temp, float humidity, float pressure)
{
	m_pressure = pressure;
	display();
}

void CurrentPressureDisplay::display()
{
	cout<<"Current Pressure is : "<< m_pressure<<endl;
}


int main()
{
	WeatherData *weatherData = new WeatherData();
	CurrentTempDisplay* curTemp = new CurrentTempDisplay(weatherData);
	CurrentHumidityDisplay * curHumidity = new CurrentHumidityDisplay(weatherData);
	CurrentPressureDisplay* curPressure = new CurrentPressureDisplay(weatherData);

	weatherData->setMeasurements(20, 30, 40);

}
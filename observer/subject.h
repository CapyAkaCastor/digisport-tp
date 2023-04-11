
#pragma once
#include <string>
class Observer;

class Subject {
public: 
	virtual std::string getValue() = 0;
	virtual void setValue(std::string value) = 0;
	virtual bool isRegistered(Observer* o)=0;
	virtual void registerObserver(Observer* o)=0;
	virtual void unregisterObserver(Observer* o)=0;
	virtual void notify()=0;
	virtual ~Subject() {};
};



#pragma once
#include <string>
#include <vector>
#include "subject.h"
#include "observer.h"
//class Observer;

class SubjectImpl : public Subject
{
public:
	SubjectImpl() {};
	virtual std::string getValue();
	virtual void setValue(std::string value);
	virtual bool isRegistered(Observer* o);
	virtual void registerObserver(Observer* o);
	virtual void unregisterObserver(Observer* o);
	virtual void notify();

	virtual ~SubjectImpl() {};

private : 
	std::string tweet_;
	std::vector<Observer*> list_abonnes_;
};
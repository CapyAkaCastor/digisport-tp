#pragma once
#include <string>
#include "observer.h"
//#include <vector>

//class Subject;
#include "subject.h"

class ObserverImpl : public Observer
{
public:
	ObserverImpl(Subject* s);
	virtual void update(Subject* s);
	virtual ~ObserverImpl();
	std::string value_;

private:
	Subject* subject_; //? 
};
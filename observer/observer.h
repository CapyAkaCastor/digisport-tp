#pragma once
#include <string>

class Subject;

class Observer {
public : 
	virtual void update(Subject* s) =0;
	virtual ~Observer() {};
};


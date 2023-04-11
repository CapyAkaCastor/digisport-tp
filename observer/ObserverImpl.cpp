#include "ObserverImpl.h"
#include <iostream>


ObserverImpl::ObserverImpl(Subject* s) 
	: subject_(s),value_(s->getValue())
{
	s->registerObserver(this);
}

ObserverImpl::~ObserverImpl()
{
	subject_->unregisterObserver(this);
}

void ObserverImpl::update(Subject* s)
{
	std::cout << "ObserverImpl: " << s->getValue() << std::endl;
	this->value_ = s->getValue();

}

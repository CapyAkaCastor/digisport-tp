#include "SubjectImpl.h"
#include <iostream>

std::string SubjectImpl::getValue() {
    return this->tweet_; // renvoi le dernier tweet en date
}

void SubjectImpl::setValue(std::string value) {
    this->tweet_ = value; //Tweet quelque chose
    notify(); // met � jour tous les abonn�s
}

bool SubjectImpl::isRegistered(Observer* o) {
    auto it = std::find(this->list_abonnes_.begin(), this->list_abonnes_.end(), o); // v�rifie qu'un twittos est bien abonn�
    return it != this->list_abonnes_.end();
}

void SubjectImpl::registerObserver(Observer* o) {
    if (!isRegistered(o)) {  // �vite de s'abonner si d�j� abonn�
        this->list_abonnes_.push_back(o); // rajoute un abonn� � la liste abonn�
    }
}

void SubjectImpl::unregisterObserver(Observer* o) {
    auto it = std::find(this->list_abonnes_.begin(), this->list_abonnes_.end(), o); //trouve l'abonn� dans la liste d'abonn�
    if (it != this->list_abonnes_.end()) {
        this->list_abonnes_.erase(it); // efface la personne de la liste d'abonn�s 
    }
}

void SubjectImpl::notify() {
    for (auto observer : this->list_abonnes_) { //itt�re parmis toute la liste d'abonn�s
        observer->update(this);  //met � jour l'abonn�
    }
}
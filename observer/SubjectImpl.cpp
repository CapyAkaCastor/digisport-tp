#include "SubjectImpl.h"
#include <iostream>

std::string SubjectImpl::getValue() {
    return this->tweet_; // renvoi le dernier tweet en date
}

void SubjectImpl::setValue(std::string value) {
    this->tweet_ = value; //Tweet quelque chose
    notify(); // met à jour tous les abonnés
}

bool SubjectImpl::isRegistered(Observer* o) {
    auto it = std::find(this->list_abonnes_.begin(), this->list_abonnes_.end(), o); // vérifie qu'un twittos est bien abonné
    return it != this->list_abonnes_.end();
}

void SubjectImpl::registerObserver(Observer* o) {
    if (!isRegistered(o)) {  // évite de s'abonner si déjà abonné
        this->list_abonnes_.push_back(o); // rajoute un abonné à la liste abonné
    }
}

void SubjectImpl::unregisterObserver(Observer* o) {
    auto it = std::find(this->list_abonnes_.begin(), this->list_abonnes_.end(), o); //trouve l'abonné dans la liste d'abonné
    if (it != this->list_abonnes_.end()) {
        this->list_abonnes_.erase(it); // efface la personne de la liste d'abonnés 
    }
}

void SubjectImpl::notify() {
    for (auto observer : this->list_abonnes_) { //ittère parmis toute la liste d'abonnés
        observer->update(this);  //met à jour l'abonné
    }
}
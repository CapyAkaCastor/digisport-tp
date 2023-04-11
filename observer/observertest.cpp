//
// Created by Noël Plouzeau on 20/03/2023.
//
#include <iostream>

#include "gtest/gtest.h"
#include "ObserverImpl.h"
#include "SubjectImpl.h"

//test si un observer recoit bien le tweet une fois émit 
  TEST(ObserverTest, ObserverUpdateTest) {
	  // Créer un twittos observé et un abonné
	  SubjectImpl subject;
	  ObserverImpl observer(&subject);
	  // tweet et notifie la liste des abonnés
	  subject.setValue("tweet num 1");
	  // Vérifier que la méthode update() a correctement mis à jour l'état de l'observateur
	  EXPECT_EQ(observer.value_, "tweet num 1");
  }

  //test getvalue 
  TEST(ObserverTest, getvalue) {
	  // Créer un twittos 
	  SubjectImpl subject;
	  // tweet 
	  subject.setValue("tweet num 1");
	  // Vérifier que la méthode update() a correctement mis à jour l'état de l'observateur
	  EXPECT_EQ(subject.getValue(), "tweet num 1");
  }

  //test si plusieurs abonnés recoivent bien le tweet une fois émit 
  TEST(ObserverTest, MultipleObserverUpdateTest) {
	  // Créer un twittos observé et un abonné
	  SubjectImpl subject;
	  ObserverImpl observer1(&subject);
	  ObserverImpl observer2(&subject);
	  ObserverImpl observer3(&subject);
	  // tweet et notifie la liste des abonnés
	  subject.setValue("tweet num 2");
	  // Vérifier que la méthode update() a correctement mis à jour l'état de l'observateur
	  EXPECT_EQ(observer1.value_, "tweet num 2");
	  EXPECT_EQ(observer2.value_, "tweet num 2");
	  EXPECT_EQ(observer3.value_, "tweet num 2");
  }

  //test si un observer recoit bien le deuxième tweet une fois émit 
  TEST(ObserverTest, ObserverDoubleUpdateTest) {
	  // Créer un twittos observé et un abonné
	  SubjectImpl subject;
	  ObserverImpl observer(&subject);
	  // tweet et notifie la liste des abonnés
	  subject.setValue("tweet num 1");
	  // Vérifier que la méthode update() a correctement mis à jour l'état de l'observateur
	  EXPECT_EQ(observer.value_, "tweet num 1");

	  subject.setValue("tweet num 2");
	  EXPECT_EQ(observer.value_, "tweet num 2");
  }

// test si un observer est bien abonné à un sujet
TEST(ObserverTest, IsRegisteredVrai) {
	SubjectImpl subject;
	ObserverImpl observer(&subject);
	EXPECT_TRUE(subject.isRegistered(&observer));
}

// test si plusieurs observers sont bien abonnés à un sujet
TEST(ObserverTest, MultipleIsRegisteredVrai) {
	SubjectImpl subject;
	ObserverImpl observer1(&subject);
	ObserverImpl observer2(&subject);
	EXPECT_TRUE(subject.isRegistered(&observer1));
	EXPECT_TRUE(subject.isRegistered(&observer2));
}

//test si un observer n'est pas abonné à un sujet quelconque 
TEST(ObserverTest, IsRegisteredFaux) {
	SubjectImpl subject;
	SubjectImpl subject2;
	ObserverImpl observer(&subject);
	EXPECT_FALSE(subject2.isRegistered(&observer));
}

//test si un observer est bien désabonné 
TEST(ObserverTest, Unregister) {
	SubjectImpl subject;
	ObserverImpl observer(&subject);

	subject.unregisterObserver(&observer);
	EXPECT_FALSE(subject.isRegistered(&observer));
}


//test registerObserver  
TEST(ObserverTest, Register) {
	SubjectImpl subject1;
	SubjectImpl subject2;
	ObserverImpl observer(&subject1);
	subject2.registerObserver(&observer);
	EXPECT_TRUE(subject2.isRegistered(&observer));
}

//test si un observer peut recevoir des tweets de plusieurs sujets
TEST(ObserverTest, MultipleSubject) {
	SubjectImpl subject1;
	SubjectImpl subject2;
	ObserverImpl observer(&subject1);
	subject2.registerObserver(&observer);
	subject1.setValue("tweet num 1");
	EXPECT_EQ(observer.value_, "tweet num 1");
	subject2.setValue("tweet num 2");
	EXPECT_EQ(observer.value_, "tweet num 2");
}

//test si un observer peut recevoir un tweet, se désabonner et ne pas recevoir un tweet, puis se réabonner et recevoir un tweet
TEST(ObserverTest, RegisterUnregisterRegister) {
	SubjectImpl subject1;
	ObserverImpl observer(&subject1);
	subject1.setValue("tweet num 1");
	EXPECT_EQ(observer.value_, "tweet num 1");
	subject1.unregisterObserver(&observer);

	subject1.setValue("tweet num 2");
	EXPECT_EQ(observer.value_, "tweet num 1");

	subject1.registerObserver(&observer);
	subject1.setValue("tweet num 3");
	EXPECT_EQ(observer.value_, "tweet num 3");
}

//test si plusieurs observers peuvent recevoir des tweets de plusieurs sujets
TEST(ObserverTest, MultipleSubjectMutlipleTweetMultipleObserver) {
	SubjectImpl subject1;
	SubjectImpl subject2;
	ObserverImpl observer1(&subject1);
	ObserverImpl observer2(&subject1);
	subject2.registerObserver(&observer1);
	subject2.registerObserver(&observer2);

	subject1.setValue("tweet num 1");
	EXPECT_EQ(observer1.value_, "tweet num 1");
	EXPECT_EQ(observer1.value_, "tweet num 1");
	subject2.setValue("tweet num 2");
	EXPECT_EQ(observer2.value_, "tweet num 2");
	EXPECT_EQ(observer2.value_, "tweet num 2");

}
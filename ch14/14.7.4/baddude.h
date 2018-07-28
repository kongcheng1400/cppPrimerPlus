#ifndef BADDUDE_H_
#define BADDUDE_H_

#include <string>
#include <iostream>

using namespace std;

class Card
{
	public:
		enum color {spade, heart, club, diamond};
	private:
		unsigned value;
		color color_m;

	public:
		Card(color cl = spade, int val = 10) {color_m = cl, value = val;};
		Card(const Card & c) : value(c.value), color_m(c.color_m) {};
		Card & operator=(const Card & c);
		friend ostream & operator<<(ostream & os, const Card & c);	

		virtual ~Card() {};
};


class Person
{
	private:
		string firstName;
		string lastName;
	protected:
		void displayPerson() const
		{
			cout << "Name is  " << firstName << " " << lastName << endl;
		}


	public:
		Person(const string & fn = "Person", const string & ln="noboday") {firstName = fn; lastName = ln;}
		Person(const Person & p) : firstName(p.firstName), lastName(p.lastName) {};
		Person & operator=(const Person & p) ;
		void virtual show() const  { cout << "\n A person is here: \n"; displayPerson();}
		virtual ~Person() {};
};


class GunSlinger : public virtual Person
{
	private:
		double time;
		int kills;

	protected:
		void displayGunSlinger() const 
		{
			cout << "His gunskills:  draw time: " << time <<  " , " << "kills: " << kills << endl;
		}

	public:
		GunSlinger(const string & fn =  "GunMan", const string & ln = "noboday", double t = 3.23, int k = 5)
			: Person(fn, ln), time(t), kills(k) {}
		GunSlinger(const Person & p, double t, int k) : Person(p), time(t), kills(k) {};
		GunSlinger(const GunSlinger & gs) : Person(gs), time(gs.time), kills(gs.kills) {};	
		GunSlinger & operator=(const GunSlinger & gs);
		
		virtual void show() const {cout << "\nA Gun slinger is here: \n"; displayPerson(); displayGunSlinger();}
		virtual double draw() const { return time;};
		virtual ~GunSlinger() {};

};

class PokerPlayer : virtual public Person
{
	private:
		Card myCard;

	protected:
		void displayPokerPlayer() const {cout << "his card: " << myCard << endl;};

	public:
		PokerPlayer(const string & fn = "PokerPlayer", const string & ln = "nobody", Card::color cl = Card::heart, unsigned val = 10)
			: Person(fn, ln), myCard(cl, val) {};
		PokerPlayer(const Person & p, Card::color cl = Card::heart, unsigned val = 10) 
			: Person(p), myCard(cl, val) {};
		PokerPlayer(const PokerPlayer & pp) : Person(pp), myCard(pp.myCard) {};	
		virtual ~PokerPlayer() {};

		PokerPlayer & operator=(const PokerPlayer & pp);
		virtual void show() const {cout << "\nA pokerplayer is here: \n"; displayPerson(); displayPokerPlayer();}
		virtual const Card &  draw() const {return myCard;}





};	




class BadDude : public GunSlinger, public PokerPlayer
{
	private:
	protected:

	public:
		BadDude(const string & fn = "GunPokerMan", const string & ln = "noboday", double t = 4.33, int k = 34, Card::color cl = Card::spade, unsigned val = 14)
			: Person(fn, ln), GunSlinger(fn, ln, t, k), PokerPlayer(fn, ln, cl, val) {};
		BadDude(const Person & p, double t = 4.33, int k = 34, Card::color cl = Card::spade, unsigned val = 14)
			: Person(p), GunSlinger(p, t, k), PokerPlayer(p, cl, val) {};
		BadDude(const BadDude & bd)
			: Person(bd), GunSlinger(bd), PokerPlayer(bd) {}

		virtual ~BadDude() {};
		BadDude & operator=(const BadDude & bd);
		virtual void show() const { cout << "\nA badbude can shot and poker: \n"; displayPerson();  displayPokerPlayer(); displayGunSlinger();};
		
		double gDraw() const {return GunSlinger::draw();}
		const Card & cDraw() const {return PokerPlayer::draw();}
};


#endif

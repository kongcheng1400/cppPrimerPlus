#ifndef WORKER0_H_
#define WORKER0_H_

#include <string>

class Worker //abstract class
{
	private:
		std::string fullName_m;
		long id_m;

	protected:
		virtual void data() const;
		virtual void get();

	public:
		Worker() : fullName_m("Nobody"), id_m(0L) {}
		Worker(const std::string & s, long n)
			: fullName_m(s), id_m(n) {}

		virtual ~Worker() = 0;
		virtual void set() = 0;
		virtual void show() const = 0;

};

class Waiter : virtual public Worker
{
	private:
		int panache_m;

	protected:
		void data() const;
		void get();
	public:
		Waiter() : Worker(), panache_m(0) {}
		Waiter(const std::string & s, long n, int p = 0)
			: Worker(s, n), panache_m(p) {}

		Waiter(const Worker & wk, int p = 0)
			: Worker(wk), panache_m(p) {}

		virtual void set();
		virtual void show() const;
		virtual ~Waiter() {};
};

class Singer : virtual public Worker
{
	protected:
		enum {other, alto, contralto, soprano, bass, baritone, tenor};
		enum {Vtypes= 7};
		void data() const;
		void get();

	private:
		static const char *pv[Vtypes]; 
		int voice_m;

	public:
		Singer() : Worker(), voice_m(other) {}
		Singer(const std::string & s, long n, int v = other)
			: Worker(s, n), voice_m(v) {}
		Singer(const Worker & wk, int v = other)
			: Worker(wk), voice_m(v) {}
		virtual void set();
		virtual void show() const;
		virtual ~Singer() {};



};

class SingingWaiter : public Singer, public Waiter
{
	protected:
		void data() const;
		void get();

	public:
		SingingWaiter() {};
		SingingWaiter(const std::string & s, long n, int p = 0, int v = other)
			: Worker(s, n), Waiter(s, n, p), Singer(s, n, v) {} //need worker to initialize virtual base class data
		SingingWaiter(const Worker & wk, int p = 0, int v = other)
			: Worker(wk), Waiter(wk, p), Singer(wk, v) {}
		SingingWaiter(const Waiter & wt, int v = other)
			: Worker(wt), Waiter(wt), Singer(wt, v) {}
		SingingWaiter(const Singer & sg, int p = 0)
			: Worker(sg), Waiter(sg, p), Singer(sg) {}
		virtual void set();
		virtual void show() const;
		virtual ~SingingWaiter() {};
















};









#endif

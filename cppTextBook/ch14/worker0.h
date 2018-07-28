#ifndef WORKER0_H_
#define WORKER0_H_

#include <string>

class Worker //abstract class
{
	private:
		std::string fullName_m;
		long id_m;

	public:
		Worker() : fullName_m("Nobody"), id_m(0L) {}
		Worker(const std::string & s, long n)
			: fullName_m(s), id_m(n) {}

		virtual ~Worker() = 0;
		virtual void set();
		virtual void show() const;

};

class Waiter : public Worker
{
	private:
		int panache_m;
	public:
		Waiter() : Worker(), panache_m(0) {}
		Waiter(const std::string & s, long n, int p = 0)
			: Worker(s, n), panache_m(p) {}

		Waiter(const Worker & wk, int p = 0)
			: Worker(wk), panache_m(p) {}

		void set();
		void show() const;
		virtual ~Waiter() {};
};

class Singer : public Worker
{
	protected:
		enum {other, alto, contralto, soprano, bass, baritone, tenor};
		enum {Vtypes= 7};

	private:
		static const char *pv[Vtypes]; 
		int voice_m;

	public:
		Singer() : Worker(), voice_m(other) {}
		Singer(const std::string & s, long n, int v = other)
			: Worker(s, n), voice_m(v) {}
		Singer(const Worker & wk, int v = other)
			: Worker(wk), voice_m(v) {}
		void set();
		void show() const;
		virtual ~Singer() {};



};


#endif

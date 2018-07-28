#ifndef TV_H_
#define TV_H_

class TV
{
public:
	friend class Remote;
	enum {Off, On};
	enum {MinVal, MaxVal = 20};
	enum {Antenna, Cable};
	enum {TVV, DVD};

	TV(int s = Off, int mc = 125) : state_m(s), volume_m(5),
		maxChannel_m(mc), channel_m(2), mode_m(Cable), input_m(TVV) {}

	void onOff() { state_m = (state_m == On)? Off : On;}
	bool isOn() const { return state_m == On;}
	bool volUp();
	bool volDown();
	void chanUp();
	void chanDown();
	void setMode() { mode_m = (mode_m == Antenna) ? Cable : Antenna;}
	void setInput() { input_m = (input_m == TVV) ? DVD : TVV;}
	void settings() const;

private:
	int state_m;
	int volume_m;
	int maxChannel_m;
	int channel_m;
	int mode_m;
	int input_m;	





};


class Remote
{
	private:
		int mode_m;
	public:
		Remote(int m = TV::TVV) : mode_m(m) {};
		bool volUp(TV & t) { return t.volUp();}
		bool volDown(TV & t) {return t.volDown();}
		void onOff(TV & t) {t.onOff();}
		void chanUp(TV & t) { t.chanUp();}
		void chanDown(TV & t) { t.chanDown();}
		void setChan(TV & t, int c) {t.channel_m = c;}
		void setMode(TV & t) { t.setMode();}
		void setInput(TV &t) { t.setInput();}


};




#endif

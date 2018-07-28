#ifndef TV_H_
#define TV_H_
class TV;
class Remote
{
	public:
	enum {TVV, DVD};
	private:
		int mode_m;
	public:
		Remote(int m = TVV) : mode_m(m) {};
		bool volUp(TV & t);
		bool volDown(TV & t);
		void onOff(TV & t);
		void chanUp(TV & t);
		void chanDown(TV & t);
		void setChan(TV & t, int c);
		void setMode(TV & t);
		void setInput(TV &t);


};


class TV
{
public:
	friend void Remote::setChan(TV & t, int c);
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

inline bool Remote::volUp(TV & t) { return t.volUp();};
inline bool Remote::volDown(TV & t) { return t.volDown();}
inline void Remote::onOff(TV & t) { t.onOff();}
inline void Remote::chanDown(TV & t) { t.chanDown();}
inline void Remote::chanUp(TV & t) { t.chanUp();}
inline void Remote::setMode(TV & t) { t.setMode();}
inline void Remote::setInput(TV & t) { t.setInput();}
inline void Remote::setChan(TV & t, int c) { t.channel_m = c;}







#endif

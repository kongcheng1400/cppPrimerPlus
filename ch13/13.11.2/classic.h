class CD{
	private:
		char * performers_m;
		char * label_m;
		int selections_m;
		double playtime_m;

	public:
		CD(const char * s1, const char * s2, int n, double x);
		CD(const CD & d);
		CD();
		virtual ~CD();
		virtual void report() const;
		CD & operator=(const CD & d);

};



class Classic :public CD
{
	private:
		char * keywords_m;
	
	public:
		Classic(const char * kw,const char * s1, const char * s2, int n, double x);
		Classic(const Classic & cl);
		Classic();
		virtual ~Classic();	

		virtual void report() const;
		Classic & operator=(const Classic & cl);

};

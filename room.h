#include "./event.h"
#include "./info.h"

class room{
	private:
		event *e;
		bool rope;
		bool been;
	public:
		room();
		void setRope(bool);
		event * getE();
		void setE(event *&);
		void eMessage(info);
		bool ifNULL();
		char getEType();
		bool getRope();
		void eAction(info &);
		void setBeen(bool);
		void setNULL();
};

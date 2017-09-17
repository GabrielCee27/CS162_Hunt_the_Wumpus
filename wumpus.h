#include "./event.h"

class wumpus : public event{
	private:
		int posR;
		int posC;
	public:
		wumpus();
		void message();
		void action(info &);
};

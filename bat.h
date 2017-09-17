#include "./event.h"

class bat : public event {
	public:
		void message();
		bat();
		void action(info &g);
};

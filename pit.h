#include "./event.h"

class pit : public event {

	public:
		pit();
		void message();
		void action(info &g);
};

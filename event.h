#pragma once
#include <iostream>
#include "./info.h"
#include <time.h>
#include <stdlib.h>
class event{
	protected:
		char type;
	public:
		virtual void message()=0;
		char getType();
		void setType(char t);
		virtual void action(info &)=0;
};

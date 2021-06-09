#ifndef VALIDTIMER_H_
#define VALIDTIMER_H_

#include <conio.h>
#include <time.h>	// class needs this inclusion

using namespace std;

class ValidTimer {
    private:
		bool running;
		unsigned long  beg, end;

	public:
		
    ValidTimer() {
	    running = false;
	    beg = 0;
	    end = 0;
    }


    void start() {
	    if(!running) {
		    beg -= end - (unsigned long) clock();
		    running = true;
	    }
    }

    void stop() {
	    if(running) {
		    end = (unsigned long) clock();
		    running = false;
	    }
    }

    unsigned long getTime() {
	    if(running)
		    return ((unsigned long) clock() - beg); //return the number of milliseconds
	    else
		    return end - beg;
    }

};

#endif

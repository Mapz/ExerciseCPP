#include "person.h"
using namespace std;

void person::attack(){
	cout << "attack by default" << endl;
}


void kicker::attack(){
	cout << "kick" << endl;
}

person_handle& person_handle::operator=(const person_handle &ph){
	++*ph.use;
	dec_use();	//因为是原句柄指向到了新的对象，所以原句柄的引用要减一
	p = ph.p;
	use = ph.use;
	return *this;
}
#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;
class person
{
public:
	person():
		name("Default Name"),
		address("Unknown Location"){};
	person(string n,string a):
		name(n),
		address(a){};
	virtual person* clone() const{
		return new person(*this);
	};
	string name,address;
	virtual void attack();
	string getName(void) const {return name;}
	string getAdd(void) const {return address;}
};


class kicker : public person {
public:
	kicker():
		person(){};
	kicker(string n,string a):
		person(n,a){};
	void attack();
	kicker* clone() const{
		return new kicker(*this);
	};
};

class person_handle {
public:
	person_handle():
		p(0),
		use(new size_t(1)){};
	person_handle(const person &per):
		p(per.clone()),
		use(new size_t(1)){};
	person_handle(const person_handle &ph):
		p(ph.p),
		use(ph.use){*use++;};
	~person_handle(){dec_use();};
	
	person_handle& operator=(const person_handle&);

	person *operator->() const{
		if(p) return p;
		else throw logic_error("unbound person");
	}
	person &operator*() const{
		if(p) return *p;
		else throw logic_error("unbound person");
	}
private:
	person *p;
	size_t *use;
	//减少引用判断引用是否为零,为零的时候销毁指针空间
	void dec_use(){
		cout << "use:" << *use - 1 << endl;
		if(--*use==0){
			cout << "deleted" << endl;
			delete p;
			delete use;
		}
	}
};

#include <string>
#include <iostream>
#include "MapzUtil.h"
#include <vector>
using namespace std;

long MapzUtil::ver = 100000001l;

MapzUtil::MapzUtil():name(string("default")){

};

MapzUtil::MapzUtil(string &nm){
	name = nm;
};

MapzUtil::MapzUtil(const MapzUtil &m){
	name = m.name;
};

MapzUtil::~MapzUtil(){
	
};

ostream& operator<<(ostream &os, const MapzUtil &MU){
	os << MU.name;
	return os;
};

MapzUtil operator+(MapzUtil &mu1,MapzUtil &mu2){
	string name_new = mu1.name + mu2.name;
	MapzUtil mu3 = MapzUtil(name_new);
	return mu3;
}
void MapzUtil::addStrToVec
(vector<string>::iterator &beg,vector<string>::iterator &end,strConvert func){
	while(beg!=end){
		*beg += func(*beg);
		beg++;
	}
}

string MapzUtil::eachPlusOne(string &str){
	string::iterator si = str.begin();
	while(si!=str.end()){
		*si++ += 1;
	}
	return str;
}
void MapzUtil::showVector(vector<int> &iv){
	 vector<int>::iterator i = iv.begin();
	  cout << "======beginning of vector======" <<endl;
	  while(i!=iv.end())
		  cout<<*i++<<endl;
	  cout << "=========end of vector=========" <<endl;
};
void MapzUtil::showVector(vector<string> &sv){
	  vector<string>::iterator i = sv.begin();
	  cout << "======beginning of vector======" <<endl;
	  while(i!=sv.end())
		  cout<<*i++<<endl;
	  cout << "=========end of vector=========" <<endl;
};
long MapzUtil::getVer(){
	return ver;
};
string MapzUtil::getName(){
	return name;
};
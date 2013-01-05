#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class MapzUtil{
	typedef string (*strConvert)(string &a);
	friend ostream& operator<<(ostream& , const MapzUtil&);
	friend MapzUtil operator+(MapzUtil& , MapzUtil&);
	public:
		MapzUtil();
		MapzUtil(string &nm);
		MapzUtil(const MapzUtil&);
		~MapzUtil();
		string getName();
		static string eachPlusOne(string&);
		static void addStrToVec(vector<string>::iterator&,vector<string>::iterator&,strConvert);
		static void showVector(vector<int>&);
		static void showVector(vector<string>&);
		static long getVer();
	private:
		static long ver;
		string name;
};

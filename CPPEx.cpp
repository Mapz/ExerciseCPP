//============================================================================
// Name        : CPPEx.cpp
// Author      : MapzChen
// Version     :
// Copyright   : Your copyright notice
// Description : Exercise C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <list>
#include <deque>
#include <sstream>
#include <string>
#include <vector>
#include <bitset>
#include <cstring>
#include <math.h>
#include <stdexcept>
#include <algorithm>
#include <utility>
#include <map>
#include <numeric>
#include <iterator>
#include "MapzUtil.h"
#include "person.h"
#include "define.h"

using namespace std;


typedef int (*compareInt)(int &a,int &b);
/*
函数是ff：
函数返回一个指向返回int型，接受两个double引用作为形参的函数的指针
函数的形参也是一个返回int型，接受两个double引用作为形参的函数的指针
PS：真是蛋痛
*/
typedef int (*ff(int *(double &a,double &b)))(double &c,double &d);
/*
函数是callBackFunc：
函数返回一个指向void，形参为指向void的指针的函数的指针
函数的形参也是一个返回void，形参为指向void的指针的的函数的指针
PS：更加蛋痛
*/
typedef void (*ff2(void *(void *ap)))(void *bp);
typedef int (*ff3(int &a));

int test(int &a,int &b){
		return a + b;
	}

void reset(int* ip){
	*ip=0;
	ip=0;
}

void arrayIn(int ar[2]){
	for(int i=0;i!=2;++i){
		cout << ar[i] << ",";
	}
}
//注意不能用这个重载上面的函数，因为有歧义
void arrayIn2(int (&ar)[2]){
	for(int i=0;i!=2;++i){
		cout << ar[i] << ";";
	}
}
double noReturn(){
	//return;  这是错误的，你可以没有return语句来返回一个默认的值，但是不能写return不反悔值或者不能隐式转换的值
	return 1;
}
//为了计算一个数的几次方才会达到某个值，要返回大于他的第一个值且要返回次数
long mi(long number,long toCal,int &times){
	long result = number;
	while(result < toCal ){
		result*=number;
		times++;
	}
	return result;
}
  int self100(int &a){
	return a*100;
 }


  bool CmpStrSz(string &s1,string &s2){
	  return s1.size() > s2.size();
  }
  
  bool GT4(string &s){
	  return s.size() > 4;
  }
  
  void funcAttack(person &p){
	  p.attack();
  }
  
  template <typename T>
  void c_out(T &v){
	  cout << v;
	  cout << endl;
  }

  template <typename T>
  void c_out_n(T v){
	  cout << v;
	  cout << endl;
  }
 int main() {
	/*---------------遍历器为向量赋值-------------------*/
//	vector<int> vecInt(10);
//	for (vector<int>::iterator i = vecInt.begin();i!=vecInt.end();i++){
//		*i = 50;
//		cout<< *i <<endl;
//	}
//	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	/*----------------bitset逐位取反-------------------*/
//	const int countX = 15;
//	const int startBit = 4;
//	bitset<countX> bits;
//	bits.set();
//	int last = startBit;
//	int now = last;
//	while((true)){
//		bits.flip(now);
//		cout<<bits<<endl;
//		last = now;
//		bits.flip(last);
//		now = (now<countX-1)?now +=1:0;
//	}
	/*--------------关于数组--------------------------*/
//	string ff[2] = {"Fast","Five"};
//	char cf[] = "c++";
	/*-------------把一个数组赋给另一个------------------*/
//	const int length = 10;
//	int array1[length];
//	int array2[length];
//	for(size_t s = 0;s != length;s++){
//		array1[s] = s;
//		cout<<array1[s];
//	}
//	cout << &array1 << endl;
//	for(size_t s = 0;s != length;s++){
//		array2[s] = array1[s];
//		cout<<array2[s];
//	}
//	cout << &array2 <<endl;
//
//	int *ar1 = array1;
//	cout << *(ar1+6)<<endl;
//
//	 /*----------用指针来复制数组:现在看起来和刚才那个赋值的方式复制数组差不多了----------------*/
//	cout << "-----x-----" << endl;
//	int array3[length];
//	int *ar3 = array3; //int *ar3 = &array3[0];  //当指针指向数组名字时，就是指向数组第一个元素
//	for(size_t s = 0;s != length; s++){
//		ar3[s] = ar1[s];//同 *(ar3+s) = *(ar1 + s);
//		cout << array3[s] << endl;
//	}
	/*------------引用与指针----------------*/
//	int a = 1,b = 2;
//	int &as = a , &bs = b;
//	string c = "3.0";
//	string &cs = c;
//	double d = 4.0;
//	double &ds = d;
//	//as = cs;  不正确，不是因为不同类的引用不能相互赋值，而是因为引用是初始化之后不能被赋值的，
//	//只能改变引用的对象，而string对象不能转型成int
//	as = bs;
//	as = ds; //double 被转型成了 int
//	cout << a << " "<< b << " "<< " "<< c << " " << d <<endl;
	/*------------------const限定符和指针的操作------------*/
//	string i = "c++";
//	const string *pi = &i;
//	//*pi = "cv";//出错，因为不允许通过自以为指向const变量的指针来修改变量
//	/*--------------C style 字符串------------*/
//	/*------ 比较Example1和Example2-------*/
//	/*--Example1-----*/
//	char csc[] = "abcd";
//	cout << *csc << endl; //C风格字符串的名字既是第一个字符的指针，和数组统一
//	cout << *(csc+1) << csc[1] << endl;
//	int step = 0;
//	while(*(csc+step)){
//		cout <<*(csc+step)<<endl;
//		step++;
//	//	csc ++;					和下面的比较一下，两种方式还是有区别的咯，虽然是名字是指针，
//	//	但实际上还是数组，不能做自增。(很好理解，因为自增了就不是指向这个数组了嘛)。
//
//	}
//	/*--Example2----*/
//	const char *csp = "abcd";    //我们还是这么定义C风格字符串吧
//	while(*csp){
//		cout << *csp << endl;
//		csp ++;   //可以自增，因为是指针,和数组木有直接关系
//	}
//	/*关于C风格字符串标准库*/
//	const char *cstr1 = "This is Tom";
//	const char *cstr2 = "This is Jerry";
//	int diff = strcmp(cstr1,cstr2);
//	cout << diff << endl;
//	/*C风格字符串需要有空字符结尾*/
//	char cstr3[] = {'N','o',' ','E','n','d'}; //没有结尾，让我们看看有什么后果
//	cout << strlen(cstr3) << endl; //结果不可预测，会继续在内存序列中找到空字符为止
//	char cstr4[] = "No End";
//	cout << strlen(cstr4) << endl;
//	/*Copy和add 字符串*/
//	char largeChar[3];
//	char char1[] = "Th";
//	char char2[] = "is";
//	strcpy(largeChar,char1);
//	strcat(largeChar,char2);
//	cout << largeChar << strlen(largeChar) <<endl;	//strlen已经和初始定义的大小无关了，
//	/*安全的copy和add，保证新的数组大小正确*/
//	char char1safe[] = "Th";
//	char char2safe[] = "is";
//	char largeCharSafe[strlen(char1safe) + strlen(char2safe) + 1/*加上一个\0字符的位置*/];
//	strcpy(largeCharSafe,char1safe);
//	strcat(largeCharSafe,char2safe);
//	cout << largeCharSafe << strlen(largeCharSafe) <<endl;
//	//所以算出正确的大小很重要
//	/*尽量使用标准库string*/
//	string str1 = largeCharSafe;
//	str1 += str1;
//	cout << str1 << endl;
//	/*动态数组*/
//	int *cp;
//	int *dp;
//	int len = 10;
//	{
//		int *ap = new int[len]();
//		int b[len];
//		int *bp = b;
//		cp = ap;
//		dp = bp;
//		for(size_t s = 0 ; s != len ;s++)
//		{
//			*(ap+s) = 10;
//			*(bp+s) = 10;
//		}
//		cout << "first:" << endl;
//		for(size_t s = 0 ; s != len ;s++)
//		{
//		cout << *(ap + s) << ":" <<*(bp + s) <<  ";";
//		}
//	}
//	cout << "end" << endl;
//	//cout << b << endl;   数组在声明的块之外不可用
//	//cout << *ap << endl; 数组在声明的块之外不可用
//	//cout << *bp << endl; 数组在声明的块之外不可用
//	cout << *cp << endl; //动态数组存储在自由存储中，依然可以访问到
//	cout << *dp << endl; //虽然用dp保持了bp的指针，但是由于在块的外部，所以没有保存下来，结果不可预料
//	delete [] cp;
//	cout << *cp << endl;
	/*-------多维数组，可以理解成指针的指针-----------*/
//	/*遍历一下多维数组*/
//	int ar[3][5] = {{0,1,2,3,4},{1,2,3,4,5},{2,3,4,5,6}};
//	int (*ap)[5] = ar;
//	ap = &ar[0];
//	for(int i = 0; i != 3; ++i){
//		cout <<"{" ;
//		for(int j = 0; j != 5; ++j){
//			//cout << **(ap + i+ j) << ":";//错误的解引用，得到的结果只有每行第一个正确（想想为什么）
//			cout << *(*(ap + i) + j) << ":";
//		}
//		cout << "}"<< endl;
//	}
//
//	/*使用typedef来简化上面的程序*/
//	typedef int int_array5[5];
//	int_array5 *ap2 = ar;
//	for(int_array5 *ip = ap2; ip != ap2 + 3; ++ip){
//		cout <<"{" ;
//		//for(int *jp = ip; jp != ip + 5 ; ++ jp) //错误的解引用
//		for(int *jp = *ip; jp != *ip + 5 ; ++ jp){//正确的解引用，须知ip是一个存放指针的指针，解引用一次才能得到
//												 //第二维的指针
//			cout << *jp << ":";
//		}
//		cout << "}"<< endl;
//	}
	/*------多维数组（完）----------*/

	/*------位运算----------*/
//	bitset<8> a(0x00000000);
//	a.set(2);
//	cout << a << endl;
//	/*习题4.22*/
//	const char *cp = "Hello";
//	int cnt = 0;
//	while(*cp){
//		cnt++;
//		cp++;
//	}
//	cout << cnt << ":"  << endl;
//	//确定结果是5
//	const char *cp1 = "Hello";
//	int cnt1 = 0;
//	while(cp1){
//		cnt1++;
//		cp1++;
//	}
//	cout << cnt << ":" << cnt1 << endl;
//	//死循环，因为cp1作为判断条件是指针，不会为0
	/*--------------测试-------------------*/
//	int a = 2;
//	double b = 3.4;
//	a = b;
//	cout << a << endl;
//	return 0;
	/******************解引用和自增操作符************/
//	vector<int> iv = vector<int>(10);
//	int i = 0;
//	for(vector<int>::iterator iter = iv.begin(); iter != iv.end();i++, iter++){
//		*iter = i;
//		}
//	for(vector<int>::iterator iter = iv.begin(); iter != iv.end();i++, iter++){
//			cout<< " " << *iter ;
//		}
//	cout << endl;
//	i = 0;
//	for(vector<int>::iterator iter = iv.begin(); iter != iv.end();i++){
//			*iter++ = i;
//		}
//	for(vector<int>::iterator iter = iv.begin(); iter != iv.end();i++, iter++){
//				cout<< " " << *iter ;
//		}
//	cout <<endl;
//	//最后可以简化成
//	i = 0;
//	vector<int>::iterator iter = iv.begin();
//	while(iter!=iv.end()){
//		*iter++ = i++;
//	}
//	for(vector<int>::iterator iter = iv.begin(); iter != iv.end();i++, iter++){
//					cout<< " " << *iter ;
//			}
//	cout<<endl;
	/*******************解引用和自增操作符，完**********************************/
///********************箭头操作符******************************************/
//	/*
//	 * 箭头操作符等于解引用操作符和点操作符的合体
//	 * (*p).foo和 p->foo等同
//	 * 注意解引用的优先级低于点操作符，所以*p.foo是错误的
//	 */
//	vector<int> vec = vector<int>(10);
//	vector<int> *vp = &vec;
//	for(vector<int>::iterator iter = vp->begin();iter!=vp->end();iter++){
//}
	/************************箭头操作符 完***********************************/
	/************************sizeof和引用***********************************/
	/*
	 * 引用的sizeof会返回引用占用的内存大小
	 */
//	int a = 10;
//	int &as = a;
//	cout << sizeof(as) << endl;
//	double b = 10.0;
//	double &bs = b;
//	cout << sizeof(bs) << endl;
	/************************sizeof和引用完***********************************/
	/************************关于右||操作数***********************************/
//	int i = 0,j=0;
//	while(i++<10||j++<10){
//	}
//	cout << "i:" << i << "j" << j <<endl;
//	/*
//	 * 当左操作符足够完成判断的时候，就不会运算右操作符
//	 * 所以上例的结果是 "i:21j:11"
//	 */
	/************************关于右||操作数完***********************************/
	/************************动态变量和指针***********************************/
	//int i = new int(10);
	//cout<< i << endl;    错误的写法，Cpp中new关键字返回指针
//	 int *ip = new int(10);
//	 cout<<*ip<<endl;	   //正确的写法
//	 delete *ip;			   //用完之后请销毁掉动态内存的占用，另外注意delete对于非new出来的指针无效（可以delete
//	 	 	 	 	 	  // 0 指针，但这毫无意义）
	/********************指针和动态变量完***********************************/
	/********************转型******************************************/
//	int a = 10;
//	double b = 10.6;
//	cout << a + b << endl;
//	cout << a + static_cast<int>(b) << endl;
//*******************转型完****************************************/
	/********************错误处理***************************************/
//	int a = 0;
//	try {
//		throw a;
//	} catch (int i) {
//		cout << i << endl;
//	}
//	try {
//		throw runtime_error("ccc");
//	} catch (runtime_error re) {
//		const char* err = re.what();
//		cout << (string) err << endl;
//	}
	/*********************错误处理完*************************************/
	/*********************CPP接受隐式转换的实参***************************/
//	double a = 3.4 , b = 4.3;
//	int c = test(a,b);
//	cout << c << endl;
	/******输出结果为7，a和b被隐式转换成int传入***************************/
	/********************指针实参*********************************/
//	int x = 100;
//	int* xp = &x;
//	cout << x << " <-- " << xp << endl;
//	reset(xp);
//	cout << x << " <-- " << xp << endl;
	/*********************指针实参*******************************/
	/*********************利用传引用来达到返回多个值********************************/
//	int times = 1;
//	long result = mi(30,1000,times);
//	cout << times << "------" << result << endl;
	/*********************利用传引用来达到返回多个值的目的******************************************/
	/*********************请最好不要传递数组类型的形参，因为编译器不会监测他的长度**********************/
	/*********************如果你需要传递数组作为形参，你最好传递数组的引用，这样长度就会绑定了************/
//	int a[3] = {1,2,3};
//	arrayIn(a);//传入了一个3个元素的数组，但是函数计划只能到第二个元素，可以运行，但是结果就不如预期
//	//arrayIn2(a);    编译不通过，无法传递三个元素的数组的引用
//	int b[2] ={1,2};
//	arrayIn2(b); //  正确！
	/*********************请最好不要传递数组类型的形参，因为编译器不会监测他的长度**********************/
	/*********************如果你需要传递数组作为形参，你最好传递数组的引用，这样长度就会绑定了************/
	/**
	 * 下面的语句会打印0；没有返回值的时候返回默认值，看编译器了 - -有的会不让编译
	 */

	//cout << noReturn() << endl;

	//compareInt cm = test;
	//int a=3,b=4;
	//cout <<cm(a,b) <<endl;

	/*int ival;
	while(cin>>ival,!cin.eof()){
		if(cin.bad()){
			throw runtime_error("Fatal error");
		}
		if(cin.fail()){
			cerr << "try again";
			cin.clear(istream::failbit);
			continue;
		}

	}*/
	//cin.tie(&cout);
	/*ifstream ifile;
	ofstream ofile;
	string fileName("iofile");
	ofile.open(fileName.c_str());
	if(!ofile){
		cerr << "open file failed:" << fileName << endl;
		return -1;
	}else{
	ofile << "xcx" << endl;
	ofile.close();
	}*/
	/******读出文件并且逐行显示*****/
	/*fstream inOut;
	string fn("CPPex.cpp");
	string content("");
	inOut.open(fn.c_str(),fstream::in);
	while(getline(inOut,content)){
		cout << content <<endl;
	}*/

	/****************用c风格字符串数组来初始化一个string向量************************/
	/*char *words[] = {"a","b","c","d"};
	int size1 = sizeof(words);
	int size2 = sizeof(char *);
	size_t wordSize = size1 /size2;
	vector<string> sv(words,words + wordSize);
	cout << size1 << " " << size2 <<" " <<endl;
	vector<string>::iterator i = sv.begin();
	while(i!= sv.end()){
		cout << *i++ << endl;
	}*/
	/****************用c风格字符串数组来初始化一个string向量完************************/
	/****************习题，逆序输出一个list<string>*******************************/
	/*list<string> sl(10);
	list<string>::iterator it = sl.begin();
	int i = 1;
	while(it!=sl.end()){
		*it = string(i++,'x');
		it++;
	}
	do{
		it--;
		cout << *it <<endl;
	}
	while(it!=sl.begin());*/
	/***或者如下***/
	/*list<string>::reverse_iterator rit = sl.rbegin();
	while(rit!=sl.rend()){
		cout <<*rit << endl;
		rit++;
	}*/
	/****************习题，逆序输出一个list<string>完*******************************/
	/*list<string> ls(10);
	list<string>::iterator iter = ls.begin();
	int i = 1;
	while(iter!=ls.end()){
		*iter++ = string(i++,'x');
	}
	do{
		cout << *--iter <<endl;
	}
	while(iter!=ls.begin());
	iter = find(ls.begin(),ls.end(),"xxxxx");
	cout << *iter <<endl;*/
	/*********************使用迭代器将string中的小写字母换成大写***************************************************/
	/*string toParse("");
	cin >> toParse;
	int csSizeDiff = char('A') - char('a');
	string::iterator strIter = toParse.begin();
	while(strIter!=toParse.end()){
	if(char('a') <= *strIter && *strIter <= char('z')){
		(*strIter) += csSizeDiff;
	}
	strIter++;
	}
	cout << toParse;*/
/*********************用迭代器删除大写字母**********************************/
//homework2
//string toParse2("");
//cin >>toParse2;
//string::iterator strIter2 = toParse2.begin();
//while(strIter2!=toParse2.end()){
//	if(*strIter2 >= char('A') && *strIter2 <= char('Z')){
//		toParse2.erase(strIter2);
//	}else{
//		strIter2++;
//	}
//}
//cout << toParse2;
/*********************用迭代器删除大写字母完**********************************/
/*********************用vector<char>初始化string******************************/
//vector<char> chrs(10);
//vector<char>::iterator i = chrs.begin();
//char chr('a');
//while(i!=chrs.end()){
//	*i++=chr++;
//}
//string str("");
//vector<char>::reverse_iterator ri = chrs.rbegin();
//while(ri!=chrs.rend()){
//	str.insert(str.begin(),*ri);
//	ri++;
//}
//cout << str;
/*********************用vector<char>初始化string完******************************/
/********************练习pair1*************************************/
//vector<int> vi(10);
//vector<string> vs(10);
//vector<pair<int,string> > vp(10);
//typedef pair<int,string> pis;
//int i(0);
//for(i = 0 ;i!=10;++i){
//	vi[i] = i+1;
//	vs[i] = string(i+1,'a' + i);
//	vp[i] = pis(vi[i],vs[i]);
//	//vp[i] = make_pair(vi[i],vs[i]);
//}
//vector<pair<int,string> >::iterator it = vp.begin();
//while(it!=vp.end()){
//	cout << it->first << ":" <<it->second << endl;
//	it ++;
//}

/********************练习pair1完************************************/

/*********************用back_inseter来添加元素**********************************/
//vector<string> vc;
//fill_n(back_inserter(vc),10,string("xf"));

//vector<int> iv;
//list<int> il;
//int i;
//while(cin>>i){
//	il.push_back(i);
//}
//iostream::io_state statte = cin.rdstate();
//cin.clear();
//cin.sync();
//
//list<int>::iterator liter = il.begin();
//while(liter!=il.end()){
//	cout << *liter++ << endl;
//}
//
//copy(il.begin(),il.end(),back_inserter(iv));
//cout << "Copy End"<<endl;
//vector<int>::iterator viter = iv.begin();
//cin >> i;
//while(viter!=iv.end()){
//	cout << *viter << endl;
//	viter++;
//}
//cin.clear();
//cin.sync();
/*********************用back_inseter来添加元素完**********************************/
/*********************统计单词字母4个以下的并输出**********************************/
	/* vector<string> vs;
	 string inputStr("");
	 cout << "input your words:(end with \"quit0\")" << endl;
	 while(cin >> inputStr){
		 if(inputStr==string("quit0")){
			 break;
		 }
		 *back_inserter(vs) = inputStr;
	 }
	 cin.clear();
	 cin.sync();
	 vector<string>::iterator uniEndIter = unique(vs.begin(),vs.end());
	 vs.erase(uniEndIter,vs.end());
	 sort(vs.begin(),vs.end());
	 int numOfGT4 = count_if(vs.begin(),vs.end(),GT4);
	 vector<string>::iterator vIter = vs.begin();
	 cout << endl;
	 cout << "now these below are GT4 words" << endl;
	 while(vIter!=vs.end()){
		 if(GT4(*vIter)){
			 cout << *vIter << endl;
		 }
		 vIter++;
	 }
	 */
	 
/*********************统计单词字母4个以下的并输出完**********************************/
/*********************使用流迭代器来按入输入文本**********************************/
//vector<string> sv;
//istream_iterator<string> in_iter(cin);
//istream_iterator<string> eof;
//while(in_iter!=eof&&*in_iter!=string("quit0")){
//	sv.push_back(*in_iter++);
//}
//MapzUtil::showVector(sv);
/*********************使用流迭代器来按入输入文本完**********************************/
/*********************写到文件或者cout*********************/
//istream_iterator<string> in_iter(cin),eof;
//ofstream ofile;
//string fileName("iofile");
//ofile.open(fileName.c_str());
//ostream_iterator<string> out_iter(ofile/*cout*/,"\n");
//while(in_iter!=eof&&ofile&&*in_iter!=string("quit0")){
//	*out_iter++ = *in_iter++;
//}
//ofile.close();
/*********************写到文件或者cout完*********************/
/*********************算法和绑定流*********************/
/*
 * 要先sort再用unique_copy否则有问题
 */
//istream_iterator<int> in_iter(cin),eof;
//vector<int> vi(in_iter,eof);
//ostream_iterator<int> output(cout," ");
//sort(vi.begin(),vi.end());
//unique_copy(vi.begin(),vi.end(),output);
/*********************算法和绑定流完*********************/
	 
/*********************五种迭代器习题************************/
/*
 * 1.const的 vector必须用const_iterator
 */
//string sa[10];
//const vector<string> vi(sa,sa+6);
//vector<string>::const_iterator iter = vi.begin()+2;
/*
 * 2.循环到容器外出错，编译的时候不会出错
 */
//vector<string> vi(4,"xx");
//vector<string> vi2(4,"xx");
//sort(vi.begin(),vi2.end());
/*
 * 3.结束小于开始，编译出错
 */
//vector<string> vi(4,"xx");
//sort(vi.begin(),vi.rend());
/*********************五种迭代器习题完************************/
/*********************类************************************/
//person me(string("Mapz"),string("Nanhai"));
//cout<<me.getName() << ":" << me.getAdd() << endl;
//MapzUtil mu = MapzUtil();
//MapzUtil ma(mu);
//MapzUtil mi = ma;
//MapzUtil mo;
//cout << mo << endl; 
//cout << mi << endl;
//cout << ma << endl;
//cout << mu << endl;
//cout << (ma + mu) << endl;
/********************类和函数对象********************************/
//vector<string> vs(10);
//vector<string>::iterator vi = vs.begin();
//fill(vs.begin(),vs.end(),"xax");
//MapzUtil::addStrToVec(vi,vi+5,MapzUtil::eachPlusOne);
//MapzUtil::showVector(vs);
/********************宏的函数模版使用************************/
//int x = 0;
//int y = 1;
//
//do{
//	BREAK_IF(BIGGER(x,y));
//	cout << "s" << endl;
//}
//while(0);
//
//vector<string> vi(4,"xx");
//SHOW_VEC(string,vi,it);
//
//vector<int> ve(4,5);
//SHOW_VEC(int,ve,itf);
//
//debug("%d,%d",1,2);

/********************宏的函数模版使用************************/
/********************类的派生:多态************************/
/**
 * 容器不能实现多态
 */
//person p(string("Mapz"),string("Nanhai"));
//kicker k;
//funcAttack(p);
//funcAttack(k);
//vector<person> vc;
//vector<person*> vcp;
//vcp.push_back(&p);
//vcp.push_back(&k);
//person *pp = &k;
//pp->attack();
////vc[0] = p;	
////vc[1] = k;
//vc.push_back(p);
//vc.push_back(k);
//cout << vc.size() << endl;
//cout << pp->name << endl;
//VEC_PROCESS_FUNC(person,vc,itxv,attack);
/********************类的派生：多态************************/
/********************类的派生：句柄************************/
/*
 * 如上所说，无法由容器获得多态，由句柄来实现
 * 句柄(handle)换句话说基本上就是指向基类的智能指针类
 * 下面的代码在使用容器的时候内存有露出，晚上再研究一下
 */
//vector<person_handle> vph;
//person_handle php(person(string("Mapz"),string("Nanhai")));
//person_handle phk(kicker(string("MapzKick"),string("Foshan")));
////vph.push_back(php);
////vph.push_back(phk);
//php->attack();
//phk->attack();
////VEC_PROCESS_FUNC_PO(person_handle,vph,itxv,attack);
////vector<person_handle>::iterator iter = vph.begin();
////while(iter!=vph.end()){
////	(*iter)  -> attack();
////	iter++;
////}
/********************类的派生：句柄************************/
/********************函数模版的使用************************/
int x = 9;
string c("xxc");
c_out(x);
c_out_n(2);
c_out(c);
/********************函数模版的使用************************/
/*====================end of file==========================*/
	cout << endl;
	cout << "end of program,any key to quit" << endl;
	system("pause");
	return 1;
}




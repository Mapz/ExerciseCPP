#define BREAK_IF(cond) if(cond) break;
#define BIGGER(x,y) x>y
#define SHOW_VEC(_type,_vec,_it)\
	vector<_type>::iterator _it = _vec.begin();\
	while(_it!=_vec.end()){\
		cout << *_it++ << endl;\
	}
#define debug(format, ...) fprintf (stderr, format, ## __VA_ARGS__)
#define VEC_PROCESS_FUNC(CLASS,VEC,ITER,FUNC) \
	vector<CLASS>::iterator ITER = VEC.begin(); \
	while(ITER!= VEC.end()){	\
		ITER++ -> FUNC();	\
	}
#define VEC_PROCESS_FUNC_PO(CLASS,VEC,ITER,FUNC) \
	vector<CLASS>::iterator ITER = VEC.begin(); \
	while(ITER!= VEC.end()){	\
		**ITER++ -> FUNC();		\
	}

	

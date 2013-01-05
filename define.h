#define BREAK_IF(cond) if(cond) break;
#define BIGGER(x,y) x>y
#define SHOW_VEC(_type,_vec,_it)\
	vector<_type>::iterator _it = _vec.begin();\
	while(_it!=_vec.end()){\
		cout << *_it++ << endl;\
	}
#define VEC_PROCESS_FUNC(_type,_vec,_it,_func)\
	vector<_type>::iterator _it = _vec.begin();\
	while(_it!=_vec.end()){\
		_it++->_func();\
	}
#define debug(format, ...) fprintf (stderr, format, ## __VA_ARGS__)

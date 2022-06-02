#include "cl_app.h"
#include "_2.h"
#include "_3.h"
#include "_4.h"
#include "_5.h"
#include "_6.h"
#include <iostream>
using namespace std;

void cl_app::derevo() {
	string root_name;
	cin >> root_name;
	set_name(root_name);
	cl_base* cur_predok = this;
	cl_base* root = this;
	do {
		string spinogriz, IP;
		int clas;
		cin>>IP;
		if (IP == "endtree") {
			break;
		}
		cin >> spinogriz >> clas;
		if (IP=="/"){
			cur_predok = root;
		} else {
			cur_predok = findIP(IP);
		}
		switch (clas) { 
			case 2:
				(cur_predok)->add_spinogriz(std::unique_ptr<cl_base>(new _2(spinogriz)));
				break;
			case 3:
				(cur_predok)->add_spinogriz(std::unique_ptr<cl_base>(new _3(spinogriz)));
				break;
			case 4:
				(cur_predok)->add_spinogriz(std::unique_ptr<cl_base>(new _4(spinogriz)));
				break;
			case 5:
				(cur_predok)->add_spinogriz(std::unique_ptr<cl_base>(new _5(spinogriz)));
				break;
			case 6:
				(cur_predok)->add_spinogriz(std::unique_ptr<cl_base>(new _6(spinogriz)));
				break;
		}
	} while (true);	
}

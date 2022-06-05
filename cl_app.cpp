#include "cl_app.h"
#include "Path.h"
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
	main_root = root_name;
	do {
		string IP, spinogriz;
		int clas;
		cin >> IP;
		if (IP == "endtree") {
			break;
		}
		cin >> spinogriz >> clas;
		if (IP == "/") {
			cur_predok = root;
		}
		else {
			cur_predok = findIP(Path(IP));
			if (cur_predok == 0) {
				std::cout << "The head object " << IP << " is not found\n";
				main_root = "";
				break;
			}
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

void cl_app::questions() {
	std::string command;
	std::string cur_obj;
	std::string object;
	std::string coord;
	do {
		std::cin >> command;
		
		if (command == "END") {
			break;
		}
		else if (command == "FIND") {
			std::cin >> coord;
			object = define(coord, cur_obj);
			if (object != "") {
				std::cout  << coord << "    Object name: " << object << "\n";
			}
			else {
				std::cout << coord << "    Object is not found" << "\n";
			}
		}
		else if (command == "SET") {
			std::cin >> coord;
			object = define(coord, cur_obj);
			if (object != "") {
				cur_obj = object;
				std::cout << "Object is set : " << cur_obj << "\n";
			}
			else {
				std::cout << "Object is not found: " << cur_obj << " " << coord << "\n";
			}
		}
	} while (true);

}

std::string cl_app::define(std::string IP, std::string cur) {
	if (IP == "/") {
		return main_root; //корень
	}
	else if (IP == ".") { //? нынешний
		return cur;
	}
	else if (IP[1]=='/' and IP[0]=='/') { // от корневого
		
		return (findIP(Path(IP))->get_name());
	} 
	else if (IP[0] != '/') { // относительная координата от нынешней 
		if (cur != "") {
			IP.insert(0, (cur + '/'));
			return(findIP(Path(IP))->get_name());
		} 
		return "";
	}
	else { //абсолютная 
		return(findIP(Path(IP))->get_name());
	}
}

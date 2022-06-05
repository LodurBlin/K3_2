#ifndef CL_APP_H
#define CL_APP_H
#include "cl_base.h"
#include <iostream>
class cl_app : public cl_base //1 
{
private:
	std::string main_root;
public:
	cl_app() : cl_base("") {};
	void derevo(); //postr
	void print() {  //zapuck
		std::cout << "Object tree";
		print_hierarchy(0);
		if (main_root != "") {
			std::cout << "\n";
			questions();
		}
	};
	std::string define(std::string IP, std::string cur);
	void questions();
};

#endif

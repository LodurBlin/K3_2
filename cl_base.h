#ifndef CL_BASE_H
#define CL_BASE_H
#include <vector>
#include <memory>
#include <string>


class cl_base {
	std::string ob_name; //наименование

public:
	cl_base* p_predok{}; //указатель на голову

	std::vector<std::unique_ptr<cl_base>> spinogrizi; //массив указателей

	cl_base(std::string name, cl_base* p_predok = 0) : ob_name{ name }, p_predok{ p_predok } {}; //конструктор

	void set_name(std::string name) { //определение имени
		ob_name = name;
	}
	std::string get_name() const { //получение имени
		if (this) {
			return ob_name;
		}
		else {
			return "";
		}
	}
	void add_spinogriz(std::unique_ptr<cl_base>&&); //добавление дочернего объекта

	void print_hierarchy(int offset); //вывод

	cl_base* kto_otez(); //получение головного указателя

	std::unique_ptr<cl_base> uproot(); //выкорчевывание
	void move_to(cl_base* destination);//усыновление

	cl_base* search(std::string wanted); //поиск объекта по имени

	cl_base* findIP(std::vector<std::string> IP);//метод получения указателя на любой объект в составе дерева иерархии объектов согласно пути (координаты)
};
#endif

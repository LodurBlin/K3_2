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
			return ob_name;
		}
		void add_spinogriz(std::unique_ptr<cl_base>&&); //добавление дочернего объекта

		void print_hierarchy(int offset); //вывод

		cl_base* kto_otez(); //получение головного указателя

		std::unique_ptr<cl_base> uproot(); //выкорчевывание
		void move_to(cl_base* destination);//усыновление
		
		cl_base* search(std::string wanted); //поиск объекта по имени
		
		/*метод получения указателя на любой объект в составе дерева согласно пути (координаты). 
		 coord: / -корень, //ob_name -поиск от корня, . -текущий объект, o1/o2 - o1 подч this, относит коорд от текущ об, /o1/o2 - абс коорд
		Если координата пустая строка или объект не найден, то вернуть нулевой указатель.
		в строке ввода первым указано не наименование головного объекта, а абсолютный путь к нему.
		
		SET «координата»  – устанавливает текущий объект;
		FIND «координата» – находит объект относительно текущего;
		END – завершает функционирование системы (выполнение программы).
		*/
		cl_base* findIP(std::string);
};

#endif

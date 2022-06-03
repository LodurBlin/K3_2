#include "cl_base.h"
#include "Path.h"
#include <iostream>
#include <cassert>
#include <algorithm>

void cl_base::add_spinogriz(std::unique_ptr <cl_base>&& spinogriz) {

	spinogriz->p_predok = this;
	spinogrizi.push_back(std::move(spinogriz));

}

void cl_base::print_hierarchy(int offset) {
	std::cout << "\n" << std::string(offset * 4, ' ') << this->ob_name;
	if (spinogrizi.size() == 0) {
		return;
	}
	for (const auto& spin : spinogrizi) {
		(spin)->print_hierarchy(++offset);
		--offset;
	}
}


cl_base* cl_base::kto_otez() {
	return p_predok;
}
std::unique_ptr<cl_base> cl_base::uproot() {
	assert(p_predok);
	auto& ch = p_predok->spinogrizi;
	std::unique_ptr<cl_base> a = nullptr;
	for (auto& spin : ch) {
		if (this == spin.get()) {
			std::swap(a, spin);
		}
	}
	ch.erase(std::remove(ch.begin(), ch.end(), nullptr), ch.end());
	return a;
}

void cl_base::move_to(cl_base* destination) {
	destination->add_spinogriz(uproot());
}

cl_base* cl_base::search(std::string wanted) {
	if (this->get_name() == wanted) {
		return this;
	}
	for (const auto& spin : spinogrizi) {
		auto res = spin->search(wanted);
		if (res) return res;
	}
	return nullptr;
}

cl_base* cl_base::findIP(std::vector<std::string> IP) {
	cl_base* cur_predok;
	cur_predok = search(IP[0]);
	cur_predok = cur_predok->search(IP.back());
	return cur_predok;
}

void cl_base::questions() {
	std::string command;
	std::string cur_obj;
	do {
		std::cin >> command;
		if (command == "END") {
			break;
		}
		else if (command == "FIND") {
			std::cin >> command;
			define(command, cur_obj);
		}
		else if (command == "SET") {
			std::cin >> command;
			define(command, cur_obj);
		}
	} while (true);
		
}

cl_base* cl_base::define(std::string IP, std::string cur) {
	if (IP == "/") {
		return nullptr; //корень
	}
	else if (IP==".") {
		return (search(cur));
	}
	else {
		std::string object = (findIP(Path(this->get_name()))->get_name());
		return (search(object));
	}
}

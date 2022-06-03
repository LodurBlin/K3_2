#include <vector>
#include <string>
#include <algorithm>

class Path : public std::vector<std::string>
{
public:
    Path(std::string IP) { //   o1/o2/o3
        std::string cur_name;
        bool flag = 0;
        for (int i = 0; i < IP.size(); i++) {
            if (IP[i] == '/') {
                flag = 1;
            }
            else {
                cur_name += IP[i];
            }
            if (i == IP.size() - 1) { //последнее слово
                flag = 1;
            }
            if (flag == 1) {
                this->push_back(cur_name);
                cur_name = "";
                flag = 0;
            }

        }

        this->erase(std::remove(this->begin(), this->end(), ""), this->end());
    }
};

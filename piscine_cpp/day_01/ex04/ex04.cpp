#include <iostream>

int     main(void) {
    std::string str = "HI THIS IS BRAIN";
    std::string* pstr = &str;
    std::string& rstr = str;

    std::cout << "Normal string \'" << str << "\'" << std::endl;
    std::cout << "Pointer string \'" << *pstr << "\'" << std::endl;
    std::cout << "Reference string \'" << rstr << "\'" << std::endl;
    return 0;
}

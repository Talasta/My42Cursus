
#include <iostream>
#include <fstream>

void    process_file(char const * a[]) {
    std::string filename(a[1]), str1(a[2]), str2(a[3]), line;
    std::ifstream in(filename);
    std::ofstream out(filename + ".replace");
    size_t len1 = str1.length();
    size_t len2 = str2.length();
    size_t pos = 0;

    if (!in) {
        std::cerr << "Could not open " << filename << std::endl;
        return ;
    }
    if (!out) {
        std::cerr << "Could not open " << filename << ".replace" << std::endl;
        return ;
    }

    while (getline(in, line))
    {
        pos = 0;
        while (true)
        {
            pos = line.find(str1, pos);
            if (pos == std::string::npos)
                break;
            line.replace(pos, len1, str2);
            pos += len2;
        }

        out << line << '\n';
    }
    return ;
}

int     main(int argc, char const *argv[]) {

    if (argc == 4) {
        process_file(argv);
    } else {
        std::cout << "usage: ./replace <filename> <string1> <string2>"
                << std::endl;
    }
    return 0;
}

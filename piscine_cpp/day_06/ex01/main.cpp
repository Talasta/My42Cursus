#include <cstdlib>
#include <iostream>

struct Data
{
    std::string s1;
    int         n;
    std::string s2;
};

void gen_random(char *s, const int len)
{
    const char alphanum[] = "0123456789 ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < len; ++i)
    {
        s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    s[len] = 0;
}

void*       serialize(void)
{
    char    random_string[9];
    Data* data = new Data;

    gen_random(random_string, 8);
    data->s1 = random_string;
    gen_random(random_string, 8);
    data->s2 = random_string;
    data->n = rand();
    std::cout << "Serialize" << std::endl;
    std::cout << "s1: " << data->s1 << std::endl;
    std::cout << "n:  " << data->n << std::endl;
    std::cout << "s2: " << data->s2 << std::endl;
    return reinterpret_cast<void*>(data);
}

Data*       deserialize(void* raw)
{
    return reinterpret_cast<Data*>(raw);
}

int     main(void)
{
    srand(time(NULL));
    void*   addr = serialize();
    Data*   data = deserialize(addr);
    std::cout << std::endl << "Deserialized" << std::endl;
    std::cout << "s1: " << data->s1 << std::endl;
    std::cout << "n:  " << data->n << std::endl;
    std::cout << "s2: " << data->s2 << std::endl;
    delete data;
    return 0;
}

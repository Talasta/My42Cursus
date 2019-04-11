template<typename T>
void        iter(T* array, unsigned int len, void(*f)(const T&))
{
    for (unsigned int i = 0; i < len; ++i)
    {
        f(array[i]);
    }
}

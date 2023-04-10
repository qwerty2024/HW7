#include "IntegerArray.h"

IntegerArray::IntegerArray(int lenght)
{
    len = lenght;
    try
    {
        if (lenght <= 0)
            throw bad_length();

        data = new int[lenght] {};
    }
    catch (const exception& e)
    {
        cout << e.what();
        len = 0;
        data = nullptr;
    }
}

IntegerArray::IntegerArray(int length, int init)
{
    len = length;
    try
    {
        if (length <= 0)
            throw bad_length();

        data = new int[length] {};
        for (int i = 0; i < len; ++i)
        {
            data[i] = init;
        }
    }
    catch (const exception& e)
    {
        cout << e.what();
        len = 0;
        data = nullptr;
    }
}

void IntegerArray::erase() 
{
     delete[] data;

     data = nullptr;
     len = 0;
}

int& IntegerArray::operator[](int index)
{
    try
    {
        if (index < 0 || index >= len)
            throw bad_range();

        return data[index];
    }
    catch (exception& e)
    {
        cout << e.what();

        return index; //вернем индекс, если вышли за пределы
    }
}

void IntegerArray::reallocate(int newLength)
{
    erase();

    len = newLength;
    try
    {
        if (len <= 0)
            throw bad_length();

        data = new int[len] {};
    }
    catch (const exception& e)
    {
        cout << e.what();
        len = 0;
        data = nullptr;
    }
}

void IntegerArray::resize(int newLength)
{
    if (newLength == len)
        return;

    len = newLength;
    try
    {
        if (len <= 0)
            throw bad_length();
    }
    catch (const exception& e)
    {
        cout << e.what();
        len = 0;
        data = nullptr;
        return;
    }

    int *new_data = new int[newLength];

    if (len > 0)
    {
        int elementsToCopy{ (newLength > len) ? len : newLength };

        for (int index = 0 ; index < elementsToCopy; ++index)
            new_data[index] = data[index];
    }

    delete[] data;

    data = new_data;
    len = newLength;
}

IntegerArray::IntegerArray(const IntegerArray& a)
{
    reallocate(a.getLength());

    for (int index = 0; index < len; ++index)
        data[index] = a.data[index];
}

IntegerArray& IntegerArray::operator=(const IntegerArray& a)
{
    if (&a == this)
        return *this;

     reallocate(a.getLength());

     for (int index{ 0 }; index < len; ++index)
        data[index] = a.data[index];

    return *this;
}

int IntegerArray::insertBefore(int value, int index)
{
    try
    {
        if (index < 0 || index >= len)
            throw bad_range();
    }
    catch (exception& e)
    {
        cout << e.what();
        return index; //вернем индекс, если вышли за пределы
    }

    int *new_data = new int[len + 1];

    for (int before = 0; before < index; ++before)
        new_data[before] = data[before];

    new_data[index] = value;

    for (int after = index; after < len; ++after)
        new_data[after + 1] = data[after];

    delete[] data;
    data = new_data;
    ++len;
    return 0;
}

int IntegerArray::remove(int index)
{
    try
    {
        if (index < 0 || index >= len)
            throw bad_range();
    }
    catch (exception& e)
    {
        cout << e.what();
        return index; 
    }

    if (len == 1)
    {
        erase();
        return 0;
    }

    int *new_data = new int[len - 1];

    for (int before{ 0 }; before < index; ++before)
        new_data[before] = data[before];

    for (int after{ index + 1 }; after < len; ++after)
        new_data[after - 1] = data[after];

    delete[] data;
    data = new_data;
    --len;
    return 0;
}

void IntegerArray::push_front(int value)
{
    int *new_data = new int[len + 1];

    new_data[0] = value;

    for (int after = 0; after < len; ++after)
        new_data[after + 1] = data[after];

    delete[] data;
    data = new_data;
    ++len;
}

void IntegerArray::push_back(int value)
{
    int *new_data = new int[len + 1];

    for (int before = 0; before < len; ++before)
        new_data[before] = data[before];

    new_data[len] = value;

    delete[] data;
    data = new_data;
    ++len;
}

bool IntegerArray::search(int value, int &index)
{  
    for (int i = 0; i < len; ++i)
    {
        if (data[i] == value)
        {
            index = i;
            return true;
        }
    }
    
    return false;
}

void IntegerArray::printer()
{
    if (len == 0) cout << "Void array!";
    for (int i = 0; i < len; ++i)
        cout << "[" << i << "]" << data[i] << " ";
    cout << endl;
}
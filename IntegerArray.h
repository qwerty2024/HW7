#pragma once

#include <iostream>
#include <exception>


using namespace std;

class IntegerArray
{
public:
    IntegerArray() = default;
    IntegerArray(int length);
    IntegerArray(int length, int init);

    IntegerArray(const IntegerArray& a);
    IntegerArray& operator=(const IntegerArray& a);

    void erase();
    int getLength() const { return len; }
    void reallocate(int newLength);
    void resize(int newLength);
    int insertBefore(int value, int index);
    int remove(int index);
    void push_front(int value);
    void push_back(int value);
    bool search(int value, int& index);
    void printer();

    int& operator[](int index);

	~IntegerArray() 
    {
        delete[] data;
    }

private:
	int *data;
	int len;
};

class bad_length : public exception
{
public:
    virtual const char* what() const noexcept override
    {
        return "ERROR: Bad Length!\n";
    }
};

class bad_range : public exception
{
public:
    virtual const char* what() const noexcept override
    {
        return "ERROR: Bad Range! >>> ";
    }
};
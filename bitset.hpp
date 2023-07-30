#ifndef BITSET
#define BITSET
#include <iostream>

const int elemSize = 8*sizeof(int);

class Bitset
{
private:
	int* m_arr;
	int m_size;
	int m_capasity;
public:
    Bitset(int count);
    ~Bitset();
    void set(int index);
    void reset(int index);
    void resize();
    void swap(int, int);
    void flip(int);
    void reverse();
	bool test(int index) const;
    
    void push_back(int);
    void pop_back();
    
};

#endif

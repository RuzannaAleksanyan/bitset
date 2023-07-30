#include "bitset.hpp"


Bitset::Bitset(int count)
{
	m_size = 0;
	m_capasity = count/elemSize + 1;
	m_arr = new int[m_capasity];
	for(int i = 0; i < m_capasity; ++i) {
		m_arr[i] = 0;
	}
}

Bitset::~Bitset() {
	m_size = 0;
	m_capasity = 0;
	delete m_arr;
}

void Bitset::set(int index)
{
	if(index < 0 || index >= m_capasity * elemSize) 
	{
        	throw std::out_of_range("Invalid index");
	}

	m_arr[index/elemSize] |= (1 << (index - (index/elemSize)*elemSize));
}

void Bitset::reset(int index)
{
	if(index < 0 || index >= m_capasity*elemSize)
	{
        	throw std::out_of_range("Invalid index");
	}
    
	m_arr[index/elemSize] &= ((!1) << (index - (index/elemSize)*elemSize)); 
}

void Bitset::resize()
{
	int* tmp = new int[m_capasity*2];
	for(int i = 0; i < m_size; i++)
	{
		tmp[i] = m_arr[i];
	}
	delete [] m_arr;
	m_arr = tmp;
	tmp = NULL;
	m_capasity *=2;
}

void Bitset::swap(int i, int j)
{
    if(i < 0 || i >= m_capasity * elemSize || j < 0 || j >= m_capasity * elemSize) 
    {
        throw std::out_of_range("Invalid index");
    }

	int x = (1 & (m_arr[i/elemSize] >> (i - (i/elemSize)*elemSize)));
	int y = 1 & (m_arr[j/elemSize] >> (j - (j/elemSize)*elemSize));
	if(x != y)
	{
		if(x != 0)
		{
			m_arr[i/elemSize] = m_arr[i/elemSize] - (x << i);
		}
		else
		{
			m_arr[i/elemSize] = m_arr[i/elemSize] | (x << i);
		}
		if(y != 0)
		{
			m_arr[j/elemSize] = m_arr[j/elemSize] - (x << j);  
		}
		else
		{
			m_arr[j/elemSize] = m_arr[j/elemSize] | (x << j);
		}
	}
}

void Bitset::flip(int i)
{
	if(i < 0 || i >= m_capasity * elemSize)
	{
		throw std::out_of_range("Invalid index");
	}
	else if((m_arr[i/elemSize] >> (i - (i/elemSize)*elemSize))% 2 == 0)
	{
		m_arr[i/elemSize] |= (1 << (i - (i/elemSize)*elemSize));
	}
	else
	{
		m_arr[i/elemSize] &= ((!1) << (i - (i/elemSize)*elemSize)); 
	}
}

void Bitset::reverse()
{
	for(int i = 0, j = (m_size * elemSize) -1; i < j; ++i, --j)
	{
		swap(i, j);
	}
}

bool Bitset::test(int index) const
{
	if (index < 0 || index >= m_capasity * elemSize)
	{
		throw std::out_of_range("Invalid index");
	}
	
	return (m_arr[index / elemSize] >> (index - (index / elemSize) * elemSize)) & 1;
}

void Bitset::push_back(int elem)
{
	if(m_size == m_capasity)
	{
		resize();
	}
	m_arr[m_size] = elem;
	m_size++;
}

void Bitset::pop_back()
{
	m_size -= 1;
}

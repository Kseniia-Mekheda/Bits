#include <iostream>
#include "bits.h"

size_t BitSet::GetSize() const
{
	return sizeof bit * 8;
}

BitSet::BitSet()
	:bit(0)
{
	size = GetSize();
}

BitSet::BitSet(unsigned char val)
	:bit(val)
{
	size = GetSize();
}

void BitSet::SetBit(size_t index)
{
	if (index < 0 || index >= size)
	{
		std::cout << "Inappropriate index;";
		return;
	}

	bit |= (1 << index);
}

void BitSet::ResetBit(size_t index)
{
	if (index < 0 || index >= size)
	{
		std::cout << "Inappropriate index;";
		return;
	}

	bit = bit & ~(1 << index);
}

void BitSet::FlipBit(size_t index)
{
	if (index < 0 || index >= size)
	{
		std::cout << "Inappropriate index;";
		return;
	}

	if (TestBit(index))
	{
		ResetBit(index);
	}
	else
	{
		SetBit(index);
	}
}

void BitSet::PrintBitSet() const
{
	for (size_t i = 0; i < size; ++i)
	{
		if (TestBit(i))
		{
			std::cout << 1;
		}
		else
		{
			std::cout << 0;
		}
	}
	std::cout << std::endl;
}

bool BitSet::TestBit(size_t index) const
{
	if (index < 0 || index >= size)
	{
		std::cout << "Inappropriate index;";
	}

	return (bit & (1 << index)) != 0;
}

bool BitSet::IsEmpty() const
{
	bool statement = true;
	for (size_t i = 0; i < size; ++i)
	{
		if (TestBit(i))
		{
			statement = false;
			break;
		}
	}
	return statement;
}

bool BitSet::IsAny() const
{
	bool statement = false;
	for (size_t i = 0; i < size; ++i)
	{
		if (TestBit(i))
		{
			statement = true;
			break;
		}
	}
	return statement;
}

bool BitSet::IsFull() const
{
	bool statement = true;
	for (size_t i = 0; i < size; ++i)
	{
		if (!TestBit(i)) {
			statement = false;
			break;
		}
	}
	return statement;
}

bool BitSet::operator[](size_t index) const
{
	if (index < 0 || index >= size)
	{
		std::cout << "Inappropriate index;";
	}

	if (TestBit(index))
	{
		return true;
	}
	else
	{
		return false;
	}
}

size_t BitSet::Count() const
{
	size_t counter = 0;
	for (size_t i = 0; i < size; ++i)
	{
		if (TestBit(i))
		{
			++counter;
		}
	}
	return counter;
}

#pragma once
class BitSet
{
private:
	unsigned char bit;
	size_t size;
	size_t GetSize() const;
public:
	BitSet();
	BitSet(unsigned char val);

	void SetBit(size_t index);
	void ResetBit(size_t index);
	void FlipBit(size_t index);

	void PrintBitSet() const;

	bool TestBit(size_t index) const;
	bool IsEmpty() const;
	bool IsAny() const;
	bool IsFull() const;
	bool operator[](size_t index) const;

	size_t Count() const;
};
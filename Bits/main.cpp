#include <iostream>
#include "bits.h"


int main() {
	BitSet OurBits; 
	
	std::cout << "Printing our bit set: " << std::endl;
	OurBits.PrintBitSet(); 

	OurBits.SetBit(3);
	OurBits.SetBit(1);
	OurBits.SetBit(2); 
	OurBits.SetBit(5); 

	std::cout << "Bits set on indexes 1, 2, 3, 5, our bit set now: " << std::endl;
	OurBits.PrintBitSet(); 

	OurBits.ResetBit(2);
	OurBits.ResetBit(7); 
	std::cout << "Bits reset on index 2, 7, our bit set now: " << std::endl;
	OurBits.PrintBitSet();

	OurBits.FlipBit(7); 
	OurBits.FlipBit(2);
	OurBits.FlipBit(3);
	std::cout << "Bits flipped on index 2, 3, 7, our bit set now: " << std::endl;
	OurBits.PrintBitSet();

	std::cout << "Are all elements filled?: " << OurBits.IsFull() << std::endl;
	std::cout << "Is at least one bit set?: " << OurBits.IsAny() << std::endl;
	std::cout << "Is our bit set empty?: " << OurBits.IsEmpty() << std::endl;

	std::cout << "Testing bits: \n Bit Index 1: " << OurBits.TestBit(1) << "\n Bit Index 6: " << OurBits.TestBit(6) << std::endl;
	std::cout << "Bits counter: " << OurBits.Count() << std::endl;

	std::cout << "Access by using [ ] (Bit Index 2): " << OurBits[2] << std::endl;
	std::cout << std::endl;

	BitSet Test;
	Test.SetBit(0);
	Test.SetBit(4);
	Test.SetBit(7);

	std::cout << std::endl;
	std::cout << "Our bit set before usage of ~ operator: " << std::endl;
	Test.PrintBitSet();

	~Test; 
	std::cout << "After usage: " << std::endl;
	Test.PrintBitSet();
	std::cout << std::endl;

	BitSet TestBitSet;
	std::cout << "Usage of operator |=: " << std::endl;
	TestBitSet.SetBit(4);
	std::cout << "Before: \n";  OurBits.PrintBitSet(); TestBitSet.PrintBitSet();
	std::cout << "After: \n";
	TestBitSet |= OurBits;
	TestBitSet.PrintBitSet();
	std::cout << std::endl;

	BitSet NewBits;
	std::cout << "Usage of operator &=: " << std::endl;
	NewBits.SetBit(0);
	NewBits.SetBit(7);
	std::cout << "Before: \n"; OurBits.PrintBitSet(); NewBits.PrintBitSet();
	NewBits &= OurBits;
	std::cout << "After: \n";
	NewBits.PrintBitSet();
	std::cout << std::endl;
	return 0;
}


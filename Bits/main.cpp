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

	std::cout << "Bits filled, our bit set now: " << std::endl;
	OurBits.PrintBitSet(); 

	OurBits.ResetBit(2);
	OurBits.ResetBit(7); 
	std::cout << "Bits reset, our bit set now: " << std::endl;
	OurBits.PrintBitSet();

	OurBits.FlipBit(7); 
	OurBits.FlipBit(2);
	OurBits.FlipBit(3);
	std::cout << "Bits flipped, our bit set now: " << std::endl;
	OurBits.PrintBitSet();

	std::cout << "Are all elements filled?: " << OurBits.IsFull() << std::endl;
	std::cout << "Is at least one bit set?: " << OurBits.IsAny() << std::endl;
	std::cout << "Is our bit set empty?: " << OurBits.IsEmpty() << std::endl;

	std::cout << "Testing bits: \n Bit Index 1: " << OurBits.TestBit(1) << "\n Bit Index 6: " << OurBits.TestBit(6) << std::endl;
	std::cout << "Bits counter: " << OurBits.Count() << std::endl;

	std::cout << "Access by using [ ] (Bit Index 2): " << OurBits[2] << std::endl;;

	return 0;
}


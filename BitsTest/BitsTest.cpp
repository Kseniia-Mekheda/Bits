#include "pch.h"
#include "CppUnitTest.h"
#include "../Bits/bits.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BitsTest
{
	TEST_CLASS(BitsTest)
	{
	public:
		
		TEST_METHOD(BitSetTest)
		{
			BitSet Bits;
			Bits.SetBit(0);
			Assert::IsTrue(Bits[0]);
			Assert::IsFalse(Bits[1]);

			std::ostringstream output;
			std::cout.rdbuf(output.rdbuf());

			Bits.SetBit(-4);
			Assert::AreEqual(output.str().c_str(), "Inappropriate index;");
		}

		TEST_METHOD(BitResetTest)
		{
			BitSet Bits;
			Bits.SetBit(0);
			Bits.SetBit(5);
			Assert::IsTrue(Bits[5]); 

			Bits.ResetBit(5);

			std::ostringstream output;
			std::cout.rdbuf(output.rdbuf());

			Bits.ResetBit(-4);

			Assert::IsFalse(Bits[5]);
			Assert::AreEqual(output.str().c_str(),  "Inappropriate index;");
		}

		TEST_METHOD(BitFlipTest)
		{
			BitSet Bits;
			Bits.SetBit(0);
			Bits.SetBit(5);
			Assert::AreEqual(Bits[5], true);
			
			Bits.FlipBit(5); 
			Bits.FlipBit(4);
			Assert::AreEqual(Bits[5], false);
			Assert::AreEqual(Bits[4], true);

			std::ostringstream output;
			std::cout.rdbuf(output.rdbuf());

			Bits.FlipBit(-4);
			Assert::AreEqual(output.str().c_str(), "Inappropriate index;");
		}

		TEST_METHOD(PrintBitsTest)
		{
			BitSet Bits;
			Bits.SetBit(3);
			Bits.SetBit(1);
			Bits.SetBit(2);
			Bits.SetBit(5);

			std::ostringstream output;
			std::cout.rdbuf(output.rdbuf());

			Bits.PrintBitSet(); 

			Assert::AreEqual(output.str().c_str(), "01110100\n");
		}

		TEST_METHOD(TestBitTest)
		{
			BitSet Bits;
			Bits.SetBit(3);
			Bits.SetBit(1);

			Assert::IsTrue(Bits.TestBit(1));
			Assert::IsFalse(Bits.TestBit(2));
		}

		TEST_METHOD(IsEmptyTest)
		{
			BitSet Bits;
			Bits.SetBit(3);
			Bits.SetBit(1);

			Assert::IsFalse(Bits.IsEmpty());

			Bits.ResetBit(3);
			Bits.ResetBit(1);

			Assert::IsTrue(Bits.IsEmpty());
		}

		TEST_METHOD(IsAnyTest)
		{
			BitSet Bits;
			Bits.SetBit(3);
			Bits.SetBit(1);

			Assert::IsTrue(Bits.IsAny()); 

			Bits.ResetBit(3);
			Bits.ResetBit(1);

			Assert::IsFalse(Bits.IsAny());
		}

		TEST_METHOD(IsFullTest)
		{
			BitSet Bits;
			Bits.SetBit(3);
			Bits.SetBit(1);

			Assert::IsFalse(Bits.IsFull());

			Bits.SetBit(0);
			Bits.SetBit(2);
			Bits.SetBit(4);
			Bits.SetBit(5);
			Bits.SetBit(6);
			Bits.SetBit(7);

			Assert::IsTrue(Bits.IsFull());
		}

		TEST_METHOD(CountTest)
		{
			BitSet Bits;
			Bits.SetBit(3);
			Bits.SetBit(1);
			Bits.SetBit(0);
			Bits.SetBit(2);

			size_t ExpectedCounterResult = 4;

			Assert::AreEqual(Bits.Count(), ExpectedCounterResult);
		}
	};
}

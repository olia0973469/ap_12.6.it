#include "pch.h"
#include "CppUnitTest.h"
#include "../ap_12.6.it/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			std::stringstream buffer;
			std::streambuf* oldbuffer = std::cout.rdbuf(buffer.rdbuf()); 
			
			printNumbersWithPrimeFactors(10);
			std::string result = buffer.str(); 

			Assert::AreEqual("2 3 4 5 6 8 9 10 12 15 ", result.c_str());

			std::cout.rdbuf(oldbuffer);
		}
	};
}

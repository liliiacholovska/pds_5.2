#include "pch.h"
#include "CppUnitTest.h"
#include "../pds_5(2)/pds_5(2).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestPerformSetOperations)
        {
            std::ostringstream output;
            std::streambuf* oldCoutBuffer = std::cout.rdbuf(output.rdbuf());

            std::istringstream input("5\n1 2 3 4 5\n3\n1 3 5\n3\n2 3 4\n");
            std::cin.rdbuf(input.rdbuf());

            performSetOperations();

            std::cout.rdbuf(oldCoutBuffer);

            std::string strOutput = output.str();
            Assert::IsTrue(strOutput.find("Bit vector A: 1 0 1 0 1") != std::string::npos);
            Assert::IsTrue(strOutput.find("Bit vector B: 0 1 1 1 0") != std::string::npos);
            Assert::IsTrue(strOutput.find("not A: 0 1 0 1 0") != std::string::npos);
            Assert::IsTrue(strOutput.find("AperB: 0 0 1 0 0") != std::string::npos);
            Assert::IsTrue(strOutput.find("Aob B: 1 1 1 1 1") != std::string::npos);
            Assert::IsTrue(strOutput.find("A \\ B: 1 0 0 0 1") != std::string::npos);
            Assert::IsTrue(strOutput.find("AxorB: 1 1 0 1 1") != std::string::npos);
        }
	};
}

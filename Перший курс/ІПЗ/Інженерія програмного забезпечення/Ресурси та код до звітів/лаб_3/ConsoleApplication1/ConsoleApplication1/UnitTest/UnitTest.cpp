#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\esulu\Desktop\folders\1 курс\swe\практические лабы\лр_4_Шулюпов_КН_221В\ConsoleApplication1\ConsoleApplication1\ConsoleApplication1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(y_test)
	{
	public:

		TEST_METHOD(calculate_get_2and5_res_minus0point03125)
		{
			double x_1 = 2;
			int n = 5;
			double exp_ed = -0.03125;
			double actual = y_2(x_1, n);
			Assert::AreEqual(exp_ed, actual);
		}

	
		TEST_METHOD(calculate_get_minus10and5_res_minus0point1)
		{
			double x_1 = -10;
			int n = 1;
			double exp_ed = -0.1;
			double actual = y_1(x_1, n);
			Assert::AreEqual(exp_ed, actual);
		}


		TEST_METHOD(calculate_get_minus10and5_res_minus0point25)
		{
			double x_1 = -10;
			int n = 1;
			double exp_ed = -0.25;
			double actual = y_1(x_1, n);
			Assert::AreEqual(exp_ed, actual);
		}

	};
	TEST_CLASS(checkValidParams_test)
	{
	public: 

		TEST_METHOD(CheckValidParams_get_minus10_20_3_5_exceptionNotThrown)
		{
			double x_1 = -10;
			double x_2 = 20;
			double step = 3;
			int n = 5;
			try {
				checkValidInput(x_1, x_2, step, n);
				Assert::IsTrue(true);
			}
			catch (...){
				Assert::Fail();
			}
 		}

	public: 
		TEST_METHOD(CheckValidParams_get_minus10_minus11_3_5_exceptionThrown)
		{
			double x_1 = -10;
			double x_2 = -11;
			double step = 1;
			int n = 5;
			try {
				checkValidInput(x_1, x_2, step, n);
				Assert::Fail();
			}
			catch (...) {
				Assert::IsTrue(true);
			}
		}
	};
}

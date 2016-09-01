#include "stdafx.h"
#include <PrintNumandString.h>

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace CustomPrint_Test
{
	[TestClass]
	public ref class UnitTest
	{
	private:
		TestContext^ testContextInstance;
		PrintNumAndString* ns;

	public: 
		/// <summary>
		///Gets or sets the test context which provides
		///information about and functionality for the current test run.
		///</summary>
		property Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ TestContext
		{
			Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ get()
			{
				return testContextInstance;
			}
			System::Void set(Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ value)
			{
				testContextInstance = value;
			}
		};

		// Test when 0 is sent as a number to the map
		[TestMethod]
		void TestMapWithZero()
		{
			std::map<int, string> map1;
			int i1 = 0;
			string s1 = "This is 0";
			map1.insert(pair<int, string>(i1, s1));
			vector<string> v1;
			v1 = ns->ProcessMap(map1);
			Assert::IsTrue(v1.empty());
		};

		// Test when one element is sent to the map
		[TestMethod]
		void TestMapWithOneElement()
		{
			std::map<int, string> map1;
			int i1 = 10;
			string expected = "This is 10";
			map1.insert(pair<int, string>(i1, expected));
			vector<string> v1;
			v1 = ns->ProcessMap(map1);
			Assert::AreEqual((int)v1.size(), 100);

			string actual = v1.at(9);
			Assert::IsTrue(expected == actual);
		};

		// Test when two elements are sent to the map
		[TestMethod]
		void TestMapWithTwoElements()
		{
			std::map<int, string> map1;
			int i1 = 10;
			string s1 = "Yes1";
			int i2 = 20;
			string s2 = "Yes2";
			map1.insert(pair<int, string>(i1, s1));
			map1.insert(pair<int, string>(i2, s2));

			vector<string> v1;
			v1 = ns->ProcessMap(map1);
			Assert::AreEqual((int)v1.size(), 100);

			string expected1 = "1";
			string expected2 = "Yes1";
			string expected3 = "Yes1Yes2";
			string actual1 = v1.at(0);
			string actual2 = v1.at(9);
			string actual3 = v1.at(19);

			Assert::IsTrue(expected1 == actual1);
			Assert::IsTrue(expected2 == actual2);
			Assert::IsTrue(expected3 == actual3);
		};
	};
}

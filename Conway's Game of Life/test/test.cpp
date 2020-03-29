#include <igloo/igloo.h>
#include <algorithm>
#include <myLib.h>

using namespace igloo;

Context (DecimalToHexStringFunction){
	Spec(Zero){
		Assert::That(intToHexStr(0), Equals("00"));
	}
	Spec(One){
		Assert::That(intToHexStr(1), Equals("01"));
	}
	Spec(Ten){
		Assert::That(intToHexStr(10), Equals("0A"));
	}
	Spec(Fifteen){
		Assert::That(intToHexStr(15), Equals("0F"));
	}
	Spec(Sixteen){
		Assert::That(intToHexStr(16), Equals("10"));
	}
	Spec(OneHundred){
		Assert::That(intToHexStr(100), Equals("64"));
	}
	Spec(TwoHundredAndFiftyFive){
		Assert::That(intToHexStr(255), Equals("FF"));
	}
};

Context(MemRepFunction){
	Spec(TwoThousandNineteen){
		ucm::json actual = memRep(2019);
		ucm::json list = {"E3", "07", "00", "00"};
		ucm::json expected;
		expected["valid"] = true;
		expected["hex"] = list;

		Assert::That(actual, Equals(expected));
	}

	Spec(Zero){
		ucm::json actual = memRep(0);
		ucm::json list = {"00", "00", "00", "00"};
		ucm::json expected;
		expected["valid"] = true;
		expected["hex"] = list;

		Assert::That(actual, Equals(expected));
	}

	Spec(LargestInt){
		ucm::json actual = memRep(2147483647);
		ucm::json list = {"FF", "FF", "FF", "7F"};
		ucm::json expected;
		expected["valid"] = true;
		expected["hex"] = list;

		Assert::That(actual, Equals(expected));
	}
};



int main() {
	// Run all the tests defined above
	return TestRunner::RunAllTests();
}

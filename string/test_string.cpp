#include <cstdlib>
#include <cstring>

#include "test.hpp"
#include "string.hpp"

TestResult TestAssignment();
TestResult TestLength();
TestResult TestAt();
TestResult TestIsEqual();
TestResult TestConcat();
TestResult TestNotEqual();
TestResult TestEqual();

int main()
{
	RUN_TEST(TestAssignment);
	RUN_TEST(TestLength);
	RUN_TEST(TestAt);
	RUN_TEST(TestIsEqual);
	RUN_TEST(TestConcat);
	RUN_TEST(TestNotEqual);
	RUN_TEST(TestEqual);
	
	return (EXIT_SUCCESS);
}

TestResult TestAssignment()
{
	const char *str = "This is just a string!@#$^&*()_";
	String s1(str);
	String s2(s1);

	s2 = s1;
	REQUIRE(0 == strcmp(s1.c_str(), s2.c_str()));	

	s2 = s2;
	REQUIRE(0 == strcmp(s2.c_str(), s2.c_str()));	

	return (TEST_PASS);
}

TestResult TestLength()
{
	const char *longestWordInEnglish = "pneumonoultramicroscopicsilicovolcanoconiosis";
	const char *emptyString = "";
	String *string1 = new String(longestWordInEnglish);
	String *string2 = new String(emptyString);
		
	REQUIRE(45 == string1->Length());	
	REQUIRE(0 == string2->Length());	

	delete string1;
	delete string2;

	return (TEST_PASS);
}

TestResult TestAt()
{
	const char *str = "Respect";
	String s1(str);

	REQUIRE(s1[0] == 'R');
	REQUIRE(s1[1] == 'e');
	REQUIRE(s1[2] == 's');
	REQUIRE(s1[3] == 'p');
	REQUIRE(s1[4] == 'e');
	REQUIRE(s1[5] == 'c');
	REQUIRE(s1[6] == 't');

	return (TEST_PASS);
}

TestResult TestIsEqual()
{
	const char *str1 = "Shai";
	const char *str2 = "shai";

	String s1(str1);
	String s2(str2);
	String s3(str1);

	REQUIRE(s1 != s2);
	REQUIRE(s1 == s3);

	return (TEST_PASS);
}

TestResult TestConcat()
{
	const char *str1 = "a";
	const char *str2 = "b";
	const char* str3 = "ab";
	const char* result = "abab";
	String s1(str1);
	String s2(str2);
	String s3(str3);
	
	s1 += s2;
	REQUIRE(0 == strcmp(s1.c_str(), str3));

	s3 = s3 + s1;
	REQUIRE(0 == strcmp(s3.c_str(), result));

	return (TEST_PASS);
}

TestResult TestNotEqual()
{
	const char *str1 = "abc";
	const char *str2 = "abd";
	String s1(str1);
	String s2(str2);

	REQUIRE(str1 != str2);

	return (TEST_PASS);
}

TestResult TestEqual()
{
	const char *str1 = "abcd";
	const char *str2 = "abcd";
	String s1(str1);
	String s2(str2);

	REQUIRE(str1 == str2);

	return (TEST_PASS);
}
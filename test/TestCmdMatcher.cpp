/*
 * TestCmdMather.cpp
 *
 *  Created on: 2014Äê11ÔÂ15ÈÕ
 *      Author: Thoughtworks
 */
#include <gtest/gtest.h>
#include <vector>
#include <string>
#include "CmdMatcher.h"
using namespace std;

class TestCmdMatcher: public testing::Test {
public:
	void SetUp() {

	}
	void TearDown() {

	}
protected:
};

TEST_F(TestCmdMatcher, )
{
	CmdMatcher matcher;
	matcher.addCmd("fei:0");
	matcher.addCmd("fei:1");
	std::vector<string> relates;
	matcher.getRelatedStrings("fei:", relates);
	ASSERT_EQ(false, relates.empty());
	EXPECT_EQ("0",relates[0]);
	EXPECT_EQ("1",relates[1]);
}




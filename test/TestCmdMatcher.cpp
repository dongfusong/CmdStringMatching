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


TEST_F(TestCmdMatcher, can_match_nothing_if_wrong){
	CmdMatcher matcher;
	matcher.addCmd("fei:0/1/2");
	std::vector<string> relates;
	matcher.getRelatedStrings("pei", relates);
	ASSERT_EQ(0, relates.size());
	relates.clear();
	matcher.getRelatedStrings("fei:0/1/2/", relates);
	ASSERT_EQ(0, relates.size());
}

TEST_F(TestCmdMatcher, if_finish_can_match_nothing){
	CmdMatcher matcher;
	matcher.addCmd("fei:0/1/2");
	std::vector<string> relates;
	matcher.getRelatedStrings("fei:0/1/2", relates);
	ASSERT_EQ(0, relates.size());
}

TEST_F(TestCmdMatcher, return_all_opts_if_empty){
	CmdMatcher matcher;
	matcher.addCmd("fei:");
	matcher.addCmd("pei:");
	std::vector<string> relates;
	matcher.getRelatedStrings("", relates);
	ASSERT_EQ(2, relates.size());
	EXPECT_EQ("fei",relates[0]);
	EXPECT_EQ("pei",relates[1]);
}

TEST_F(TestCmdMatcher, can_match_symbol)
{
	CmdMatcher matcher;
	matcher.addCmd("fei:");
	matcher.addCmd("pei:");
	std::vector<string> relates;
	matcher.getRelatedStrings("fei", relates);
	ASSERT_EQ(1, relates.size());
	EXPECT_EQ(":",relates[0]);
}

TEST_F(TestCmdMatcher, can_match_multi_num_opts){
	CmdMatcher matcher;
	matcher.addCmd("fei:0/1-2");
	matcher.addCmd("fei:0/1-3");
	matcher.addCmd("fei:11/1/3");
	matcher.addCmd("fei:2/1/3");
	std::vector<string> relates;
	matcher.getRelatedStrings("fei:", relates);
	ASSERT_EQ(3, relates.size());
	EXPECT_EQ("0",relates[0]);
	EXPECT_EQ("11",relates[1]);
	EXPECT_EQ("2",relates[2]);
	relates.clear();
	matcher.getRelatedStrings("fei:0/1-", relates);
	ASSERT_EQ(2, relates.size());
	EXPECT_EQ("2",relates[0]);
	EXPECT_EQ("3",relates[1]);
}







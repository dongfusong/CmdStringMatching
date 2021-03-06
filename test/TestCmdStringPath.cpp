/*
 * TestStringPath.cpp
 *
 *  Created on: 2014��11��15��
 *      Author: Thoughtworks
 */

#include <gtest/gtest.h>
#include <string>
#include "CmdStringPath.h"
using namespace std;
class TestStringPath: public testing::Test {
public:
	void SetUp() {

	}
	void TearDown() {

	}
protected:
};

TEST_F(TestStringPath, test_string_path)
{
	CmdStringPath path("fei:1-2/3");
	EXPECT_EQ(0, path.parse());
	EXPECT_EQ("fei", path.getCurrentPart());
	path.next();
	EXPECT_EQ(":", path.getCurrentPart());
	path.next();
	EXPECT_EQ("1", path.getCurrentPart());
	path.next();
	EXPECT_EQ("-", path.getCurrentPart());
	EXPECT_EQ("-", path.getCurrentPart());
	path.next();
	EXPECT_EQ("2", path.getCurrentPart());
	path.next();
	EXPECT_EQ("/", path.getCurrentPart());
	path.next();
	EXPECT_EQ("3", path.getCurrentPart());
	path.next();
	EXPECT_EQ(true, path.isDone());
}



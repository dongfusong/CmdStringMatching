/*
 * TestStringPath.cpp
 *
 *  Created on: 2014��11��15��
 *      Author: Thoughtworks
 */

#include <gtest/gtest.h>
#include <string>
#include "StringPath.h"
using namespace std;
class TestStringPath: public testing::Test {
public:
	void SetUp() {

	}
	void TearDown() {

	}
protected:
};

TEST_F(TestStringPath, )
{
	StringPath path("fei:1");
	EXPECT_EQ("fei", path.getCurrentPart());
	path.next();
	EXPECT_EQ(":", path.getCurrentPart());
	path.next();
	EXPECT_EQ("1", path.getCurrentPart());
	EXPECT_EQ(true, path.isDone());
}


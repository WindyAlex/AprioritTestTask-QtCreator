#pragma once

#include <gtest/gtest.h>

#include "../Trams/filereader.h"

TEST(FileReader, OpenCloseFile)
{
    std::fstream file;
    file.open("file.in", std::ios_base::out);
    file.close();

    FileReader reader("file.in");
    reader.OpenFile();
    reader.CloseFile();

    EXPECT_TRUE(true);
}

TEST(FileReader, ParseFile)
{
    std::fstream file;
    file.open("file.in", std::ios_base::out);
    file << "1 7 3 1 1 2 1 2 4 1 3 5";
    file.close();

    FileReader reader("file.in");
    reader.OpenFile();
    int res = reader.ParseFile();
    reader.CloseFile();

    EXPECT_EQ(res, 2);
}

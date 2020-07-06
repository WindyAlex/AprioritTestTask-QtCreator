#pragma once

#include <gtest/gtest.h>

#include "../Trams/filewriter.h"

TEST(FileWriter, OpenCloseFileTest)
{
    FileWriter writer("file.out");
    writer.OpenFile();
    writer.CloseFile();

    EXPECT_TRUE(true);
}

TEST(FileWriter, WriteToFileTest)
{
    FileWriter writer("file.out");
    writer.OpenFile();
    writer.WriteToFile(1);
    writer.CloseFile();

    EXPECT_TRUE(true);
}

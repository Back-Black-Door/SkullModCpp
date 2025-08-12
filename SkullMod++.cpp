// SkullMod++.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <Windows.h>
#include <string.h>
#include <string>
#include "gfs.h"
#include <filesystem>

//-----------------------

namespace fs = std::filesystem;

int main(int argc, char* argv[])
{
    std::cout << R"(
   _____ _          _ _ __  __           _  _____           
  / ____| |        | | |  \/  |         | |/ ____|_     _   
 | (___ | | ___   _| | | \  / | ___   __| | |   _| |_ _| |_ 
  \___ \| |/ / | | | | | |\/| |/ _ \ / _` | |  |_   _|_   _|
  ____) |   <| |_| | | | |  | | (_) | (_| | |____|_|   |_|  
 |_____/|_|\_\\__,_|_|_|_|  |_|\___/ \__,_|\_____|                                                                                             
)" << std::endl;

    std::cout << "Version: 0.5" << "\n";
    std::cout << "Original program made by 0xFAIL" << "\n";
    std::cout << "The C++ version is made by ImpDi" << "\n";
    std::cout << '\n';
    if (argc == 1) {
        std::cout << "There are no files" << '\n';
        system("pause");
        return 0;
    }
    GFSUnpacker GFSUnpack;
    GFSPacker GFSpack;
    for (int i{ 1 }; i < argc; i++) {
        std::filesystem::path fileread = argv[i];
        std::cout << "File Read Path:" << fileread << '\n';
        //GFS gfs(fileread);

        if (fileread.extension() == "") {
            std::cout << "File Write Path:" << fileread.replace_extension(".gfs") << '\n';
            GFSpack(fileread);
        }
        else {
            std::cout << "File Write Path:" << fileread.replace_extension("") << '\n';
            GFSUnpack(fileread);
        }
    } //for
} //main


#pragma once

#define EXPORT __declspec(dllexport)

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include "constants.h"

extern "C" EXPORT bool checkLengthOfKeyword(char* key);
extern "C" EXPORT bool checkCharactersInKeyword(char* key);
extern "C" EXPORT bool checkDuplicatesInKeyword(char* key);
extern "C" EXPORT std::string removeDuplicates(char* key);
//extern "C" EXPORT std::string checkValidityOfKeyword(char* key);
extern "C" EXPORT bool checkValidityOfKeyword(char* key);
extern "C" EXPORT void createPolybiusSquare(char** square, char* key);
extern "C" EXPORT bool checkCharactersInText(char* text);
extern "C" EXPORT std::string encryptText(char** square, char* text, int width, int height);
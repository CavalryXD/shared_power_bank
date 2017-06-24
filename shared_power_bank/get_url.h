#pragma once
#pragma comment(lib, "ws2_32.lib")
#pragma warning(disable:4996)
#include<WINSOCK2.H>  
#include<STDIO.H>  
#include <string>
#include "reader.h"
#include "value.h"
#include <iostream>
using namespace std;

class GetUrl {
public:
	static Json::Value Get(const string url);
};
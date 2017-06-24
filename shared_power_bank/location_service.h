#pragma once
#include <iostream>
#include "get_url.h"
using namespace std;
class LocService
{
public:
	LocService() = default;
	static pair<float, float> GetLocation();  //¾­Î³¶È
	//return a vector that include coordinate pair like (lng, lat)
};


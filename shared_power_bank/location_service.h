#pragma once
#include <iostream>
using namespace std;
class LocService
{
public:
	LocService() = default;
	static string GetCity();  //return your city
	static pair<float, float> GetLocation();  //return a vector that include coordinate pair like (lng, lat)
	static string loc_api_url;
};

string LocService::loc_api_url = "http://restapi.amap.com/v3/ip?key=52f41ecb8481df329c89b0e2cfbaf0c4";
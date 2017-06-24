#pragma once
#include "pow_bank_dep.h"
#include <vector>
using namespace std;
class DepositoryMng
{
public:
	static void GetNeighborDep(pair<float, float> coordinate,string name);  // 返回附近的存放机，  参数为用户坐标
	static int GetChkCode(PowBankDepository selected_dep);  // 用户以选择的存放机为参数得到验证码
};
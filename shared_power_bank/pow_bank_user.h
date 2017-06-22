#pragma once
#include <string>
#include "pow_bank.h"
#include "pow_bank_dep.h"

using namespace std;

class PowBankUser{
public:
	PowBankUser():user_pow(nullptr),chosen_dep(nullptr){}
	void GetInfo(string,string);		//从数据库获取用户信息
	void GetLocation();					//得到当前位置
	void ChoosePowDep();				//选择存放机
	void GetChkCode();					//从存放机管理系统得到验证码
	int ShowChkCode();					//返回验证码给借出存放机
	void BorrowPow();					//从存放机借一个充电宝
	void ReturnPow();					//归还充电宝
	void CreateOrderform();				//形成订单
	void CalculateCost();				//计算费用

private:
	string user_name;
	string user_phone_number;
	pair<float, float> current_location;
	int chk_code;						//用户得到的验证码
	float balance;						//用户余额
	//bool get_pow;						//判断用户是否借了充电宝
	int pow_deposit_number;				//用户选择的存放机
	PowBank *user_pow;					//用户所借的充电宝
	PowBankDepository *chosen_dep;		//用户所选择的存放机
};
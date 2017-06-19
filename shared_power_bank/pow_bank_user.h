#pragma once
#include <string>
#include "pow_bank.h"
#include "pow_bank_dep.h"

using namespace std;

class PowUser {
public:
	PowUser() = default;
	void get_info(string s);		//从数据库获取用户信息
	void create_order();		//形成订单
	void get_location();		//得到当前位置

private:
	string user_name;
	string user_phone_number;
	pair<float, float> current_location;
	string chk_code;     //用户得到的验证码
	float balance;		//用户余额
	//bool get_pow;		//判断用户是否借了充电宝
	int pow_deposit_number;		//用户选择的存放机
	PowBank user_pow;		//用户的
	PowBankDepositry chosen_dep;	//用户所选择的存放机
};
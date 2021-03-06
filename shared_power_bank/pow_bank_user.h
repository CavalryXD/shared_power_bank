#pragma once
#include <string>
#include "pow_bank_dep.h"

using namespace std;

class PowBankUser{
public:
	PowBankUser():user_pow(nullptr),chosen_dep(nullptr),get_pow(false), user_name(" "), user_email(" "), password(" "){}
	bool SignUp();									//用户注册	
	bool SignIn();									//用户登录
	void GetInfo(string,string,string);				//从数据库获取用户信息
	void ShowInfo();								//显示的用户个人信息
	void GetLocation();								//得到当前位置
	void GetMoney(float);							//getmoney
	void ShowMoney();								//显示当前余额
	bool ReCharge();								//充钱
	void ChoosePowDep();							//选择存放机
	void GetChkCode();								//从存放机管理系统得到验证码
	string ShowChkCode();							//返回验证码给借出存放机
	bool BorrowPow();								//从存放机借一个充电宝
	bool IfGetPow();								//判断用户是否借了充电宝
	bool IfReturn();								//判断用户是否归还充电宝
	bool IfGetPowDep();								//判断用户是否选择了存放及
	void ReturnPow();								//归还充电宝
	float CalculateCost(time_t t1,time_t t2);		//计算费用
	void PayCost(float);									//从数据库中扣除费用
private:
	string user_name;
	string user_email;
	string password;
	int times;										//借还次数
	pair<float, float> current_location;			//当前位置
	string chk_code;								//用户得到的验证码
	float balance;									//用户余额
	bool get_pow;									//判断用户是否借了充电宝
	string pow_deposit_number;						//用户选择的存放机
	PowBank *user_pow;								//用户所借的充电宝
	PowBankDepository *chosen_dep;					//用户所选择的存放机
};
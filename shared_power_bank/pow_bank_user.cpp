#include <iostream>
#include <string>
#include <vector>
#include "pow_bank_user.h"
#include "location_service.h"
#include "dep_manager.h"
#include <iomanip>
using namespace std;
bool PowBankUser::SignUp() {				//注册
	cout << "请输入您的名字，email和密码，中间用回车分隔" << endl;
	cout << "请输入您的名字：";
	cin >> user_name;
	cout << "请输入您的email：";
	cin >> user_email;
	cout << "请输入您的密码：" ;
	cin >> password;
	//get请求
	string s = "GET /user/register?username=" + user_name + "&passwd=" + password +"&email="+ user_email+" HTTP/1.1\nHost:192.168.31.97:5000\n\n";
	Json::Value value = GetUrl::Get(s);
	if (value["status"].asString() == "200")
	{
		return true;
	}
	if (value["status"].asString() == "404")
		return false;
	return false;
}
bool PowBankUser::SignIn() {			//登陆
	string name;
	string word;
	//get请求
	cout << "请输入您的名字和密码，中间用回车分隔" << endl;
	cout << "请输入您的名字：";
	cin >> name;
	cout << "请输入您的密码：" ;
	cin >> word;
	string s = "GET /user/login?username=" + name + "&passwd=" + word + " HTTP/1.1\nHost:192.168.31.97:5000\n\n";
	Json::Value value = GetUrl::Get(s);
	if (value["status"].asString() == "200")
	{
		user_name = name;
		password = word;
		balance = value["message"]["balance"].asFloat();
		user_email= value["message"]["email"].asString();
		return true;
	}
	else
		return false;
}
void PowBankUser::GetInfo(string name, string phone_number,string user_password) {
	//todo 链接网络
	user_name = name;
	password = user_password;
	user_email = phone_number;
}
void PowBankUser::ShowInfo() {
	cout << "您的姓名为:      " << user_name << endl;
	cout << "您的email为:     " << user_email << endl;
	cout << endl;
}
void PowBankUser::GetLocation() {
	current_location = LocService::GetLocation();
}
void PowBankUser::GetMoney(float t) {
	
	balance = t;
}
void PowBankUser::ShowMoney() {
	cout << "您当前的余额为：" ;
	string s = "GET /user/login?username=" + user_name + "&passwd=" + password + " HTTP/1.1\nHost:192.168.31.97:5000\n\n";
	Json::Value value = GetUrl::Get(s);
	balance = value["message"]["balance"].asFloat();
	cout << balance << endl;
	cout << endl;
}
bool PowBankUser::ReCharge(){
	charge:
	float money;
	cout << "欢迎来到充值界面，请输入您要充值的金额" << endl;
	if (!(cin >> money) && money < 0) {
		cout << "您输入的有误,需要重新输入吗？ 0 or 1" << endl;
		int code=0;
		if ((!cin >> code) &&code != 1)
			return false;
		else
			goto charge;
	}
	else {
		string s = "GET /user/charge?username=" + user_name + "&passwd=" + password + "&money="+to_string(money)+" HTTP/1.1\nHost:192.168.31.97:5000\n\n";
		Json::Value value = GetUrl::Get(s);
		cout << "恭喜您，充值成功！" << endl;
		return true;
	}
}
void PowBankUser::ChoosePowDep() {
	cout << "以下是您周围的充电宝存放点" << endl;
	string s = "GET /depositories?username=" + user_name+ " HTTP/1.1\nHost:192.168.31.97:5000\n\n";
	Json::Value value = GetUrl::Get(s);
	if (value["status"] == "404")
		cout << "查询失败" << endl;
	else
		for (int i = 0; i < value["message"].size(); ++i) {
			cout <<"存放机编号："<< setw(2)<<value["message"][i]["id"].asString()<<"号    "<<"存放机位置："<< setw(10)<<value["message"][i]["location"].asString()<< "        经度：" <<setw(-5)<< (value["message"][i]["coordinate"]["lng"].asString()).substr(0,5) << "  纬度：" <<setw(-4)<< (value["message"][i]["coordinate"]["lat"].asString()).substr(0,4) << endl;
		}
	cout << "请输入您想选择的存放机的编号" << endl;
	string number;
	cin >> number;						//存放机编号
	pow_deposit_number = number;		//用户所选择的存放机编号
}
void PowBankUser::GetChkCode() {
	string s = "GET /depositories/checkcode?username=" + user_name+"&id=" + pow_deposit_number+ " HTTP/1.1\nHost:192.168.31.97:5000\n\n";
	Json::Value value= GetUrl::Get(s);
	chk_code = value["message"]["chkcode"].asString();
}
string PowBankUser::ShowChkCode() {
	cout << "您的验证码是："<< chk_code << endl;
	cout << endl;
	return chk_code;
}
bool PowBankUser::BorrowPow() {
	if (balance == 0) {
		cout << "您当前余额不足，请先充值 0 or 1" << endl;
		int code = 0;
		if ((cin >> code) && code != 1)
			return false;
		else
		{
			bool chargeornot = ReCharge();
			if (chargeornot)
				return true;
			else
				return false;
		}
	}
	if (times ==1) {
		cout << "您已经借了一个充电宝了，无法继续借出！" << endl;
		return false;
	}
	int opt;
	reborrow:
	string code;
	cout << "验证码以显示在存放机上，请在当前界面输入验证码" << endl;
	cin >> code;
	string s = "GET /depositories/check?chkcode=" + code + "&id=" + pow_deposit_number + " HTTP/1.1\nHost:192.168.31.97:5000\n\n";
	Json::Value value = GetUrl::Get(s);
	string status = value["status"].asString();
	if (status == "200") {
		cout << "您已成功借出充电宝，请尽快取出！" << endl;
		chk_code = code;
		times = 1;
		get_pow= true;
		return true;
	}
	else {
		cout << "您输入的验证码有误 需要重新输入吗？ 0 or 1" << endl;
		if (cin >> opt&&opt != 1)
			return false;
		else
			goto reborrow;
	}	
}
bool PowBankUser::IfGetPow() {
	return get_pow;
}
bool PowBankUser::IfReturn() {
	return times==2;
}
bool  PowBankUser::IfGetPowDep(){
	return chosen_dep != nullptr;
}
void PowBankUser::ReturnPow() {
	times=2;
	get_pow = false;
	user_pow = nullptr;
}

float PowBankUser::CalculateCost(time_t t1,time_t t2) {
	string s = "GET /user/pay?username=" + user_name+"&passwd="+password+"&payment="+ to_string((t2 - t1)*0.01)+ " HTTP/1.1\nHost:192.168.31.97:5000\n\n";
	Json::Value value = GetUrl::Get(s);
	balance -= (t2 - t1)*0.01;				//计算剩下余额
	return (t2-t1)*0.01;
}
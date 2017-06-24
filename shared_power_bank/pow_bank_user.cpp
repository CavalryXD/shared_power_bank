#include <iostream>
#include <string>
#include <vector>
#include "pow_bank_user.h"
#include "location_service.h"
#include "dep_manager.h"

using namespace std;
bool PowBankUser::SignUp() {
	cout << "请输入您的名字，电话号码和密码，中间用回车分隔" << endl;
	cout << "请输入您的名字：";
	cin >> user_name;
	cout << "请输入您的电话号码：";
	cin >> user_phone_number;
	cout << "请输入您的密码：";
	cin >> password;
	//get请求
	string s = "GET /user/register?username=" + user_name + "&passwd=" + password + " HTTP/1.1\nHost:192.168.31.97:5000\n\n";
	Json::Value value = GetUrl::Get(s);
	if (value["status"].asString() == "200")
		return true;
	if (value["status"].asString() == "404")
		return false;
	return false;
}
bool PowBankUser::SignIn() {
	string name;
	string word;
	//get请求
	cout << "请输入您的名字和密码，中间用回车分隔" << endl;
	cout << "请输入您的名字：";
	cin >> name;
	cout << "请输入您的密码：";
	cin >> word;
	string s = "GET /user/login?username=" + name + "&passwd=" + word + " HTTP/1.1\nHost:192.168.31.97:5000\n\n";
	Json::Value value = GetUrl::Get(s);
	if (value["status"].asString()=="200")
		return true;
	else
		return false;
}
void PowBankUser::GetInfo(string name, string phone_number,string user_password) {
	user_name = name;
	password = user_password;
	user_phone_number = phone_number;
}
void PowBankUser::ShowInfo() {
	cout << "您的姓名为" << user_name << endl;
	cout << "您的电话号码为" << user_phone_number << endl;
}
void PowBankUser::GetLocation() {
	current_location = LocService::GetLocation();
}
void PowBankUser::GetMoney(float t) {
	balance = t;
}
void PowBankUser::ShowMoney() {
	cout << "您当前的余额为：" << balance << endl;
}
void PowBankUser::ChoosePowDep() {
	cout << "以下是您周围的充电宝存放点" << endl;
	string s = "GET /depositories?username=" + user_name+ " HTTP/1.1\nHost:192.168.31.97:5000\n\n";
	Json::Value value = GetUrl::Get(s);
	if (value["status"] == "404")
		cout << "查询失败" << endl;
	else
		for (int i = 0; i < value["message"].size(); ++i) {
			cout <<"您当前的位置处于：			"<< value["message"][i]["location"].asString()<< "经度：" << value["message"][i]["coordinate"]["lng"].asString() << "纬度：" << value["message"][i]["coordinate"]["lat"].asString() << endl;
		}
	cout << "请输入您想选择的存放机的编号" << endl;
	int number;
	cin >> number;						//存放机编号
	pow_deposit_number = number;		//用户所选择的存放机编号
}
void PowBankUser::GetChkCode() {
	string s = "GET /depositories/checkcode/?username=" + user_name+"&id=" + "pow_deposit_number"+ " HTTP/1.1\nHost:192.168.31.97:5000\n\n";
	Json::Value value= GetUrl::Get(s);
	chk_code = value["message"]["chkcode"].asString();
}
string PowBankUser::ShowChkCode() {
	cout << "您的验证码是："<< chk_code << endl;
	return chk_code;
}
void PowBankUser::BorrowPow() {
	/*user_pow = chosen_dep->LendPowBank(chk_code);

	while (user_pow == nullptr) {
		cout << "您输入的验证码不正确";
		cout << "是否要重新输入? 0 or 1" << endl;
		string judge;
		cin >> judge;
		if (judge == "yes") {

		}
		else
			break;
	}
	times++;
	get_pow = true;
	*/
}
bool PowBankUser::IfGetPow() {
	return get_pow;
}
bool PowBankUser::IfReturn() {
	return times>=2;
}
bool  PowBankUser::IfGetPowDep(){
	return chosen_dep != nullptr;
}
void PowBankUser::ReturnPow() {
	times++;
	get_pow = false;
	user_pow = nullptr;
}

float PowBankUser::CalculateCost(time_t t1,time_t t2) {
	string s = "GET /user/pay?username=" + user_name+"&password="+password+"&payment="+ "(t2 - t1)*0.01"+ " HTTP/1.1\nHost:192.168.31.97:5000\n\n";
	Json::Value value = GetUrl::Get(s);
	balance -= (t2 - t1)*0.01;				//计算剩下余额
	return (t2-t1)*0.01;
}
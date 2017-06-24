#include <iostream>
#include <string>
#include <vector>
#include "pow_bank_user.h"
#include "location_service.h"
#include "dep_manager.h"

using namespace std;
bool PowBankUser::SignUp() {
	int code;
	cout << "请输入您的名字，电话号码和密码，中间用回车分隔" << endl;
	cout << "请输入您的名字：";
	cin >> user_name;
	cout << "请输入您的电话号码：";
	cin >> user_phone_number;
	cout << "请输入您的密码：";
	cin >> password;
	/*get给数据库发送信息核对信息
	if (xxx)  {
	return true;
	}
	if (!xxx) {
	return false;
	}
	*/
	return true;
	return false;
}
bool PowBankUser::SignIn() {
	string name;
	string word;
	//get请求
	return true;
	if (name == user_name&&word == password)
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
	vector<PowBankDepository*> vec=DepositoryMng::GetNeighborDep(current_location);
	cout << "以下是您周围的充电宝存放点" << endl;
	//输出周围的充电宝
//	for (auto p : vec) {
//		cout << p.dep_idf() << " " << dep_loc_name() << " "
//			<< coordinate().first << "," << coordinate().second << endl;
//	}
	cout << "请输入您想选择的存放机的编号" << endl;
	int number;
	cin >> number;						//存放机编号
//	chosen_dep = vec[number - 1];		//暂定选择存放机的方法
}
void PowBankUser::GetChkCode() {
	chk_code = DepositoryMng::GetChkCode(*chosen_dep);
}
int PowBankUser::ShowChkCode() {
	cout << "您的验证码是："<< chk_code << endl;
	return chk_code;
}
void PowBankUser::BorrowPow() {
//	user_pow = chosen_dep->LendPowBank(chk_code);
	/*while (user_pow == nullptr) {
		cout << "您输入的验证码不正确";
		cout << "是否要重新输入? 0 or 1" << endl;
		string judge;
		cin >> judge;
		if (judge == "yes") {

		}
		else
			break;
	}*/
	times++;
	get_pow = true;

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
	CreateOrderform();
}

void PowBankUser::CreateOrderform() {

}
float PowBankUser::CalculateCost(time_t t1,time_t t2) {
	return (t2-t1)*0.01;
}
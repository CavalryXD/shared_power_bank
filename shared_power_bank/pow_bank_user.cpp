#include <iostream>
#include <string>
#include <vector>
#include "pow_bank_user.h"
#include "location_service.h"
#include "dep_manager.h"

using namespace std;
bool PowBankUser::SignUp() {
	cout << "�������������֣��绰��������룬�м��ûس��ָ�" << endl;
	cout << "�������������֣�";
	cin >> user_name;
	cout << "���������ĵ绰���룺";
	cin >> user_phone_number;
	cout << "�������������룺";
	cin >> password;
	//get����
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
	//get����
	cout << "�������������ֺ����룬�м��ûس��ָ�" << endl;
	cout << "�������������֣�";
	cin >> name;
	cout << "�������������룺";
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
	cout << "��������Ϊ" << user_name << endl;
	cout << "���ĵ绰����Ϊ" << user_phone_number << endl;
}
void PowBankUser::GetLocation() {
	current_location = LocService::GetLocation();
}
void PowBankUser::GetMoney(float t) {
	balance = t;
}
void PowBankUser::ShowMoney() {
	cout << "����ǰ�����Ϊ��" << balance << endl;
}
void PowBankUser::ChoosePowDep() {
	cout << "����������Χ�ĳ�籦��ŵ�" << endl;
	string s = "GET /depositories?username=" + user_name+ " HTTP/1.1\nHost:192.168.31.97:5000\n\n";
	Json::Value value = GetUrl::Get(s);
	if (value["status"] == "404")
		cout << "��ѯʧ��" << endl;
	else
		for (int i = 0; i < value["message"].size(); ++i) {
			cout <<"����ǰ��λ�ô��ڣ�			"<< value["message"][i]["location"].asString()<< "���ȣ�" << value["message"][i]["coordinate"]["lng"].asString() << "γ�ȣ�" << value["message"][i]["coordinate"]["lat"].asString() << endl;
		}
	cout << "����������ѡ��Ĵ�Ż��ı��" << endl;
	int number;
	cin >> number;						//��Ż����
	pow_deposit_number = number;		//�û���ѡ��Ĵ�Ż����
}
void PowBankUser::GetChkCode() {
	string s = "GET /depositories/checkcode/?username=" + user_name+"&id=" + "pow_deposit_number"+ " HTTP/1.1\nHost:192.168.31.97:5000\n\n";
	Json::Value value= GetUrl::Get(s);
	chk_code = value["message"]["chkcode"].asString();
}
string PowBankUser::ShowChkCode() {
	cout << "������֤���ǣ�"<< chk_code << endl;
	return chk_code;
}
void PowBankUser::BorrowPow() {
	/*user_pow = chosen_dep->LendPowBank(chk_code);

	while (user_pow == nullptr) {
		cout << "���������֤�벻��ȷ";
		cout << "�Ƿ�Ҫ��������? 0 or 1" << endl;
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
	balance -= (t2 - t1)*0.01;				//����ʣ�����
	return (t2-t1)*0.01;
}
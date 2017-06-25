#include <iostream>
#include <string>
#include <vector>
#include "pow_bank_user.h"
#include "location_service.h"
#include "dep_manager.h"
#include <iomanip>
using namespace std;
bool PowBankUser::SignUp() {				//ע��
	cout << "�������������֣�email�����룬�м��ûس��ָ�" << endl;
	cout << "�������������֣�";
	cin >> user_name;
	cout << "����������email��";
	cin >> user_email;
	cout << "�������������룺" ;
	cin >> password;
	//get����
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
bool PowBankUser::SignIn() {			//��½
	string name;
	string word;
	//get����
	cout << "�������������ֺ����룬�м��ûس��ָ�" << endl;
	cout << "�������������֣�";
	cin >> name;
	cout << "�������������룺" ;
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
	//todo ��������
	user_name = name;
	password = user_password;
	user_email = phone_number;
}
void PowBankUser::ShowInfo() {
	cout << "��������Ϊ:      " << user_name << endl;
	cout << "����emailΪ:     " << user_email << endl;
	cout << endl;
}
void PowBankUser::GetLocation() {
	current_location = LocService::GetLocation();
}
void PowBankUser::GetMoney(float t) {
	
	balance = t;
}
void PowBankUser::ShowMoney() {
	cout << "����ǰ�����Ϊ��" << balance << endl;
	cout << endl;
}
void PowBankUser::ChoosePowDep() {
	cout << "����������Χ�ĳ�籦��ŵ�" << endl;
	string s = "GET /depositories?username=" + user_name+ " HTTP/1.1\nHost:192.168.31.97:5000\n\n";
	Json::Value value = GetUrl::Get(s);
	if (value["status"] == "404")
		cout << "��ѯʧ��" << endl;
	else
		for (int i = 0; i < value["message"].size(); ++i) {
			cout <<"��Ż���ţ�"<< setw(2)<<value["message"][i]["id"].asString()<<"��    "<<"��Ż�λ�ã�"<< setw(10)<<value["message"][i]["location"].asString()<< "        ���ȣ�" <<setw(-5)<< (value["message"][i]["coordinate"]["lng"].asString()).substr(0,5) << "  γ�ȣ�" <<setw(-4)<< (value["message"][i]["coordinate"]["lat"].asString()).substr(0,4) << endl;
		}
	cout << "����������ѡ��Ĵ�Ż��ı��" << endl;
	string number;
	cin >> number;						//��Ż����
	pow_deposit_number = number;		//�û���ѡ��Ĵ�Ż����
}
void PowBankUser::GetChkCode() {
	string s = "GET /depositories/checkcode?username=" + user_name+"&id=" + pow_deposit_number+ " HTTP/1.1\nHost:192.168.31.97:5000\n\n";
	Json::Value value= GetUrl::Get(s);
	chk_code = value["message"]["chkcode"].asString();
}
string PowBankUser::ShowChkCode() {
	cout << "������֤���ǣ�"<< chk_code << endl;
	cout << endl;
	return chk_code;
}
bool PowBankUser::BorrowPow() {
	if (times ==1) {
		cout << "���Ѿ�����һ����籦�ˣ��޷����������" << endl;
		return false;
	}
	int opt;
	reborrow:
	string code;
	cout << "��֤������ʾ�ڴ�Ż��ϣ����ڵ�ǰ����������֤��" << endl;
	cin >> code;
	string s = "GET /depositories/check?chkcode=" + code + "&id=" + pow_deposit_number + " HTTP/1.1\nHost:192.168.31.97:5000\n\n";
	Json::Value value = GetUrl::Get(s);
	string status = value["status"].asString();
	if (status == "200") {
		cout << "���ѳɹ������籦���뾡��ȡ����" << endl;
		chk_code = code;
		times = 1;
		get_pow= true;
		return true;
	}
	else {
		cout << "���������֤������ ��Ҫ���������� 0 or 1" << endl;
		cin >> opt;
		if (opt != 1)
			return false;
		if (opt == 1)
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
	string s = "GET /user/pay?username=" + user_name+"&password="+password+"&payment="+ "(t2 - t1)*0.01"+ " HTTP/1.1\nHost:192.168.31.97:5000\n\n";
	Json::Value value = GetUrl::Get(s);
	balance -= (t2 - t1)*0.01;				//����ʣ�����
	return (t2-t1)*0.01;
}
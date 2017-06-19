#pragma once
#include <string>
#include "pow_bank.h"
#include "pow_bank_dep.h"

using namespace std;

class PowUser {
public:
	PowUser() = default;
	void get_info(string s);		//�����ݿ��ȡ�û���Ϣ
	void create_order();		//�γɶ���
	void get_location();		//�õ���ǰλ��

private:
	string user_name;
	string user_phone_number;
	pair<float, float> current_location;
	string chk_code;     //�û��õ�����֤��
	float balance;		//�û����
	//bool get_pow;		//�ж��û��Ƿ���˳�籦
	int pow_deposit_number;		//�û�ѡ��Ĵ�Ż�
	PowBank user_pow;		//�û���
	PowBankDepositry chosen_dep;	//�û���ѡ��Ĵ�Ż�
};
#pragma once
#include <string>
#include "pow_bank.h"
#include "pow_bank_dep.h"

using namespace std;

class PowUser {
public:
	PowUser() = default;
	void get_info(string s);			//�����ݿ��ȡ�û���Ϣ
	void create_order();				//�γɶ���
	void get_location();				//�õ���ǰλ��
	void choose_pow_dep();				//ѡ���Ż�
	void get_chk_code();				//�Ӵ�Ż�����ϵͳ�õ���֤��
	int show_chk_code();				//������֤��������Ż�


private:
	string user_name;
	string user_phone_number;
	pair<float, float> current_location;
	int chk_code;						//�û��õ�����֤��
	float balance;						//�û����
	//bool get_pow;						//�ж��û��Ƿ���˳�籦
	int pow_deposit_number;				//�û�ѡ��Ĵ�Ż�
	PowBank user_pow;					//�û�����ĳ�籦
	PowBankDepository chosen_dep;		//�û���ѡ��Ĵ�Ż�
};
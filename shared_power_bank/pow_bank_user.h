#pragma once
#include <string>
#include "pow_bank.h"
#include "pow_bank_dep.h"

using namespace std;

class PowBankUser{
public:
	PowBankUser():user_pow(nullptr),chosen_dep(nullptr){}
	void GetInfo(string,string);		//�����ݿ��ȡ�û���Ϣ
	void GetLocation();					//�õ���ǰλ��
	void ChoosePowDep();				//ѡ���Ż�
	void GetChkCode();					//�Ӵ�Ż�����ϵͳ�õ���֤��
	int ShowChkCode();					//������֤��������Ż�
	void BorrowPow();					//�Ӵ�Ż���һ����籦
	void ReturnPow();					//�黹��籦
	void CreateOrderform();				//�γɶ���
	void CalculateCost();				//�������

private:
	string user_name;
	string user_phone_number;
	pair<float, float> current_location;
	int chk_code;						//�û��õ�����֤��
	float balance;						//�û����
	//bool get_pow;						//�ж��û��Ƿ���˳�籦
	int pow_deposit_number;				//�û�ѡ��Ĵ�Ż�
	PowBank *user_pow;					//�û�����ĳ�籦
	PowBankDepository *chosen_dep;		//�û���ѡ��Ĵ�Ż�
};
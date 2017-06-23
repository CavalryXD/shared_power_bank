#pragma once
#include <string>
#include "pow_bank_dep.h"

using namespace std;

class PowBankUser{
public:
	PowBankUser():user_pow(nullptr),chosen_dep(nullptr),get_pow(false), user_name(" "), user_phone_number(" "), password(" "){}
	bool SignUp();						//�û�ע��	
	bool SignIn();						//�û���¼
	void GetInfo(string,string,string);	//�����ݿ��ȡ�û���Ϣ
	void ShowInfo();					//��ʾ���û�������Ϣ
	void GetLocation();					//�õ���ǰλ��
	void GetMoney(float);				//getmoney
	void ShowMoney();					//��ʾ��ǰ���
	void ChoosePowDep();				//ѡ���Ż�
	void GetChkCode();					//�Ӵ�Ż�����ϵͳ�õ���֤��
	int ShowChkCode();					//������֤��������Ż�
	void BorrowPow();					//�Ӵ�Ż���һ����籦
	bool IfGetPow();					//�ж��û��Ƿ���˳�籦
	bool IfGetPowDep();					//�ж��û��Ƿ�ѡ���˴�ż�
	void ReturnPow();					//�黹��籦
	void CreateOrderform();				//�γɶ���
	float CalculateCost();				//�������

private:
	string user_name;
	string user_phone_number;
	string password;
	pair<float, float> current_location;
	int chk_code;						//�û��õ�����֤��
	float balance;						//�û����
	bool get_pow;						//�ж��û��Ƿ���˳�籦
	int pow_deposit_number;				//�û�ѡ��Ĵ�Ż�
	PowBank *user_pow;					//�û�����ĳ�籦
	PowBankDepository *chosen_dep;		//�û���ѡ��Ĵ�Ż�
};
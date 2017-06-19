#pragma once
#include <set>
#include "pow_bank.h"
using namespace std;
class PowBankDepository // ��Ż���
{
private:
	int dep_idf;   //��Ż���ʶ��
	string dep_loc_name; // ��Ż�λ������ �磺 Сƻ���̵���
	pair<float, float> coordinate; // ��Ż�����
	int pow_bank_num; // ��籦����
	set<int> chk_codes; //��֤��
	set<PowBank&> depoitry; // ��籦����
public:
	PowBankDepository() = default;
	PowBankDepository(int dep_idf, string dep_loc_name, pair<float,float> coordinate, int pow_bank_num,
		set<int>chk_codes, set<PowBank&> dep);
	bool UpdateCheckCode(int new_check_code); 
	//bool IdfCheckCode(int ck);
	PowBank& LendPowBank(int ck); // �����籦�� ����Ϊ�û��õ�����֤�� 
	void ReturnPowBank(PowBank&); // �黹��籦
};
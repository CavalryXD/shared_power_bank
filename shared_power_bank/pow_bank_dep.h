#pragma once
#include <set>
#include "pow_bank.h"
using namespace std;
class PowBankDepository // ��Ż���
{
private:
	int _dep_idf;   //��Ż���ʶ��
	string _dep_loc_name; // ��Ż�λ������ �磺 Сƻ���̵���
	pair<float, float> _coordinate; // ��Ż�����
	int _pow_bank_num; // ��籦����
	set<int> _chk_codes; //��֤��
	vector<PowBank&> _depoitory; // ��籦����
public:
	int dep_idf()
	{
		return _dep_idf;
	}
	string dep_loc_name()
	{
		return _dep_loc_name;
	}
	pair<float, float> coordinate()
	{
		return _coordinate;
	}
	PowBankDepository() = default;
	PowBankDepository(int dep_idf, string dep_loc_name, pair<float,float> coordinate, int pow_bank_num,
		vector<int>chk_codes, vector<PowBank&> dep);
	bool UpdateCheckCode(int new_check_code); 
	//bool IdfCheckCode(int ck); 
	PowBank& LendPowBank(int chk); // �����籦������Ϊ�û��õ�����֤�� 
	void ReturnPowBank(PowBank&); // �黹��籦
	void ChargePowBank(PowBank&); // Ϊ��籦���
};
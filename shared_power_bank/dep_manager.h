#pragma once
#include "pow_bank_dep.h"
#include <set>
using namespace std;
class DepositoryMng
{
public:
	set<PowBankDepository&> GetNeighborDep(pair<float, float> coordinate); // ���ظ����Ĵ�Ż���  ����Ϊ�û�����
	int GetChkCode(PowBankDepository& selected_dep); // �û���ѡ��Ĵ�Ż�Ϊ�����õ���֤��
};
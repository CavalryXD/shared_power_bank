#pragma once
#include "pow_bank_dep.h"
#include <vector>
using namespace std;
class DepositoryMng
{
public:
	static vector<PowBankDepository*> GetNeighborDep(pair<float, float> coordinate);  // ���ظ����Ĵ�Ż���  ����Ϊ�û�����
	static int GetChkCode(PowBankDepository selected_dep);  // �û���ѡ��Ĵ�Ż�Ϊ�����õ���֤��
};
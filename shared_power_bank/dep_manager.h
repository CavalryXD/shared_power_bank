#pragma once
#include "pow_bank_dep.h"
#include <vector>
using namespace std;
class DepositoryMng
{
public:
	static void GetNeighborDep(pair<float, float> coordinate,string name);  // ���ظ����Ĵ�Ż���  ����Ϊ�û�����
	static int GetChkCode(PowBankDepository selected_dep);  // �û���ѡ��Ĵ�Ż�Ϊ�����õ���֤��
};
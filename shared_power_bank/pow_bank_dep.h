#pragma once
#include <vector>
#include "pow_bank.h"
using namespace std;
class PowBankDepository  // 存放机类
{
private:
	int dep_idf;		 //存放机标识符
	string dep_loc_name; // 存放机位置名， 如： 小苹果商店旁
	pair<float, float> coordinate; // 存放机坐标
	int pow_bank_num; // 充电宝数量
	vector<int> chk_codes; //验证码
	vector<PowBank&> depoitry; // 充电宝集合
public:
	PowBankDepository() = default;
	PowBankDepository(int dep_idf, string dep_loc_name, pair<float,float> coordinate, int pow_bank_num,
		vector<int>chk_codes, vector<PowBank&> dep);
	bool UpdateCheckCode(int new_check_code);
	//bool IdfCheckCode(int ck);
	PowBank& LendPowBank(int ck); // 借出充电宝， 参数为用户得到的验证码 
	void ReturnPowBank(PowBank&); // 归还充电宝
};
#pragma once
#include "pow_bank.h"
#include <vector>
using namespace std;
class PowBankDepository					// 存放机类
{
private:
	int _dep_idf;						//存放机标识符
	string _dep_loc_name;				// 存放机位置名， 如： 小苹果商店旁
	pair<float, float> _coordinate;		// 存放机坐标
	int _pow_bank_num;					// 充电宝数量
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
	int pow_bank_num() {
		return _pow_bank_num;
	}
	PowBankDepository() {}
	PowBankDepository(int dep_idf, string dep_loc_name, pair<float, float> coordinate,
		int pow_bank_num) :_dep_idf(dep_idf), _dep_loc_name(dep_loc_name), _coordinate(coordinate), _pow_bank_num(pow_bank_num) {}
	bool UpdateCheckCode(int new_check_code);
	//bool IdfCheckCode(int ck); 
	PowBank LendPowBank(int chk);		// 借出充电宝，参数为用户得到的验证码 
	void ReturnPowBank(PowBank&);		// 归还充电宝
	void ChargePowBank(PowBank&);		// 为充电宝充电
};
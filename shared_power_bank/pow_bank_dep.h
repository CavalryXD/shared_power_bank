#pragma once
#include <set>
#include "pow_bank.h"
using namespace std;
class PowBankDepositry
{
private:
	int dep_idf;
	string dep_loc_name;
	pair<float, float> coordinate;
	int pow_bank_num;
	set<int> chk_codes;
	set<PowBank&> depoitry;
public:
	PowBankDepositry() = default;
	PowBankDepositry(int dep_idf, string dep_loc_name, pair<float,float> coordinate, int pow_bank_num,
		set<int>chk_codes, set<PowBank&> dep); 
	bool UpdateCheckCode(int new_check_code);
	//bool IdfCheckCode(int ck);
	PowBank& LendPowBank(int ck);
	void ReturnPowBank(PowBank&);
	//
};
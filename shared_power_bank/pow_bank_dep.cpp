#include "pow_bank_dep.h"
#include <vector>
PowBankDepository::PowBankDepository(int dep_idf, string dep_loc_name, pair<float, float> coordinate, int pow_bank_num,
	vector<int>chk_codes, vector<PowBank> dep) {

}
PowBank PowBankDepository::LendPowBank(int chk) {
	return PowBank();
}
void PowBankDepository::ReturnPowBank(PowBank&) {

}
void PowBankDepository::ChargePowBank(PowBank&) {

}
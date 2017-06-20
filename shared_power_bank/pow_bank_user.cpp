#include <iostream>
#include <string>
#include <vector>
#include "pow_bank_user.h"
#include "location_service.h"
#include "dep_manager.h"
#include "pow_bank_dep.h"
using namespace std;

void PowBankUser::GetInfo(string name, string phone_number) {
	user_name = name;
	user_phone_number = phone_number;
}
void PowBankUser::GetLocation() {
	current_location = LocService::GetLocation();
}
void PowBankUser::ChoosePowDep() {
	vector<PowBankDepository&> vec=DepositoryMng::GetNeighborDep(current_location);
	cout << "以下是您周围的充电宝存放点" << endl;
	//输出周围的充电宝
	for (auto p : vec) {
		cout << p.dep_idf() << " " << dep_loc_name() << " "
			<< coordinate().first << "," << coordinate().second << endl;
	}
	cout << "请输入您想选择的存放机的编号" << endl;
	int number;
	cin >> number;						//存放机编号
	chosen_dep = &vec[number - 1];		//暂定选择存放机的方法
}
void PowBankUser::GetChkCode() {
	chk_code = DepositoryMng::GetChkCode(*chosen_dep);
}
int PowBankUser::ShowChkCode() {
	return chk_code;
}
void PowBankUser::BorrowPow() {
	user_pow = &(chosen_dep->LendPowBank(chk_code));

}
void PowBankUser::ReturnPow() {

}
void PowBankUser::CreateOrder() {

}
void PowBankUser::CalculateCost() {

}
#include <iostream>
#include <string>
#include <vector>
#include "pow_bank_user.h"
#include "location_service.h"
#include "dep_manager.h"
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
	//cout<<
	for (auto p : vec) {
		cout << p.dep_idf() << " " << dep_loc_name() << " "
			<< coordinate().first << "," << coordinate().second << endl;
	}
	cout << "请输入您想选择哪一个存放机" << endl;
	int number;


}
void PowBankUser::GetChkCode() {

}
int PowBankUser::ShowChkCode() {

}
void PowBankUser::ReturnPow() {

}
void PowBankUser::CreateOrder() {

}
void PowBankUser::CalculateCost() {

}
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
	vector<PowBankDepository*> vec=DepositoryMng::GetNeighborDep(current_location);
	cout << "����������Χ�ĳ�籦��ŵ�" << endl;
	//�����Χ�ĳ�籦
	for (auto p : vec) {
//		cout << p.dep_idf() << " " << dep_loc_name() << " "
//			<< coordinate().first << "," << coordinate().second << endl;
	}
	cout << "����������ѡ��Ĵ�Ż��ı��" << endl;
	int number;
	cin >> number;						//��Ż����
	chosen_dep = vec[number - 1];		//�ݶ�ѡ���Ż��ķ���
}
void PowBankUser::GetChkCode() {
	chk_code = DepositoryMng::GetChkCode(*chosen_dep);
}
int PowBankUser::ShowChkCode() {
	cout << "������֤���ǣ�"<< chk_code << endl;
	return chk_code;
}
void PowBankUser::BorrowPow() {
//	user_pow = chosen_dep->LendPowBank(chk_code);
	/*while (user_pow == nullptr) {
		cout << "���������֤�벻��ȷ";
		cout << "�Ƿ�Ҫ��������? yes or no" << endl;
		string judge;
		cin >> judge;
		if (judge == "yes") {

		}
		else
			break;
	}*/
}
void PowBankUser::ReturnPow() {
	user_pow = nullptr;
}
void PowBankUser::GetMoney(float) {

}
void PowBankUser::CreateOrderform() {

}
void PowBankUser::CalculateCost() {

}
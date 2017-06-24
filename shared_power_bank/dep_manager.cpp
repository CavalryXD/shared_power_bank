#include "dep_manager.h"
vector<PowBankDepository*> 
DepositoryMng::GetNeighborDep(pair<float, float> coordinate) {
	//get
	string s= "http://localhost:port/depositories?username=";
	Json::Value value = GetUrl::Get(s);

	return vector<PowBankDepository*>();
 }
int DepositoryMng::GetChkCode(PowBankDepository selected_dep) {
	return 0;
}
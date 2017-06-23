//#pragma comment(lib,"json_vc71_libmt.lib")
//#pragma comment(lib,"json_vc71_libmtd.lib")
#include <iostream>
#include "pow_bank_user.h"

using namespace std;
int main() {
	PowBankUser user;
	int optcode;
	cout << "欢迎使用XX共享充电宝" << endl;
	cout << "0，退出程序 1，登陆 2，注册" << endl;
	cin >> optcode;
	string name;
	string number;
	switch (optcode) {
	case 0:
		return 0;
	case 1:
		//get
		break;
	case 2:
		cin >> name >> number;
		user.GetInfo(name, number);
		break;
	}
	if (optcode == 2)
		cout << "您已成功登陆！" << endl;
	if (optcode == 1)
	{
		cout << "您已注册成功！" << endl;
		cout << "需要立即登陆吗？ 1不需要 2需要" << endl;
		cin >> optcode;
		if (optcode == 2)
			goto borrow;
		else
			return 0;
	}
	cout << "请问您接下来想执行什么操作？" << endl;
	borrow:
	cout << "0，退出程序 1，查询附近的充电宝" << endl;
	cin >> optcode;/*
	switch (optcode) {
	case 0:          
		user.GetLocation();
		user.ChoosePowDep();
		break;
	case 1:
		return 0;
	}
	cout << "查询附近充电宝成功，请问您接下来需要什么做什么？" << endl;
	cout << "0，退出程序 1，借充电宝" << endl;
	*/
	
	return 0;
}



























/*std::string strValue = "{\"key1\":\"value1\",\"array\":[{\"key2\":\"value2\"},{\"key2\":\"value3\"},{\"key2\":\"value4\"}]}";
Json::Reader reader;
Json::Value value;
if (reader.parse(strValue, value))
{
std::string out = value["key1"].asString();
std::cout << out << std::endl;
const Json::Value arrayObj = value["array"];
for (int i = 0; i<arrayObj.size(); i++)
{
out = arrayObj[i]["key2"].asString();
std::cout << out;
if (i != arrayObj.size()-1)
std::cout << std::endl;
}
}
getchar();
getchar();*/
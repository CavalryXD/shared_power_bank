//#pragma comment(lib,"json_vc71_libmt.lib")
//#pragma comment(lib,"json_vc71_libmtd.lib")
#include <iostream>
#include "pow_bank_user.h"

using namespace std;
int main() {
	PowBankUser user;
	int optcode;
	cout << "��ӭʹ��XX�����籦" << endl;
	cout << "0���˳����� 1����½ 2��ע��" << endl;
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
		cout << "���ѳɹ���½��" << endl;
	if (optcode == 1)
	{
		cout << "����ע��ɹ���" << endl;
		cout << "��Ҫ������½�� 1����Ҫ 2��Ҫ" << endl;
		cin >> optcode;
		if (optcode == 2)
			goto borrow;
		else
			return 0;
	}
	cout << "��������������ִ��ʲô������" << endl;
	borrow:
	cout << "0���˳����� 1����ѯ�����ĳ�籦" << endl;
	cin >> optcode;/*
	switch (optcode) {
	case 0:          
		user.GetLocation();
		user.ChoosePowDep();
		break;
	case 1:
		return 0;
	}
	cout << "��ѯ������籦�ɹ�����������������Ҫʲô��ʲô��" << endl;
	cout << "0���˳����� 1�����籦" << endl;
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
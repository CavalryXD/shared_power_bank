//#pragma comment(lib,"json_vc71_libmt.lib")
//#pragma comment(lib,"json_vc71_libmtd.lib")
#include <iostream>
#include "pow_bank_user.h"
#include <time.h>
#include <map>
#include <algorithm>

int optcode;
using namespace std;
int main() {
	//�°汾
	PowBankUser user;
	string name, number,password;		//�û�Ҫ�洢�������͵绰
	vector<vector<string>> interface;
	cout << "��ӭ����XX�����籦������" << endl;
	//cout << "���������һ�½���" << endl;
	//  �˳�����
	// 0 ��ʼ����
	// 1 �û�����
	// 2 ѡ���Ż�����
	// 3 �軹����
	// 4 ֧������
	
	interface.push_back(vector<string>{"�˳�����", "ע�����û�","���ڵ�½"});
	//��½��ֱ�ӽ����û�����
	interface.push_back(vector<string>{"�˳�����", "��ʾ�û���Ϣ","��ʾ��ǰ���","��ѡ���Ż�����"});
	interface.push_back(vector<string>{"�˳�����", "ѡ���Ż�","�򿪽軹����"});
	interface.push_back(vector<string>{"�˳�����", "��һ����籦","�黹һ����籦","��ʾ��ǰ��֤��","�ص�ѡ���Ż�������","�ص��û�����","��֧������"});
	interface.push_back(vector<string>{"�˳�����", "�鿴�������ѽ��","�鿴�������","�ص��û�����"});
	

	cout << "��ǰ����Ϊ��ڽ��棬����ѡ�����²���:" << endl;
	int i = 0;
	for (auto c : interface[0]) {
		cout <<"["<<i++<<"]"<<"	"<< c << endl;
	}
	//ע���¼����
	cin >> optcode;
	switch (optcode) {
	case 0:
		return 0;
	case11:
	case 1:
	{
		bool sign1 = user.SignUp();
		//get�����ݿⷢ����Ϣ�˶���Ϣ
		if (sign1 == true)
			cout << "��ϲ����ע��ɹ���" << endl;
		if (sign1 == false) {
			cout << "�Բ��𣬴��û��Ѵ���" << endl << "�Ƿ�Ҫ����ע���أ� 0 or 1" << endl;
			cin >> optcode;
			if (optcode == 1)
				goto case11;
			else
				return 0;
		}
		cout << "������Ҫ���ڵ�½�� 0 or 1" << endl;
		cin >> optcode;
		if (optcode != 1)
			return 0;
		if (optcode == 1)
			goto case12;
		
	}
	break;
	case 2:
	case12:
		//get�����ݿ�����Ϣ�Ƿ�һ��
	{
		bool sign2 = user.SignIn();
		if (sign2 == true)
			cout << "��½�ɹ���������ת���û�����" << endl;
		else {
			cout << "�����������������Ҫ���������� 0 or 1" << endl;
			cin >> optcode;
			if (optcode != 1)
				return 0;
			if (optcode == 1)
				goto case12;
		}
		break;
	}
	default:
		return 0;
		
	}

	//�û�����
	user_:
	cout << "��ǰ����Ϊ�û����棬����ѡ�����²���:" << endl;
	i = 0;
	for (auto c : interface[1]) {
		cout << "[" << i++ << "]" << "	" << c << endl;
	}
	cin >> optcode;
	switch (optcode) {
	case 0:
		return 0;
	case 1:
		user.ShowInfo();
		cout << "�Ƿ񷵻ص��û����棿 0 or 1" << endl;
		cin >> optcode;
		if (optcode == 0)
			;
		if (optcode == 1)
			goto user_;
		break;
	case 2:
		user.ShowMoney();
		cout << "�Ƿ񷵻ص��û����棿 0 or 1" << endl;
		cin >> optcode;
		if (optcode == 0)
			;
		if (optcode == 1)
			goto user_;
		break;
	case 3:
		goto repositry;
	default:
		return 0;
	}

	//��Ż�����
repositry:
	cout << "��ǰ����Ϊѡ���Ż������棬����ѡ�����²���:" << endl;
	i = 0;
	for (auto c : interface[2]) {
		cout << "[" << i++ << "]" << "	" << c << endl;
	}
	cin >> optcode;
	switch (optcode) {
	case 0:
		return 0;
	case 1:
		user.GetLocation();
		user.ChoosePowDep();
		break;
	case 2:
		if (user.IfGetPowDep())
			goto borrowandlend;
		else {
			cout << "����û��ѡ��һ����Ż�" << endl;
			cout << "�Ƿ�Ҫѡ��һ����Ż�? 0 or 1" << endl;
			cin >> optcode;
			if (optcode == 0) {
				goto repositry;
			}
			if (optcode == 1)
				goto borrowandlend;
		}
		break;
	default:
		return 0;
	}

	//�軹����
borrowandlend:
	cout << "��ǰ����Ϊ�軹���棬����ѡ�����²���:" << endl;
	i = 0;
	for (auto c : interface[3]) {
		cout << "[" << i++ << "]" << "	" << c << endl;
	}
	cin >> optcode;
	switch (optcode) {
	case 0:
		return 0;
	case 1:
		user.ShowChkCode();
		user.BorrowPow();
		break;
case22:
	case 2:
		if (user.IfGetPow()) {
			user.ReturnPow();
		}
		else {
			cout << "����û�н��籦������Ҫ�黹" << endl;
			cout << "����ȥ��һ����籦�� 0 or  1" << endl;
			cin >> optcode;
			if (optcode == 0)
				goto borrowandlend;
			if (optcode == 1)
				goto case22;
		}
		break;
	case 3:
		user.ShowChkCode();
		break;
	case 4:
		goto repositry;
	case 5:
		goto user_;
	case 6:
		goto pay;
	default:
		return 0;
	}

	//֧������
	pay:
	cout << "��ǰ����Ϊ֧�����棬����ѡ�����²���:" << endl;
	i = 0;
	for (auto c : interface[4]) {
		cout << "[" << i++ << "]" << "	" << c << endl;
	}
	cin >> optcode;
	switch (optcode) {
	case 0:
		return 0;
	case 1:
		cout << "�㱾�����ѵĽ��Ϊ��" <<user.CalculateCost(begin,end)<< endl;
		break;
	case 2:
		user.ShowMoney();
		break;
	case 3:
		goto user_;
	default:
		return 0;

	}

	getchar();
	getchar();

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
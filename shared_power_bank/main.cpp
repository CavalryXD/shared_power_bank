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

	
	/*
	PowBankUser user;
	cout << "��ӭʹ��XX�����籦" << endl;
	cout << "[0] �˳�����		[1] ��½			[2] ע��" << endl;
	re_input1:
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
		cout << "�������������ֺ͵绰���룬�м��ûس��ָ�" << endl;
		cout << "�������������֣�" ;
		cin >> name ;
		cout << "���������ĵ绰���룺" ;
		cin >> number;
		user.GetInfo(name, number);
		break;
	default:
		cout << "�Բ�����������������������" << endl;
		goto re_input1;
	}
	if (optcode == 1)
		cout << "���ѳɹ���½��" << endl;
	if (optcode == 2)
	{
		cout << "����ע��ɹ���" << endl;
		cout << "��Ҫ������½��			[1] ����Ҫ [2] ��Ҫ" << endl;
		cin >> optcode;
		if (optcode == 2)
			goto borrow;       
		else
			return 0;
	}
	cout << "��������������ִ��ʲô������" << endl;

	borrow:     //�������㣬�����������籦

	cout << "[0] �˳�����			[1] ��ѯ�����ĳ�籦" << endl;
	re_input2:
	cin >> optcode;
	switch (optcode) {
	case 0:          
		return 0;
	case 1:
		user.GetLocation();
		user.ChoosePowDep();
		break;
	default:
		cout << "�Բ�����������������������" << endl;
		goto re_input2;
	}
	if (optcode == 1)
	{
		cout << "��ѯ������籦�ɹ�����������������Ҫʲô��ʲô��" << endl;
		cout << "[0] �˳�����			[1] ���籦" << endl;
	}
	cin >> optcode;
	if (optcode != 1)
		return 0;
	if (optcode == 1) {
		cout << "������֤���ǣ�";//<<user.ShowChkCode()<< endl;
	}
	int input_times = 0;
	while (true) {				 
		//����http���ж���֤���Ƿ����
		//�ڴ˴������ж�
		cout << "���������֤����������������" << endl;
		input_times++;
		if (input_times == 3) {
			cout << "�������3�Σ����������" << endl;
			return 0;
		}
	}
	cout << "���ڻ����·�ȡ����籦��ף��ʹ����죡" << endl;
	float costs;				 //�Ӵ���籦�ܻ���
	time_t begin_time;			 //��ʱ
	cout << "��ӭ�ص������棬�����ִ�����²�����" <<endl<< 
		"[0] �˳�����	   [1]��һ����籦		[2]�黹��籦"<<endl;
	cin >> optcode;
	switch (optcode) {
	case 0:
		return 0;
	case 1:
		if (!user.IfGetPow()) {
			user.GetLocation();
			user.ChoosePowDep();
			break;
		}
		else {
			cout << "���Ѿ�����һ����籦�ˣ����ڹ黹����֮����ִ�в���" << endl;
			break;
		}
	case 2:
		user.ReturnPow();
		cout << "���ѳɹ��黹��籦����ӭ�´�ʹ�ã�" << endl;
	default:
		;
	}
	*/
	//�°汾
	PowBankUser user;
	string name, number,password;		//�û�Ҫ�洢�������͵绰
	time_t begin, end;
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

		}
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
		time_t t1;
		time(&t1);
		begin = t1;
case22:
	case 2:
		if (user.IfGetPow()) {
			user.ReturnPow();
			time_t t2;
			time(&t2);
			end = t2;
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
	case 3:
		user.ShowChkCode();
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
	case 2:
		user.ShowMoney();
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
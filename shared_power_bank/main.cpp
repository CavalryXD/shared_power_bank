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

	PowBankUser user;

	cout << "欢迎使用XX共享充电宝" << endl;
	cout << "[0] 退出程序		[1] 登陆			[2] 注册" << endl;
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
		cout << "请输入您的名字和电话号码，中间用回车分隔" << endl;
		cout << "请输入您的名字：" ;
		cin >> name ;
		cout << "请输入您的电话号码：" ;
		cin >> number;
		user.GetInfo(name, number);
		break;
	default:
		cout << "对不起，您输入有误请重新输入" << endl;
		goto re_input1;
	}
	if (optcode == 1)
		cout << "您已成功登陆！" << endl;
	if (optcode == 2)
	{
		cout << "您已注册成功！" << endl;
		cout << "需要立即登陆吗？			[1] 不需要 [2] 需要" << endl;
		cin >> optcode;
		if (optcode == 2)
			goto borrow;       
		else
			return 0;
	}
	cout << "请问您接下来想执行什么操作？" << endl;

	borrow:     //在这个结点，可以用来借充电宝

	cout << "[0] 退出程序			[1] 查询附近的充电宝" << endl;
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
		cout << "对不起，您输入有误请重新输入" << endl;
		goto re_input2;
	}
	if (optcode == 1)
	{
		cout << "查询附近充电宝成功，请问您接下来需要什么做什么？" << endl;
		cout << "[0] 退出程序			[1] 借充电宝" << endl;
	}
	cin >> optcode;
	if (optcode != 1)
		return 0;
	if (optcode == 1) {
		cout << "您的验证码是：";//<<user.ShowChkCode()<< endl;
	}
	int input_times = 0;
	while (true) {				 
		//接受http，判断验证码是否相等
		//在此处进行判断
		cout << "您输入的验证码有误，请重新输入" << endl;
		input_times++;
		if (input_times == 3) {
			cout << "您已输错3次，请待会重试" << endl;
			return 0;
		}
	}
	cout << "请在机器下方取出充电宝，祝你使用愉快！" << endl;
	float costs;				 //接触充电宝总花费
	time_t begin_time;			 //计时
	cout << "欢迎回到主界面，你可以执行以下操作：" <<endl<< 
		"[0] 退出程序	   [1]借一个充电宝		[2]归还充电宝"<<endl;
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
			cout << "您已经借了一个充电宝了，请在归还充电包之后在执行操作" << endl;
			break;
		}
	case 2:
		user.ReturnPow();
		cout << "你已成功归还充电宝，欢迎下次使用！" << endl;
	default:
		;
	}

	//新版本
	vector<vector<string>> all_interface;
	cout << "欢迎来到XX共享充电宝！！！" << endl;
	//cout << "本程序包含一下界面" << endl;
	//  退出程序
	// 0 开始界面
	// 1 用户界面
	// 2 选择存放机界面
	// 3 借还界面
	// 4 支付界面
	
	all_interface.push_back(vector<string>{"退出程序", "显示您当前位置"});
	all_interface.push_back(vector<string>{"显示用户信息","显示当前余额"});
	all_interface.push_back(vector<string>{"显示当前位置","选择存放机"});
	all_interface.push_back(vector<string>{"接一个充电宝","归还一个充电宝","显示当前验证码"});
	all_interface.push_back(vector<string>{"查看本次消费金额","查看您的余额"});






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
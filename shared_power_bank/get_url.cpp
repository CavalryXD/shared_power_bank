#include "get_url.h"
Json::Value GetUrl::Get(const string url) {
	WORD sockVersion = MAKEWORD(2, 2);
	WSADATA data;
	if (WSAStartup(sockVersion, &data) != 0)
	{
		return 0;
	}
	SOCKET sclient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sclient == INVALID_SOCKET)
	{
		printf("invalid socket!");
		return 0;
	}
	sockaddr_in serAddr;
	serAddr.sin_family = AF_INET;
	serAddr.sin_port = htons(5000);
	serAddr.sin_addr.S_un.S_addr = inet_addr("192.168.31.97");
	if (connect(sclient, (sockaddr *)&serAddr, sizeof(serAddr)) == SOCKET_ERROR)
	{ //连接失败   
		printf("connect error!");
		closesocket(sclient);
		return 0;
	}
	//string mdata = "GET /depositories/checkcode?username=asdfwdsfrg&id=2 HTTP/1.1\nHost:192.168.31.97:5000\n\n";
	string mdata = url;
	//cin >> mdata;
	const char * sendData;
	sendData = mdata.c_str(); //string转const char*   									//char * sendData = "你好，TCP服务端，我是客户端\n";  
	send(sclient, sendData, strlen(sendData), 0);
	//send()用来将数据由指定的socket传给对方主机  
	//int send(int s, const void * msg, int len, unsigned int flags)  
	//s为已建立好连接的socket，msg指向数据内容，len则为数据长度，参数flags一般设0  
	//成功则返回实际传送出去的字符数，失败返回-1，错误原因存于error   
	char recData[2000];
	int ret;
	string alljdata;
	while (ret = recv(sclient, recData, 2000, 0)) {
		if (ret>0) {
			recData[ret] = 0x00;
			//cout << recData << endl;
			alljdata += string(recData);
		}
	}
	auto begin = alljdata.begin();
	auto end = alljdata.end() - 1;
	for (; ;) {
		if (*begin == '[' || *begin == '{' || *begin == '"') {
			break;
		}
		++begin;
	}
	for (;;) {
		if (*end != '[' && *end != '{' && *end != '"') {
			--end;
		}
		break;
	}
	string jdata(begin, end + 1);
	Json::Reader reader;
	Json::Value value;
	reader.parse(jdata, value);				//解析Json
	closesocket(sclient);
	WSACleanup();
	return value;
}
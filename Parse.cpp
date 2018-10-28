#include "Parse.h"
#include <vector>


Parse::Parse()
{
}


Parse::~Parse()
{
}

Parse * Parse::instance()
{
	static Parse instance;
	return &instance;
}

int Parse::FindStr(const char* buf, char* key)
{
	char *pdest = NULL;
	pdest = strstr((char *)buf, key);
	if (pdest != NULL)
		return (pdest - buf);
	else
		return -1;
}
bool Parse::GetData(const char *buf, char* szFind, char *szData, int len)
{
	int pos = FindStr(buf, szFind);
	if (pos < 0)
		return false;

	int posEnd = FindStr(buf + pos + strlen(szFind), "\"");
	if (posEnd<0)
		return false;
	if (posEnd>len)
		posEnd = len;
	strncpy(szData, buf + pos + strlen(szFind), posEnd);
	szData[posEnd] = '\0';
	return true;
}
int Parse::getType(char *buf)
{
	char Data[256];

	memset(Data, 0, 256);

	if (!GetData(buf, "type=\"", Data))
		return -1;
	printf("type = %d\n", atoi(Data));
	return atoi(Data);
}

//"type=\"1\"<aaaa=\"11111111\"bbb=\"111111111\"ccccc=\"111\"><aaaa=\"2222222222\"bbb=\"111111111\"ccccc=\"111\"><aaaa=\"3333333333\"bbb=\"111111111\"ccccc=\"111\"><aaaa=\"4444444444444\"bbb=\"111111111\"ccccc=\"111\">";
int Parse::GetSingleItemData(char *buf, std::vector <std::string > & vec)
{
	char szData[1024] = "";
	int pos = 0, offset = 0;
	int posStart = 0, posEnd = 0;
	while (true)
	{
		posStart = FindStr(buf + offset, "<");
		if (posStart < 0)
			return -1;
		posEnd = FindStr(buf + offset + posStart, ">");
		if (posEnd < 0)
			return -1;
		strncpy(szData, buf + offset + posStart, posEnd);
		szData[posEnd] = '\0';
		if (pos < 0)
			break;
		offset += posStart + posEnd;
		vec.push_back(szData + 1);
	}
	return 0;
}

bool Parse::GetQueryIdentificationResultPara(const char* buf, char *parentIdentity, char * parentName)
{
	char Data[256];

	memset(Data, 0, 256);

	if (!GetData(buf, "parentIdentity=\"", Data))
		return false;
	strcpy(parentIdentity, Data);

	if (!GetData(buf, "parentName=\"", Data))
		return false;
	strcpy(parentName, Data);

	return true;
}

bool Parse::GetSubmitResultPara(const char* buf, char * parentID, char * childID, char * parentDNA, char * childDNA, char *retult)
{
	char Data[256];

	memset(Data, 0, 256);

	if (!GetData(buf, "parentID=\"", Data))
		return false;
	strcpy(parentID, Data);

	if (!GetData(buf, "childID=\"", Data))
		return false;
	strcpy(childID, Data);

	if (!GetData(buf, "parentDNA=\"", Data))
		return false;
	strcpy(parentDNA, Data);

	if (!GetData(buf, "childDNA=\"", Data))
		return false;
	strcpy(childDNA, Data);

	if (!GetData(buf, "retult=\"", Data))
		return false;
	strcpy(retult, Data);

	return true;
}

bool Parse::Para1001(const char* buf, char* userName, char* result)
{
	char Data[256];

	memset(Data, 0, 256);

	if (!GetData(buf, "userName=\"", Data))
		return false;
	strcpy(userName, Data);

	if (!GetData(buf, "result=\"", Data))
		return false;
	strcpy(result, Data);

	return true;
}

bool Parse::Para1002(const char* buf, char* userName, char* result)
{
	char Data[256];

	memset(Data, 0, 256);

	if (!GetData(buf, "userName=\"", Data))
		return false;
	strcpy(userName, Data);

	if (!GetData(buf, "result=\"", Data))
		return false;
	strcpy(result, Data);

	return true;
}

bool Parse::Para1003(const char* buf, char* userName, char* passWord, char* name, char* id, char* sex, char* phone, char* mail, char* address, char* weight, char* height)
{
	char Data[256];

	memset(Data, 0, 256);

	if (!GetData(buf, "userName=\"", Data))
		return false;
	strcpy(userName, Data);

	if (!GetData(buf, "passWord=\"", Data))
		return false;
	strcpy(passWord, Data);

	if (!GetData(buf, "name=\"", Data))
		return false;
	strcpy(name, Data);

	if (!GetData(buf, "id=\"", Data))
		return false;
	strcpy(id, Data);

	if (!GetData(buf, "sex=\"", Data))
		return false;
	strcpy(sex, Data);

	if (!GetData(buf, "phone=\"", Data))
		return false;
	strcpy(phone, Data);

	if (!GetData(buf, "mail=\"", Data))
		return false;
	strcpy(mail, Data);

	if (!GetData(buf, "address=\"", Data))
		return false;
	strcpy(address, Data);

	if (!GetData(buf, "weight=\"", Data))
		return false;
	strcpy(weight, Data);

	if (!GetData(buf, "height=\"", Data))
		return false;
	strcpy(height, Data);

	return true;
}

bool Parse::Para1004(const char* buf, char* userName, char* result)
{
	char Data[256];

	memset(Data, 0, 256);

	if (!GetData(buf, "userName=\"", Data))
		return false;
	strcpy(userName, Data);

	if (!GetData(buf, "result=\"", Data))
		return false;
	strcpy(result, Data);

	return true;
}

bool Parse::Para1005(const char* buf, char* userName, char* result)
{
	char Data[256];

	memset(Data, 0, 256);

	if (!GetData(buf, "userName=\"", Data))
		return false;
	strcpy(userName, Data);

	if (!GetData(buf, "result=\"", Data))
		return false;
	strcpy(result, Data);

	return true;
}

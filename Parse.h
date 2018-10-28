#pragma once
#include <string>
#include <vector>

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	A server parse. </summary>
///
/// <remarks>	gsl, 2017/6/9. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

class Parse
{
public:
	Parse();
	~Parse();
	static Parse * instance();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Searches for the first string. </summary>
	///
	/// <remarks>	gsl, 2017/6/14. </remarks>
	///
	/// <param name="buf">	The buffer. </param>
	/// <param name="key">	[in,out] If non-null, the key. </param>
	///
	/// <returns>	The found string. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	int FindStr(const char* buf, char* key);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets a data. </summary>
	///
	/// <remarks>	gsl, 2017/6/14. </remarks>
	///
	/// <param name="buf">   	The buffer. </param>
	/// <param name="szFind">	[in,out] If non-null, the find. </param>
	/// <param name="szData">	[in,out] If non-null, the data. </param>
	/// <param name="lenlen">	(Optional) The lenlen. </param>
	///
	/// <returns>	True if it succeeds, false if it fails. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	bool GetData(const char *buf, char* szFind, char *szData, int lenlen = 1023);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets a type. </summary>
	///
	/// <remarks>	gsl, 2017/6/14. </remarks>
	///
	/// <param name="buf">	[in,out] If non-null, the buffer. </param>
	///
	/// <returns>	The type. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	int getType(char *buf);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets single item data./ </summary>
	///
	/// <remarks>	gsl, 2017/6/14. </remarks>
	///
	/// <param name="buf">	[in,out] If non-null, the buffer. </param>
	/// <param name="vec">	[in,out] The vector. </param>
	///
	/// <returns>	The single item data. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	//"type=\"99\"<aaaa=\"11111111\"bbb=\"111111111\"ccccc=\"111\"><aaaa=\"2222222222\"bbb=\"111111111\"ccccc=\"111\"><aaaa=\"3333333333\"bbb=\"111111111\"ccccc=\"111\"><aaaa=\"4444444444444\"bbb=\"111111111\"ccccc=\"111\">";
	int GetSingleItemData(char *buf, std::vector <std::string > & vec);
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	2号协议解析 . </summary>
	///
	/// <remarks>	gsl, 2017/6/10. </remarks>
	///
	/// <param name="buf">			 	The buffer. </param>
	/// <param name="parentIdentity">	[in,out] If non-null, the parent identity. </param>
	/// <param name="parentName">	 	[in,out] If non-null, name of the parent. </param>
	///
	/// <returns>	True if it succeeds, false if it fails. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	bool GetQueryIdentificationResultPara(const char* buf, char *parentIdentity, char * parentName);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	3号协议解析 . </summary>
	///
	/// <remarks>	gsl, 2017/6/10. </remarks>
	///
	/// <param name="buf">   	The buffer. </param>
	/// <param name="result">	[out] If non-null, the result. </param>
	///
	/// <returns>	True if it succeeds, false if it fails. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	bool GetSubmitResultPara(const char* buf, char *  parentID, char *  childID, char *  parentDNA, char *  childDNA, char *retult);

	bool Para1001(const char* buf, char* userName, char* result);
	bool Para1002(const char* buf, char* userName, char* result);
	bool Para1003(const char* buf, char* userName, char* passWord, char* name, char* id, char* sex, char* phone, char* mail, char* address, char* weight, char* height);
	bool Para1004(const char* buf, char* userName, char* result);
	bool Para1005(const char* buf, char* userName, char* result);

};


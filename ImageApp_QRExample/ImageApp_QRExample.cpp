#include <stdio.h>
#include <tchar.h>
#include <Windows.h>
#include "../../IEngine_Image/IEngine_Source/IEngine_ImageRecognition/ImageRecognition_Define.h"
#include "../../IEngine_Image/IEngine_Source/IEngine_ImageRecognition/ImageRecognition_Error.h"

#ifdef _MSC_BUILD
#pragma comment(lib,"../../IEngine_Image/IEngine_Source/Debug/IEngine_ImageRecognition")
#endif

int main()
{
#ifdef _MSC_BUILD
	LPCTSTR lpszSrcFile = _T("D:\\IEngine_ImageApp\\1.png");
	LPCSTR lpszDstFile = "D:\\IEngine_ImageApp\\1.png";
#else
	LPCTSTR lpszFile = _T("1.png");
#endif
	LPCTSTR lpszDetectProto = _T("D:\\IEngine_ImageApp\\Debug\\detect.prototxt");
	LPCTSTR lpszDetectModel = _T("D:\\IEngine_ImageApp\\Debug\\detect.caffemodel");
	LPCTSTR lpszSrProto = _T("D:\\IEngine_ImageApp\\Debug\\sr.prototxt");
	LPCTSTR lpszSrModel = _T("D:\\IEngine_ImageApp\\Debug\\sr.caffemodel");

	ImageRecognition_Help_QREncodec(lpszSrcFile, _T("hellowdm,21md02md012d02jd0"));
	TCHAR tszMsgBuffer[1024];
	CHAR tszSrcBuffer[102400];

	memset(tszMsgBuffer, '\0', sizeof(tszMsgBuffer));
	memset(tszSrcBuffer, '\0', sizeof(tszSrcBuffer));

// 	FILE* pSt_File = fopen(lpszDstFile, "rb");
// 	int nRet = fread(tszSrcBuffer, 1, sizeof(tszSrcBuffer), pSt_File);
// 	ImageRecognition_Help_QRDecodec(tszSrcBuffer, &nRet, tszMsgBuffer, lpszDetectProto, lpszDetectModel, lpszSrProto, lpszSrModel);
	ImageRecognition_Help_QRDecodec(lpszDstFile, NULL, tszMsgBuffer, lpszDetectProto, lpszDetectModel, lpszSrProto, lpszSrModel);
	_tprintf(_T("%s\n"), tszMsgBuffer);
	return 0;
}
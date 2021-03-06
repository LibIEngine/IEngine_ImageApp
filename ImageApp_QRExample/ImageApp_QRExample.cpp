#include <stdio.h>
#include <tchar.h>
#include <locale.h>
#include <Windows.h>
#include "../../IEngine_Image/IEngine_Source/IEngine_ImageRecognition/ImageRecognition_Define.h"
#include "../../IEngine_Image/IEngine_Source/IEngine_ImageRecognition/ImageRecognition_Error.h"

#ifdef _MSC_BUILD
#ifdef _WIN64
#pragma comment(lib,"../../IEngine_Image/IEngine_Source/x64/Debug/IEngine_ImageRecognition")
#else
#pragma comment(lib,"../../IEngine_Image/IEngine_Source/Debug/IEngine_ImageRecognition")
#endif
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
	LPCTSTR lpszSrcBuffer = _T("我阿达是:12010:wadnowandoawind");

	TCHAR tszMsgBuffer[1024];
	memset(tszMsgBuffer, '\0', sizeof(tszMsgBuffer));

	ImageRecognition_Help_QREncodec(lpszSrcFile, lpszSrcBuffer);
	ImageRecognition_Help_QRDecodec(lpszDstFile, NULL, tszMsgBuffer, lpszDetectProto, lpszDetectModel, lpszSrProto, lpszSrModel);

	_tsetlocale(LC_ALL, _T("chs"));
	_tprintf(_T("%ws\n"), tszMsgBuffer);
	return 0;
}
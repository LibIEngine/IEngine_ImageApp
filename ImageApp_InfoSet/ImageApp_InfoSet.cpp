#ifdef _MSC_BUILD
#include <Windows.h>
#include <tchar.h>
#pragma comment(lib,"XEngine_SystemSdk/XEngine_SystemApi")
#ifdef _WIN64
#pragma comment(lib,"../../IEngine_Image/IEngine_Source/x64/Debug/IEngine_ImageInformation")
#else
#pragma comment(lib,"../../IEngine_Image/IEngine_Source/Debug/IEngine_ImageInformation")
#endif
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <XEngine_Include/XEngine_CommHdr.h>
#include <XEngine_Include/XEngine_Types.h>
#include <XEngine_Include/XEngine_BaseLib/BaseLib_Define.h>
#include <XEngine_Include/XEngine_BaseLib/BaseLib_Error.h>
#include <XEngine_Include/XEngine_SystemSdk/ProcFile_Define.h>
#include <XEngine_Include/XEngine_SystemSdk/ProcFile_Error.h>
#include <XEngine_Include/XEngine_SystemSdk/SystemApi_Define.h>
#include <XEngine_Include/XEngine_SystemSdk/SystemApi_Error.h>
#include "../../IEngine_Image/IEngine_Source/IEngine_ImageInformation/ImageInfo_Define.h"
#include "../../IEngine_Image/IEngine_Source/IEngine_ImageInformation/ImageInfo_Error.h"

//g++ -std=c++17 -Wall -g ImageInfo_APPTest.cpp -o ImageInfo_APPTest.exe -L ../../../XEngine/XEngine_Release/XEngine_Linux/Ubuntu/XEngine_Image -lXEngine_ImageInformation -Wl,-rpath=../../../XEngine/XEngine_Release/XEngine_Linux/Ubuntu/XEngine_Image,--disable-new-dtags

int Image_Small()
{
	LPCTSTR lpszDir = _T("./");
	int nListCount = 0;
	CHAR** ppszListDir = NULL;
	SystemApi_File_EnumFile(lpszDir, &ppszListDir, &nListCount);
	for (int i = 0; i < nListCount; i++)
	{
		IMAGEINFO_BASEATTR st_BaseInfo;
		memset(&st_BaseInfo, '\0', sizeof(IMAGEINFO_BASEATTR));

		ImageInfo_Get_Attr(ppszListDir[i], &st_BaseInfo);
		if (ImageInfo_Set_FileResolution(ppszListDir[i], st_BaseInfo.nHeigth / 2, st_BaseInfo.nWidth / 2))
		{
			printf("裁剪文件:%s 成功\r\n", ppszListDir[i]);
		}
		else
		{
			printf("裁剪文件:%s 失败\r\n", ppszListDir[i]);
		}
	}
	return 0;
}
int main()
{
	Image_Small();
	return 0;
	IMAGEINFO_BASEATTR st_BaseInfo;
	IMAGEINFO_EXTENDATTR st_ExtInfo;
	LPCTSTR lpszFile = _T("D:\\xengine_apps\\Debug\\1.png");

	memset(&st_BaseInfo, '\0', sizeof(IMAGEINFO_BASEATTR));
	memset(&st_ExtInfo, '\0', sizeof(IMAGEINFO_EXTENDATTR));

	ImageInfo_Get_Attr(lpszFile, &st_BaseInfo, &st_ExtInfo);
	ImageInfo_Set_FileResolution(lpszFile, 1024, 768);
	return 0;
}
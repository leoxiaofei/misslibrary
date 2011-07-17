#ifndef MISS_HPP
#include <mSystem.h>
#endif

#include <windows.h>

namespace Miss
{
    TString GetAppExePath()
    {
        TCHAR pChar[MAX_PATH];
		GetModuleFileName(NULL,pChar,MAX_PATH);
		//PathRemoveFileSpec(pChar);
		int nIndex(0),nFind(0);
		while( pChar[nIndex] != '\0' )
        {
            if(pChar[nIndex] == '\\' )
            {
                nFind = nIndex;
            }
            ++nIndex;
        }
        if(nFind != 0)
        {
            pChar[nFind] = '\0';
        }
		TString ret(pChar);

		return ret;
    }
}

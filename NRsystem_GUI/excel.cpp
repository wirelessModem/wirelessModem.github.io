#include "stdafx.h"
#include"excel.h"


CexcelAccess::CexcelAccess()
{
    this->initExcel();
}

CexcelAccess::~CexcelAccess()
{
    this->releaseExcel();
    /*
    // app.Quit(); // 退出
    //释放对象
    m_range.ReleaseDispatch();
    m_sheet.ReleaseDispatch();
    m_sheets.ReleaseDispatch();
    m_book.ReleaseDispatch();
    m_books.ReleaseDispatch();

    m_app.ReleaseDispatch();
    */

}

void CexcelAccess::initExcel()
{
    //创建Excel 2003服务器(启动Excel)
    if (!m_app.CreateDispatch(_T("Excel.Application"), NULL))
    {
        AfxMessageBox(_T("Create Excel service failure!"));
        return;
    }

    // 设置为FALSE时，后面的app.Quit();注释要打开
    // 否则EXCEL.EXE进程会一直存在，并且每操作一次就会多开一个进程
    m_app.put_Visible(TRUE);
    m_books.AttachDispatch(m_app.get_Workbooks(), true);
}

void CexcelAccess::releaseExcel()
{
    //
    
    //释放对象
    m_range.ReleaseDispatch();
    m_sheet.ReleaseDispatch();
    m_sheets.ReleaseDispatch();
    m_book.ReleaseDispatch();
    m_books.ReleaseDispatch();

    m_app.Quit(); // 退出
    m_app.ReleaseDispatch();
    
    
}

void CexcelAccess::writeExcel_example(char *FileName)
{
    //LPDISPATCH lpDisp;
    COleVariant vResult;

    //COleVariant covTrue((short)TRUE);
    //COleVariant covFalse((short)FALSE);
    COleVariant covOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);

    m_book = m_books.Add(covOptional); // 添加一个工作簿，这里没有open操作，在最后调用SaveCopyAs另存为

    m_app.put_DisplayAlerts(false); // 不弹出对话框询问是否保存
                                   // 得到Worksheets

    m_sheets.AttachDispatch(m_book.get_Worksheets(), true);
    
    // 得到Worksheet
    m_sheet.AttachDispatch(m_sheets.get_Item(_variant_t((short)(1))));

    // 得到全部Cells
    m_range.AttachDispatch(m_sheet.get_Cells(), true);
    
    //m_range.put_Item(_variant_t((LONG)1), _variant_t((LONG)1), _variant_t("X"));
    //m_range.put_Item(_variant_t((LONG)1), _variant_t((LONG)2), _variant_t("Y1"));
    //m_range.put_Item(_variant_t((LONG)1), _variant_t((LONG)3), _variant_t("Y2"));

    /*
    //CRange rngTmp;
    for (int i = 0; i < 8; i++)
    {
        m_range.put_Item(_variant_t((LONG)(2 + i)), _variant_t((LONG)1), _variant_t((long)(i + 1)));
        m_range.put_Item(_variant_t((LONG)(2 + i)), _variant_t((LONG)2), _variant_t((long)((i + 1)*(i + 1))));
        m_range.put_Item(_variant_t((LONG)(2 + i)), _variant_t((LONG)3), _variant_t((long)((i + 1) * 2)));
    }
    */
    Cnterior it;
    _variant_t vrange;

    for (int i = 0; i < 8; i++)
    {
        m_range.AttachDispatch(m_sheet.get_Range(_variant_t("A1"), _variant_t("A1")));
        vrange = m_range.get_Item(_variant_t((LONG)(2 + i)), _variant_t((LONG)2));
        m_range.AttachDispatch(m_sheet.get_Range(_variant_t(vrange), _variant_t(vrange)));
        it.AttachDispatch(m_range.get_Interior());
        it.put_ColorIndex(_variant_t((long)21));
    }

    for (int i = 0; i < 8; i++)
    {
        m_range.AttachDispatch(m_sheet.get_Range(_variant_t("A1"), _variant_t("A1")));
        vrange = m_range.get_Item(_variant_t((LONG)(2 + i)), _variant_t((LONG)3));
        m_range.AttachDispatch(m_sheet.get_Range(_variant_t(vrange), _variant_t(vrange)));
        it.AttachDispatch(m_range.get_Interior());
        it.put_ColorIndex(_variant_t((long)23));
    }


    for (int i = 0; i < 8; i++)
    {
        m_range.AttachDispatch(m_sheet.get_Range(_variant_t("A1"), _variant_t("A1")));
        vrange = m_range.get_Item(_variant_t((LONG)(2 + i)), _variant_t((LONG)1));
        m_range.AttachDispatch(m_sheet.get_Range(_variant_t(vrange), _variant_t(vrange)));
        it.AttachDispatch(m_range.get_Interior());
        it.put_ColorIndex(_variant_t((long)22));
    }

    CString path;
    char ch1[100], ch2[100], ch3[100];
    int ilen;
    TCHAR  ch4[100];

    LPCTSTR lpsz = (LPCTSTR)path;
    lpsz = AfxGetApp()->m_pszHelpFilePath;
    path = lpsz;
    path = path.Left(path.ReverseFind('\\'));
    #ifdef UNICODE
    MultiByteToWideChar(CP_ACP, 0, FileName, -1, ch4, 100);
    #else
    strcpy(ch4, FileName);
    #endif

    path = path+_T('\\') + ch4;
    /*
    ilen = path.GetAllocLength();
    ilen = path.GetLength();

    strcpy_s(ch1, path.GetAllocLength(),(const char *)(LPSTR)(LPCTSTR)path);

	strcpy_s(ch1+strlen(ch1),strlen(FileName), FileName);
    */
    //path= path+_T("\\test.xlsx");
    
    #if 1
    m_book.SaveCopyAs(_variant_t(path));  //both are OK!!
    #else
    COleVariant VOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);
    m_book.SaveAs(_variant_t(path),
        VOptional, VOptional, VOptional, VOptional, VOptional,
        (long)0, VOptional, VOptional, VOptional, VOptional,
        VOptional);
    #endif


    //m_book.Save();
    //m_books.Close();
    
    #if 1
    m_app.put_DisplayAlerts(false); // 不弹出对话框询问是否保存
    #else
    m_app.put_DisplayAlerts(true); // 弹出对话框询问是否保存
    #endif
     

}

void CexcelAccess::writeExcelAsRe(int * pGrid,char *FileName)
{
    COleVariant vResult;
    COleVariant covOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);

    m_book = m_books.Add(covOptional); // 添加一个工作簿，这里没有open操作，在最后调用SaveCopyAs另存为
    m_app.put_DisplayAlerts(false); // 不弹出对话框询问是否保存
                                    // 得到Worksheets
    m_sheets.AttachDispatch(m_book.get_Worksheets(), true);
    // 得到Worksheet
    m_sheet.AttachDispatch(m_sheets.get_Item(_variant_t((short)(1))));
    // 得到全部Cells
    m_range.AttachDispatch(m_sheet.get_Cells(), true);

    m_range.put_ColumnWidth(_variant_t((short)3));
    m_range.put_RowHeight(_variant_t((short)5));

    /////////////////////////////////////////////////////////
    // Fill the Grid color
    Cnterior it;
    _variant_t vrange1, vrange2;
    int excelColorIdx[] = {20,21,22,23}; //excelColorIdx[Grid[x]]
    
    //14*280
    for (int i = 0; i < 14; i++)
    {
        for (int j = 0; j < 280; j++)
        {
            if (pGrid[i * 280 + j])
            {
                //m_range.AttachDispatch(m_sheet.get_Range(_variant_t("A3360"), _variant_t("A3360")));
                m_range.AttachDispatch(m_sheet.get_Range(_variant_t("A1"), _variant_t("A1")));
                //vrange1 = m_range.get_Item(_variant_t((LONG)(-(j+1) * 12+11))/*row*/, _variant_t((LONG)i)/*col*/);
                //vrange2 = m_range.get_Item(_variant_t((LONG)(-(j+1) * 12))/*row*/, _variant_t((LONG)i)/*col*/);
                vrange1 = m_range.get_Item(_variant_t((LONG)((j + 1) * 12 - 11))/*row*/, _variant_t((LONG)i)/*col*/);
                vrange2 = m_range.get_Item(_variant_t((LONG)((j + 1) * 12))/*row*/, _variant_t((LONG)i)/*col*/);
                m_range.AttachDispatch(m_sheet.get_Range(_variant_t(vrange1), _variant_t(vrange2)));


                it.AttachDispatch(m_range.get_Interior());
                it.put_ColorIndex(_variant_t((long)excelColorIdx[pGrid[i * 280 + j]]));
            }
        }

    }


    //////////////////////////////////////////
    // save excel file
    TCHAR  filename_tchar[100];
    CString path;
    LPCTSTR lpsz = (LPCTSTR)path;
    
    lpsz = AfxGetApp()->m_pszHelpFilePath;
    path = lpsz;
    path = path.Left(path.ReverseFind('\\'));

    #ifdef UNICODE
    MultiByteToWideChar(CP_ACP, 0, FileName, -1, filename_tchar, 100);
    #else
    strcpy(filename_tchar, FileName);
    #endif

    path = path + _T('\\') + filename_tchar;

    #if 1
    m_book.SaveCopyAs(_variant_t(path));  //both are OK!!
    #else
    COleVariant VOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);
    m_book.SaveAs(_variant_t(path),
        VOptional, VOptional, VOptional, VOptional, VOptional,
        (long)0, VOptional, VOptional, VOptional, VOptional,
        VOptional);
    #endif

    #if 1
    m_app.put_DisplayAlerts(false); // 不弹出对话框询问是否保存
    #else
    m_app.put_DisplayAlerts(true); // 弹出对话框询问是否保存
    #endif
}

void CexcelAccess::writeExcelAsRb(int * pGrid, char *FileName)
{
    COleVariant vResult;
    COleVariant covOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);

    m_book = m_books.Add(covOptional); // 添加一个工作簿，这里没有open操作，在最后调用SaveCopyAs另存为
    m_app.put_DisplayAlerts(false); // 不弹出对话框询问是否保存
                                    // 得到Worksheets
    m_sheets.AttachDispatch(m_book.get_Worksheets(), true);
    // 得到Worksheet
    m_sheet.AttachDispatch(m_sheets.get_Item(_variant_t((short)(1))));
    // 得到全部Cells
    m_range.AttachDispatch(m_sheet.get_Cells(), true);

    m_range.put_ColumnWidth(_variant_t((short)2));
    m_range.put_RowHeight(_variant_t((short)5));
    /////////////////////////////////////////////////////////
    // Fill the Grid color
    Cnterior it;
    _variant_t vrange1, vrange2;
    int excelColorIdx[] = { 20,21,22,23 }; //excelColorIdx[Grid[x]]

                                           //14*280
    for (int i = 0; i < 14; i++)
    {
        for (int j = 0; j < 280; j++)
        {
            if (pGrid[i * 280 + j])
            {
                //m_range.AttachDispatch(m_sheet.get_Range(_variant_t("A280"), _variant_t("A280")));
                m_range.AttachDispatch(m_sheet.get_Range(_variant_t("A1"), _variant_t("A1")));
                //vrange1 = m_range.get_Item(_variant_t((LONG)(-(j + 1) * 12 + 11))/*row*/, _variant_t((LONG)i)/*col*/);
                //vrange2 = m_range.get_Item(_variant_t((LONG)(-(j + 1) * 12))/*row*/, _variant_t((LONG)i)/*col*/);

                vrange1 = m_range.get_Item(_variant_t((LONG)((j + 1)))/*row*/, _variant_t((LONG)(i+1))/*col*/);
                m_range.AttachDispatch(m_sheet.get_Range(_variant_t(vrange1), _variant_t(vrange1)));


                it.AttachDispatch(m_range.get_Interior());
                it.put_ColorIndex(_variant_t((long)excelColorIdx[pGrid[i * 280 + j]]));
            }
        }

    }


    //////////////////////////////////////////
    // save excel file
    TCHAR  filename_tchar[100];
    CString path;
    LPCTSTR lpsz = (LPCTSTR)path;

    lpsz = AfxGetApp()->m_pszHelpFilePath;
    path = lpsz;
    path = path.Left(path.ReverseFind('\\'));

#ifdef UNICODE
    MultiByteToWideChar(CP_ACP, 0, FileName, -1, filename_tchar, 100);
#else
    strcpy(filename_tchar, FileName);
#endif

    path = path + _T('\\') + filename_tchar;

#if 1
    m_book.SaveCopyAs(_variant_t(path));  //both are OK!!
#else
    COleVariant VOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);
    m_book.SaveAs(_variant_t(path),
        VOptional, VOptional, VOptional, VOptional, VOptional,
        (long)0, VOptional, VOptional, VOptional, VOptional,
        VOptional);
#endif

#if 1
    m_app.put_DisplayAlerts(false); // 不弹出对话框询问是否保存
#else
    m_app.put_DisplayAlerts(true); // 弹出对话框询问是否保存
#endif
}
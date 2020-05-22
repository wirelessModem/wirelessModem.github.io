

#ifndef __EXCEL_H__
#define __EXCEL_H__




#include "CApplication.h"
#include "CWorkbook.h"
#include "CWorkbooks.h"
#include "CWorksheet.h"
#include "CWorksheets.h"
#include "CRange.h"
#include "Cnterior.h"
#include "CBorders.h"
#include "CFont0.h"

#include "comdef.h"
#include "comutil.h"
#include <afxdisp.h> //for COleVariant


class CexcelAccess {
public:
    CexcelAccess();
    virtual ~CexcelAccess();

    void initExcel();
    void releaseExcel();
    
    void writeExcel_example(char *FileName);
    void writeExcelAsRe(int * pGrid,char *FileName);
    void writeExcelAsRb(int * pGrid, char *FileName);

private:
    CApplication m_app;
    CWorksheets m_sheets;
    CWorkbooks m_books;

    CWorkbook m_book;
    CWorksheet m_sheet;
    CRange m_range;
};

/*
CApplication _app;
CWorkbook _workBook;
CWorksheet _workSheet;
CWorksheets workSheets;
CWorkbooks workBooks;
CRange range;
CRange copyFrom;
CRange copyTo;

*/

#endif

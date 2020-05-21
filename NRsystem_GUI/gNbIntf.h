/*
gNB PHY simulation system.
initial Created： 2020.5.19

file name gNbIntf.h

*/

#ifndef __G_NB_INTF_H__
#define __G_NB_INTF_H__




#ifdef __cplusplus
extern "C" {
#endif


extern void gNbTxMain();
extern void gNbRxMain();


extern void saveTxDataAsFiles(char *FileName);


extern void gNbTestMain();


#ifdef __cplusplus
}

#endif


#endif

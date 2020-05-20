/*
gNB PHY simulation system.
initial Created by tangqy(2020.5.19)

file name gNbIntf.h

*/

#ifndef __G_NB_INTF_H__
#define __G_NB_INTF_H__


#ifndef __outVarName__
#define __outVarName__

#define varName(x) #x
#define printExp(exp) cout<<#exp<<"Ϊ:\t\t"<<(exp)<<endl
#define printExpToString(exp) cout<<(string(#exp)+"Ϊ:\t\t")<<(exp).toString()<<endl

#endif

#ifdef __cplusplus
extern "C" {
#endif


extern void gNbTxMain();
extern void gNbRxMain();

extern void gNbTestMain();


#ifdef __cplusplus
}

#endif


#endif

/*
NR PHY simulation system.
initial Created by tangqy(2020.5.19)

file name nrUeIntf.h

*/

#ifndef __NR_UE_INTF_H__
#define __NR_UE_INTF_H__


#ifndef __outVarName__
#define __outVarName__

#define varName(x) #x
#define printExp(exp) cout<<#exp<<"Ϊ:\t\t"<<(exp)<<endl
#define printExpToString(exp) cout<<(string(#exp)+"Ϊ:\t\t")<<(exp).toString()<<endl

#endif

#ifdef __cplusplus
extern "C" {
#endif




extern void nrUeRxMain();


#ifdef __cplusplus
}

#endif


#endif

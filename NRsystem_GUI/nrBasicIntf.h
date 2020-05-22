/*
gNB PHY simulation system.
initial Created： 2020.5.20

file name nrBasicIntf.h

*/

#ifndef __NR_BASIC_INTF_H__
#define __NR_BASIC_INTF_H__


#if 0
//#ifndef __outVarName__
#define __outVarName__

#define varName(x) #x
#define printExp(exp) cout<<#exp<<"Ϊ:\t\t"<<(exp)<<endl
#define printExpToString(exp) cout<<(string(#exp)+"Ϊ:\t\t")<<(exp).toString()<<endl

#endif

#ifdef __cplusplus
extern "C" {
#endif

extern char* getTraceInfoPtr();

extern void resetTraceBuf();

extern void gnrSysInit();
extern int* getNbGridPtr();


#ifdef __cplusplus
}

#endif


#endif

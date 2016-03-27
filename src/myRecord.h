/** @file
********************************************************************************
<PRE>
模块名: 录音及放音模块
文件名: myRecorder.h
相关文件: myRecorder.c
文件实现功能: 录音模块相关函数、变量、类型的声明
作者: 李光程
编译器版本: VS2015
编程方式: ANSI C语言编程
生成日期: 2016-1-8
--------------------------------------------------------------------------------
多线程安全性: <否>[录音及放音分别开启一个线程，需与程序中其它线程同步处理]
异常时安全性: <是/否>[，说明]
--------------------------------------------------------------------------------
备注: <其它说明>
--------------------------------------------------------------------------------
*******************************************************************************/

#include "global.h"

#ifndef _MYRECORD_
#define _MYRECORD_

typedef void * HRECORD;

typedef struct MYRECORD 
{
	LPHWAVEIN  lhWaveIn; //录音句柄
	PBYTE pBuffer[BUFF_NUM];
	PWAVEHDR pWaveHdr[BUFF_NUM];
	PWAVEFORMATEX pWaveform;
} MYRECORD;

typedef struct RECPARAM
{
	HWND hwnd;
	HRECORD myRecord;
} RECPARAM;


//录音相关函数声明
HRECORD CreateRecord(HWND hwnd);

#endif    //_MYRECORD_


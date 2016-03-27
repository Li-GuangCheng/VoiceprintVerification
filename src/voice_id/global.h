#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED

/** @file
********************************************************************************
<PRE>
模块名: 声纹识别
文件名: global.h
相关文件:
文件实现功能: 全局资源声明及定义
作者: 李光程
编译器版本: VS2015
编程方式: ANSI C语言编程
生成日期: 2016-1-8
--------------------------------------------------------------------------------
多线程安全性: <是/否>[，说明]
异常时安全性: <是/否>[，说明]
--------------------------------------------------------------------------------
备注: <其它说明>
--------------------------------------------------------------------------------
*******************************************************************************/
#include "../global.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>

//#define _DEBUG   //DEBUG选项

#define PI   3.1415926L
#define _2PI 6.2831853L


#ifndef BOOL
#define BOOL int
#endif

#ifndef BYTE
#define BYTE unsigned char
#define PBYTE BYTE *
#endif

#ifndef FALSE
#define FALSE 0
#define TRUE  (!FALSE)
#endif

#endif // GLOBAL_H_INCLUDED

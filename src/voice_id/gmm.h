/** @file
********************************************************************************
<PRE>
模块名: 高斯混合模型过程
文件名: gmm.h
相关文件: gmm.c
文件实现功能: 高斯混合模型过程相关函数、变量的声明
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

#ifndef _GMM_H_
#define _GMM_H_

#include "mfcc.h"

//#define DEBUG_GMM

#ifndef DEBUG_GMM
#define M 6  //!< GMM阶数(混合数)8  3
#else
#define M 3
#endif // DEBUG_GMM

/**
 * @brief 高斯混合模型结构
 */
typedef struct GMM
{//结构体内改成动态内存
       void (* f_Init)(struct GMM *, int);
       int m;             //!< 高斯混合数
       double * p;        //!< M组加权系数
       double ** u;    	  //!< M组D维均值
       double ** cMatrix; //!< M个协方差矩阵(D维对角阵)
       void * (* f_CallocGMM)(struct GMM *);
       void (* f_FreeGMM)(struct GMM *);
} GMM;


BOOL GMMs(double ** X, GMM * pGMM, int train_frame_num, int m); // GMM建模过程
BOOL GMM_identify(double ** X, double * value, GMM * pGMM, int frame_num, int m); // 识别过程
void InitGMMClass(GMM * pGMM, int m);
void * CallocGMM(GMM * pGMM); // 分配GMM内存
void FreeGMM(GMM * pGMM); // 释放GMM内存

#endif /* _GMM_H_ */

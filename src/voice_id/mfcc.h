/** @file
********************************************************************************
<PRE>
模块名: mfcc参数的提取
文件名: mfcc.h
相关文件: mfcc.c
文件实现功能: 声明mfcc提取相关函数,定义训练帧长度及特征微量维度
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
#ifndef _MFCC_
#define  _MFCC_

#include <float.h>
#include "FFT2.h"


#define SIGNAL_TIME 5       //!< 训练信号持续时间(s)
#define FRAME_LEN 256       //!< 帧长度

////帧数=音频采样频率*训练信号持续时间/帧长度
//#define FRAME_NUM (SAMPLE_FREQUENCY * SIGNAL_TIME / FRAME_LEN)
#define SILENCE_VALUE   0.016  //!< 静寂状态阈值/帧，取0.016

#define GOOD_FRAME_NUM  1000   //!< 连续大于静寂状态阈值的帧数（可用于训练的最小帧数） 
#define D 20                   //!< MFCC参数向量维度20


/**
 * @brief 语音帧结构
 */
typedef struct VOICEFRAME
{
    COMPX  * pCmpx;
} VOICEFRAME;


BOOL voiceToMFCC(BYTE * pRawVoice, int iSampleNum, double ** MFCC, int train_frame_num);

#endif  //_MFCC_

/*! @file
********************************************************************************
<PRE>
模块名: 声纹识别对象
文件名: voiceprint.h
相关文件: voiceprint.c
文件实现功能: 用户链表及相关操作的定义
作者: 李光程
编译器版本: VS2015
编程方式: ANSI C语言编程
生成日期: 2016-1-8
--------------------------------------------------------------------------------
多线程安全性: <是>
异常时安全性: <是/否>[，说明]
--------------------------------------------------------------------------------
备注: <其它说明>
--------------------------------------------------------------------------------
*******************************************************************************/
#ifndef VOICEPRINT_H_INCLUDED
#define VOICEPRINT_H_INCLUDED

#include "global.h"
#include "voice_id/voiceIdentify.h"
#include "FileDlg.h"
#include "myRecord.h"

typedef enum BUILD_MODE{E_BUILD=0, E_IDENTIFY=1} BUILD_MODE; // GetUsrGMM函数调用方式

/**
 * @brief 建模数据结构
 */
typedef struct VOICE_MODEL
{
	GMM gmm;                       /**< 高斯混合模型 */
	double value[IDENTIFY_NUM][2]; /**< 帧识别阈值：[-][0]是阈值，[-][1]是识别值 */
	int percent;                   /**< 识别范围 */
	int frame_num;                 /**< 训练帧数 */
	int m;                         /**< 高斯混合数 */
	BOOL bValued;                  /**< 标记是否已经建模 */
	FILE * file_stream;            /**< 文件流 */
	TBYTE * pVoice;                /**< 声纹提取缓冲 */
	FILE_CLASS voice_file;         /**< 文件路径 */
	void (* f_Init)(struct VOICE_MODEL *);
    BOOL (* f_GetUsrGMM)(struct VOICE_PRINT *, BUILD_MODE);
}VOICE_MODEL;

/**
 * @brief 声纹结点
 */
typedef struct VOICE_PRINT
{
	void (* f_Init)(struct VOICE_PRINT *);
	VOICE_MODEL voice_mdl;        /**< 声纹模型及识别阈值 */
    HWND hwnd;                    /**< 窗口句柄 */
	HRECORD myRecord;             /**< 录音实例 */   
	HANDLE g_hRecThread;          /**< 录音线程句柄 */
	DWORD g_RecThreadID;
	int rec_frame[IDENTIFY_NUM];  /**< 每一段识别帧数 */
} VOICE_PRINT;


#endif // VOICEPRINT_H_INCLUDED
extern VOICE_PRINT my_voiceprint;

void VoiceModelInit(VOICE_MODEL * this);
void VoicePrintInit(VOICE_PRINT * this);
BOOL GetUsrGMM(VOICE_PRINT * pUsr, BUILD_MODE mod);
void PrintThresholdValue(HWND hwnd); // 打印识别阈值

/*
*********************************************************************************************************
*                                            uC/USB-Device
*                                    The Embedded USB Device Stack
*
*                    Copyright 2004-2020 Silicon Laboratories Inc. www.silabs.com
*
*                                 SPDX-License-Identifier: APACHE-2.0
*
*               This software is subject to an open source license and is distributed by
*                Silicon Laboratories Inc. pursuant to the terms of the Apache License,
*                    Version 2.0 available at www.apache.org/licenses/LICENSE-2.0.
*
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*
*                                        USB DEVICE AUDIO CLASS
*
* Filename : usbd_audio_processing.h
* Version  : V4.06.00
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*********************************************************************************************************
*                                               MODULE
*********************************************************************************************************
*********************************************************************************************************
*/

#ifndef  USBD_AUDIO_PROCESSING_MODULE_PRESENT
#define  USBD_AUDIO_PROCESSING_MODULE_PRESENT


/*
*********************************************************************************************************
*********************************************************************************************************
*                                            INCLUDE FILES
*********************************************************************************************************
*********************************************************************************************************
*/

#include  "../../Source/usbd_core.h"
#include  "usbd_audio.h"


/*
*********************************************************************************************************
*********************************************************************************************************
*                                               EXTERNS
*********************************************************************************************************
*********************************************************************************************************
*/

#ifdef   USBD_AUDIO_PROCESSING_MODULE
#define  USBD_AUDIO_PROCESSING_EXT
#else
#define  USBD_AUDIO_PROCESSING_EXT  extern
#endif


/*
*********************************************************************************************************
*********************************************************************************************************
*                                               DEFINES
*********************************************************************************************************
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*********************************************************************************************************
*                                             DATA TYPES
*********************************************************************************************************
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*********************************************************************************************************
*                                          GLOBAL VARIABLES
*********************************************************************************************************
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*********************************************************************************************************
*                                               MACRO'S
*********************************************************************************************************
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*********************************************************************************************************
*                                         FUNCTION PROTOTYPES
*********************************************************************************************************
*********************************************************************************************************
*/

#if (USBD_AUDIO_CFG_RECORD_EN == DEF_ENABLED)
void             *USBD_Audio_RecordBufGet  (USBD_AUDIO_AS_HANDLE   as_handle,
                                            CPU_INT16U            *p_buf_len);

void              USBD_Audio_RecordRxCmpl  (USBD_AUDIO_AS_HANDLE   as_handle);

void              USBD_Audio_RecordBufFree (USBD_AUDIO_AS_HANDLE   as_handle,
                                            void                  *p_buf);
#endif

#if (USBD_AUDIO_CFG_PLAYBACK_EN == DEF_ENABLED)
void             USBD_Audio_PlaybackTxCmpl (USBD_AUDIO_AS_HANDLE   as_handle);

void             USBD_Audio_PlaybackBufFree(USBD_AUDIO_AS_HANDLE   as_handle,
                                            void                  *p_buf);
#endif

#if (USBD_AUDIO_CFG_STAT_EN == DEF_ENABLED)
USBD_AUDIO_STAT  *USBD_Audio_StatGet       (USBD_AUDIO_AS_HANDLE   as_handle);
#endif


/*
*********************************************************************************************************
*                                      AUDIO STATISTICS MACRO'S
*********************************************************************************************************
*/

#if (USBD_AUDIO_CFG_STAT_EN == DEF_ENABLED)
#define  USBD_AUDIO_STAT_INC(ctr)                   {                                                       \
                                                        (ctr)++;                                            \
                                                    }

#define  USBD_AUDIO_STAT_PROT_INC(ctr)              {                                                       \
                                                        CPU_CRITICAL_ENTER();                               \
                                                        (ctr)++;                                            \
                                                        CPU_CRITICAL_EXIT();                                \
                                                    }

#define  USBD_AUDIO_DRV_STAT_INC(as_handle, ctr)    {                                                       \
                                                        USBD_AUDIO_STAT  *__p_audio_stat;                   \
                                                                                                            \
                                                        __p_audio_stat = USBD_Audio_StatGet((as_handle));   \
                                                        __p_audio_stat->ctr++;                            \
                                                    }

#define  USBD_AUDIO_STAT_DEC(ctr)                   {                                                       \
                                                        (ctr)--;                                            \
                                                    }

#define  USBD_AUDIO_STAT_PROT_DEC(ctr)              {                                                       \
                                                        CPU_CRITICAL_ENTER();                               \
                                                        (ctr)--;                                            \
                                                        CPU_CRITICAL_EXIT();                                \
                                                    }

#define  USBD_AUDIO_STAT_MAX(ctr, max)              {                                                       \
                                                        if ((ctr) > (max)) {                                \
                                                            (max) = (ctr);                                  \
                                                        }                                                   \
                                                    }

#define  USBD_AUDIO_STAT_PROT_MAX(ctr, max)         {                                                       \
                                                        CPU_CRITICAL_ENTER();                               \
                                                        if ((ctr) > (max)) {                                \
                                                            (max) = (ctr);                                  \
                                                        }                                                   \
                                                        CPU_CRITICAL_EXIT();                                \
                                                    }

#define  USBD_AUDIO_STAT_MIN(ctr, min)              {                                                       \
                                                        if ((ctr) < (min)) {                                \
                                                            (min) = (ctr);                                  \
                                                        }                                                   \
                                                    }

#define  USBD_AUDIO_STAT_PROT_MIN(ctr, min)         {                                                       \
                                                        CPU_CRITICAL_ENTER();                               \
                                                        if ((ctr) < (min)) {                                \
                                                            (min) = (ctr);                                  \
                                                        }                                                   \
                                                        CPU_CRITICAL_EXIT();                                \
                                                    }

#define  USBD_AUDIO_STAT_ADD(ctr, add)              {                                                       \
                                                        (ctr) += (add);                                     \
                                                    }

#define  USBD_AUDIO_STAT_RESET(ctr)                 {                                                       \
                                                        (ctr) = 0u;                                         \
                                                    }

#else
#define  USBD_AUDIO_STAT_INC(ctr)
#define  USBD_AUDIO_STAT_PROT_INC(ctr)
#define  USBD_AUDIO_DRV_STAT_INC(as_handle, ctr)
#define  USBD_AUDIO_STAT_DEC(ctr)
#define  USBD_AUDIO_STAT_PROT_DEC(ctr)
#define  USBD_AUDIO_STAT_MAX(ctr, max)
#define  USBD_AUDIO_STAT_PROT_MAX(ctr, max)
#define  USBD_AUDIO_STAT_ADD(ctr, add)
#define  USBD_AUDIO_STAT_RESET(ctr)
#endif


/*
*********************************************************************************************************
*********************************************************************************************************
*                                        CONFIGURATION ERRORS
*********************************************************************************************************
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*********************************************************************************************************
*                                             MODULE END
*********************************************************************************************************
*********************************************************************************************************
*/

#endif

#ifndef _TCLC_MEMORY_H
#define _TCLC_MEMORY_H

#include "types.h"
#include "config.h"
#include "object.h"

#if (TCLC_MEMORY_ENABLE)

#define MEM_ERR_NONE               (0x0U)
#define MEM_ERR_FAULT              (0x1<<1)                      /* һ���Դ���                 */
#define MEM_ERR_UNREADY            (0x1<<2)                      /* �ڴ�����ṹδ��ʼ��       */
#define MEM_ERR_NO_MEM             (0x1<<3)                      /* �ɷ����ڴ治��             */
#define MEM_ERR_BAD_ADDR           (0x1<<4)                      /* �ͷŵ��ڴ��ַ�Ƿ�         */
#define MEM_ERR_DBL_FREE           (0x1<<5)                      /* �ͷŵ��ڴ�û�б�����       */
#define MEM_ERR_POOL_FULL          (0x1<<6)                      /* �ͷŵ��ڴ�û�б�����       */

#define MEM_PROP_READY (0x1 << 0)

#endif

#endif /* _TCLC_MEMORY_H */
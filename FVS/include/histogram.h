/*#############################################################################
 * �ļ�����histogram.h
 * ���ܣ�  ʵ����ָ��ֱ��ͼ�Ĳ���
 * modified by  PRTsinghua@hotmail.com
#############################################################################*/

#if !defined FVS__HISTOGRAM_HEADER__INCLUDED__
#define FVS__HISTOGRAM_HEADER__INCLUDED__

/* �������Ͷ��� */
#include "fvstypes.h"
#include "image.h"


/* �������Щ�ӿ�ʵ����˽�еģ�����Ϊ�û���֪��ʹ�������ṩ�ĺ�������ֱ��ͼ */
typedef FvsHandle_t FvsHistogram_t;


/******************************************************************************
  * ���ܣ�����һ���µ�ֱ��ͼ����
  * ��������
  * ���أ�ʧ�ܷ��ؿգ����򷵻�ֱ��ͼ����
******************************************************************************/
FvsHistogram_t HistogramCreate(void);


/******************************************************************************
  * ���ܣ��ƻ�һ�����ڵ�ֱ��ͼ����
  * ������histogram ֱ��ͼ����ָ��
  * ���أ�������
******************************************************************************/
void HistogramDestroy(FvsHistogram_t histogram);


/******************************************************************************
  * ���ܣ�����һ�����ڵ�ֱ��ͼ����Ϊ0
  * ������histogram ֱ��ͼ����ָ��
  * ���أ�������
******************************************************************************/
FvsError_t HistogramReset(FvsHistogram_t histogram);


/******************************************************************************
  * ���ܣ�����һ��8-bitͼ���ֱ��ͼ
  * ������histogram ֱ��ͼ����ָ��
  *       image     ͼ��ָ��
  * ���أ�������
******************************************************************************/
FvsError_t HistogramCompute(FvsHistogram_t histogram, const FvsImage_t image);


/******************************************************************************
  * ���ܣ�����һ��ֱ��ͼ����ľ�ֵ
  * ������histogram ֱ��ͼ����ָ��
  * ���أ���ֵ
******************************************************************************/
FvsByte_t HistogramGetMean(const FvsHistogram_t histogram);


/******************************************************************************
  * ���ܣ�����һ��ֱ��ͼ����ķ���
  * ������histogram ֱ��ͼ����ָ��
  * ���أ�����
******************************************************************************/
FvsUint_t HistogramGetVariance(const FvsHistogram_t histogram);


#endif /* FVS__HISTOGRAM_HEADER__INCLUDED__ */

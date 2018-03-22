/*#############################################################################
 * �ļ�����import.c
 * ���ܣ�  һЩ������ͼ�����
 * modified by  PRTsinghua@hotmail.com
#############################################################################*/


#include "import.h"

#include <stdio.h>
#include <magick/api.h>


/******************************************************************************
  * ���ܣ����ļ��м���ָ��ͼ��
  * ������image       ָ��ͼ��
  *       filename    �ļ���
  * ���أ�������
******************************************************************************/
FvsError_t FvsImageImport(FvsImage_t image, const FvsString_t filename)
{
    ExceptionInfo exception;
    Image*        magicimage;
    ImageInfo*    magicinfo;
    
    FvsError_t ret = FvsOK;
    FvsByte_t*    buffer;
    FvsInt_t      pitch;
    FvsInt_t      height;
    FvsInt_t      width;
    FvsInt_t i;
    
    /* ��ʼ�� Magick ���� */
    InitializeMagick(".");
    GetExceptionInfo(&exception);

    /* ����һ���յ� imageinfo */
    magicinfo = CloneImageInfo((ImageInfo*)NULL);

    /* �����ļ��� */
    (void)strcpy(magicinfo->filename, filename);

    /* ��ͼ�� */
    magicimage = ReadImage(magicinfo, &exception);
    if (exception.severity!=UndefinedException)
      	CatchException(&exception);
    if (magicimage!=(Image*)NULL)
    {
		ret = ImageSetSize(image,
	    	(FvsInt_t)magicimage->columns,
	    	(FvsInt_t)magicimage->rows);
		if (ret==FvsOK)
		{
	    	/* ��û����� */
	    	buffer = ImageGetBuffer(image);
	    	pitch  = ImageGetPitch(image);
	    	height = ImageGetHeight(image);
	    	width  = ImageGetWidth(image);
	    
	    	/* ��һ�� */
	    	NormalizeImage(magicimage);
	
	    	/* �������� */
	    	for (i=0; i<height; i++)
	    	{
				ExportImagePixels(magicimage, 0, i, width, 1, "I", CharPixel,
				buffer+i*pitch, &exception);
	    	}
		}
        DestroyImage(magicimage);
    }
    else
        ret = FvsFailure;
    
    /* ���� */
    DestroyImageInfo(magicinfo);
    DestroyExceptionInfo(&exception);
    DestroyMagick();
    
    return ret;
}




/*#############################################################################
 * 文件名：import.c
 * 功能：  一些基本的图像操作
 * modified by  PRTsinghua@hotmail.com
#############################################################################*/


#include "import.h"

#include <stdio.h>
#include <magick/api.h>


/******************************************************************************
  * 功能：从文件中加载指纹图像
  * 参数：image       指纹图像
  *       filename    文件名
  * 返回：错误编号
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
    
    /* 初始化 Magick 环境 */
    InitializeMagick(".");
    GetExceptionInfo(&exception);

    /* 创建一个空的 imageinfo */
    magicinfo = CloneImageInfo((ImageInfo*)NULL);

    /* 设置文件名 */
    (void)strcpy(magicinfo->filename, filename);

    /* 读图像 */
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
	    	/* 获得缓冲区 */
	    	buffer = ImageGetBuffer(image);
	    	pitch  = ImageGetPitch(image);
	    	height = ImageGetHeight(image);
	    	width  = ImageGetWidth(image);
	    
	    	/* 归一化 */
	    	NormalizeImage(magicimage);
	
	    	/* 拷贝数据 */
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
    
    /* 清理 */
    DestroyImageInfo(magicinfo);
    DestroyExceptionInfo(&exception);
    DestroyMagick();
    
    return ret;
}




/***
*opencvlib.h - definitions and declarations for math library
*
*       Copyright (c) Zhang He. All rights reserved.
*
*Purpose:
*       This file contains constant definitions and external subroutine
*       declarations for the math subroutine library.
*       [ANSI/System V]
*
*       [Public]
*
****/

#ifndef _INC_OPENCV249
#define _INC_OPENCV249

//include opencv lib
#ifdef _DEBUG
#pragma comment(lib, "opencv_core249d")
#pragma comment(lib, "opencv_imgproc249d")
#pragma comment(lib, "opencv_highgui249d")
#pragma comment(lib, "opencv_legacy249d")
#pragma comment(lib, "opencv_calib3d249d")
#pragma comment(lib, "opencv_stitching249d")
#pragma comment(lib, "opencv_features2d249d")
#pragma comment(lib, "opencv_gpu249d")
#pragma comment(lib, "opencv_nonfree249d")
#pragma comment(lib, "opencv_ts249d")
#pragma comment(lib, "opencv_photo249d")
#else 
#pragma comment(lib, "opencv_core249")
#pragma comment(lib, "opencv_imgproc249")
#pragma comment(lib, "opencv_highgui249")
#pragma comment(lib, "opencv_legacy249")
#pragma comment(lib, "opencv_calib3d249")
#pragma comment(lib, "opencv_contrib249")
#pragma comment(lib, "opencv_core249")
#pragma comment(lib, "opencv_features2d249")
#pragma comment(lib, "opencv_flann249")
#pragma comment(lib, "opencv_gpu249")
#pragma comment(lib, "opencv_highgui249")
#pragma comment(lib, "opencv_imgproc249")
#pragma comment(lib, "opencv_legacy249")
#pragma comment(lib, "opencv_ml249")
#pragma comment(lib, "opencv_objdetect249")
#pragma comment(lib, "opencv_ts249")
#pragma comment(lib, "opencv_video249")
#pragma comment(lib, "opencv_stitching249")
#pragma comment(lib, "opencv_nonfree249")
#endif

#endif
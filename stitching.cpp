/*M///////////////////////////////////////////////////////////////////////////////////////
//
//  IMPORTANT: READ BEFORE DOWNLOADING, COPYING, INSTALLING OR USING.
//
//  By downloading, copying, installing or using the software you agree to this license.
//  If you do not agree to this license, do not download, install,
//  copy or use the software.
//
//
//                          License Agreement
//                For Open Source Computer Vision Library
//
// Copyright (C) 2000-2008, Intel Corporation, all rights reserved.
// Copyright (C) 2009, Willow Garage Inc., all rights reserved.
// Third party copyrights are property of their respective owners.
//
// Redistribution and use in source and binary forms, with or without modification,
// are permitted provided that the following conditions are met:
//
//   * Redistribution's of source code must retain the above copyright notice,
//     this list of conditions and the following disclaimer.
//
//   * Redistribution's in binary form must reproduce the above copyright notice,
//     this list of conditions and the following disclaimer in the documentation
//     and/or other materials provided with the distribution.
//
//   * The name of the copyright holders may not be used to endorse or promote products
//     derived from this software without specific prior written permission.
//
// This software is provided by the copyright holders and contributors "as is" and
// any express or implied warranties, including, but not limited to, the implied
// warranties of merchantability and fitness for a particular purpose are disclaimed.
// In no event shall the Intel Corporation or contributors be liable for any direct,
// indirect, incidental, special, exemplary, or consequential damages
// (including, but not limited to, procurement of substitute goods or services;
// loss of use, data, or profits; or business interruption) however caused
// and on any theory of liability, whether in contract, strict liability,
// or tort (including negligence or otherwise) arising in any way out of
// the use of this software, even if advised of the possibility of such damage.
//
//M*/

#include <iostream>
#include <fstream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/stitching/stitcher.hpp"
#include <opencv2/photo/photo.hpp>
#include <opencv249lib.h>

using namespace std;
using namespace cv;

bool try_use_gpu = true;
vector<Mat> imgs;
string result_name = "result.jpg";

void printUsage();
int parseCmdArgs(int argc, char** argv);

int main(int argc, char* argv[])
{
    int retval = parseCmdArgs(argc, argv);
    if (retval) return -1;

    Mat pano;
    Stitcher stitcher = Stitcher::createDefault(try_use_gpu);
    Stitcher::Status status = stitcher.stitch(imgs, pano);

    if (status != Stitcher::OK)
    {
        cout << "Can't stitch images, error code = " << int(status) << endl;
        return -1;
    }

	imshow("pano", pano);
	waitKey();
    imwrite(result_name, pano);
    return 0;
}

//int main()
//{
//	Mat image = imread("man.jpg");
//	vector<KeyPoint> keyPoints;
//	SimpleBlobDetector::Params params;
//	params.minThreshold = 120;
//	params.maxThreshold = 250;
//	params.thresholdStep = 8;
//	params.minConvexity = .5f;
//	//params.minInertiaRatio = .05f;
//	params.minDistBetweenBlobs = 2;
//	params.minArea =  5;
//	params.maxArea = 20;
//	params.minCircularity = 0.6;
//	params.maxCircularity = 1.0;
//	params.blobColor = 0;
//
//	SimpleBlobDetector blobDetect(params);
//	blobDetect.create("SimpleBlob");
//	blobDetect.detect(image, keyPoints);
//	cout << keyPoints.size() << endl;
//	drawKeypoints(image, keyPoints, image, Scalar(255, 0, 0));
//
//	namedWindow("blobs");
//	imshow("blobs", image);
//	waitKey();
//	return 0;
//}

void printUsage()
{
    cout <<
        "Rotation model images stitcher.\n\n"
        "stitching img1 img2 [...imgN]\n\n"
        "Flags:\n"
        "  --try_use_gpu (yes|no)\n"
        "      Try to use GPU. The default value is 'no'. All default values\n"
        "      are for CPU mode.\n"
        "  --output <result_img>\n"
        "      The default is 'result.jpg'.\n";
}


int parseCmdArgs(int argc, char** argv)
{
    if (argc == 1)
    {
        printUsage();
        return -1;
    }
    for (int i = 1; i < argc; ++i)
    {
        if (string(argv[i]) == "--help" || string(argv[i]) == "/?")
        {
            printUsage();
            return -1;
        }
        else if (string(argv[i]) == "--try_use_gpu")
        {
            if (string(argv[i + 1]) == "no")
                try_use_gpu = false;
            else if (string(argv[i + 1]) == "yes")
                try_use_gpu = true;
            else
            {
                cout << "Bad --try_use_gpu flag value\n";
                return -1;
            }
            i++;
        }
        else if (string(argv[i]) == "--output")
        {
            result_name = argv[i + 1];
            i++;
        }
        else
        {
            Mat img = imread(argv[i]);
            if (img.empty())
            {
                cout << "Can't read image '" << argv[i] << "'\n";
                return -1;
            }
            imgs.push_back(img);
        }
    }
    return 0;
}

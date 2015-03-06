#include <cv.h>
#include <highgui.h>
#include <stdio.h>

void out(IplImage *Image1)
{
	printf("The IplImage Size is : %d\n", sizeof(IplImage));
	printf("The nSize            is : %d\n", Image1->nSize);
	printf("The width           is : %d\n", Image1->width);
	printf("The height          is : %d\n", Image1->height);
	printf("The nChannels     is : %d\n", Image1->nChannels);
	printf("The depth           is : %d\n", Image1->depth);
	printf("The widthStep     is : %d\n", Image1->widthStep);
	printf("The imageSize     is : %d\n", Image1->imageSize);
	printf("The dataOrder     is : %d\n", Image1->dataOrder);
	printf("The origin           is : %d\n", Image1->origin);
	printf("The align            is : %d\n", Image1->align);
}
int filter(IplImage	*Image1)
{
	for (int i = 0; i<Image1->height; i++)
	{
		for (int j = 0; j<Image1->widthStep; j = j + 3)
		{
			char &b = (Image1->imageData[i*Image1->widthStep + j]), &g = Image1->imageData[i*Image1->widthStep + j + 1], &r = Image1->imageData[i*Image1->widthStep + j+2]; 
			b = b < 96 ? b : 0;
			g = g < 128 ? g : 0;
			r = r < 128 ? r : 0;
		//	Image1->imageData[i*Image1->widthStep + j] = 0;
		//	Image1->imageData[i*Image1->widthStep + j + 1] = 0;
		//	Image1->imageData[i*Image1->widthStep + j + 2] = 255;
		}
	}
	return 0;
}
int ImageAdjust(IplImage* src, IplImage* dst, double low, double high)
{
	if (low < 0 || high > 1 || low > high)
		return -1;
	low *= 255;
	high *= 255;
	double err_in = high - low;
	double err_out = 255;

	int x, y;
	double val;

	// intensity transform
	for (y = 0; y < src->height; y++)
	{
		for (x = 0; x < src->widthStep; x++)
		{
			val = ((uchar*)(src->imageData + src->widthStep*y))[x];
			if (val > 255) val = 255; if (val < 0) val = 0; // Make sure src is in the range [low,high]
			if (val >= low && val <= high)	val = (val - low) / err_in * 255;
			((uchar*)(dst->imageData + dst->widthStep*y))[x] = (uchar)val;
		}
	}
	return 0;
}
int fun(int n, double S[], double SS[])
{
	int i, s = 19;
	double sum[1000] = { 0 };
	for (i = 1; i <= n; i++)
	{
		sum[i] = sum[i - 1] + S[i];
	}
	int cnt = 0, a = 1;;
	for (i = 1; i <= s; i += 2)
	{
		SS[cnt++] = sum[i] / i;
		//printf("%.2lf\n", sum[i] / i);
	}
	for (i = 2; i + s - 1 <= n; i++)
	{
		SS[cnt++] = (sum[i + s - 1] - sum[i - 1]) / s;
		//printf("%.2lf\n", );
	}
	for (i++; i <= n; i += 2)
	{
		SS[cnt++] = (sum[n] - sum[i - 1]) / (n - i + 1);
		//printf("%.2lf\n", ((double));
	}
	return 0;
}
int main()
{
	IplImage *img = cvLoadImage("222.jpg", 1);
	//out(img);
	filter(img);
	// 灰度图  
	IplImage *gray = cvCreateImage(cvGetSize(img), img->depth, 1);
	cvCvtColor(img, gray, CV_BGR2GRAY);
	img = gray;	
	out(gray);
	ImageAdjust(img, gray, 0.1, 0.6);
	img = gray;
	/*二值化操作*/
	IplImage *biimg = cvCreateImage(cvGetSize(img), img->depth, 1);
	cvThreshold(img, biimg, 1, 255, CV_THRESH_BINARY);
	img = biimg;

	/*腐蚀*/
	IplImage *temp = cvCreateImage(cvGetSize(img), img->depth, 1);
	int mask[9] = { 0, 1, 0, 1, 1, 1, 0, 1, 0};
	IplConvKernel *element = cvCreateStructuringElementEx(3, 3, 1, 1, CV_SHAPE_CUSTOM, mask);
	cvErode(img, temp, element, 1);
	int mask2[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	element = cvCreateStructuringElementEx(3, 3, 1, 1, CV_SHAPE_CUSTOM, mask);
	cvErode(temp, img, element, 1);
	img = temp;
	
	cvSaveImage("out.jpg", img);

	/*水平和垂直投影*/
	int m = img->width, n = img->height;
	double S[1000] = { 0 }, SS[1000] = { 0 };
	//double * S = new double[n+10]{ 0 }, *SS = new double[n+10]{0};
	out(img);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			S[i] += ((uchar*)(img->imageData + img->widthStep*j))[i];
	}
	fun(n, S, SS);
	int x1 = 0, x2 = 0;


	//求垂直方向区间
	for (int i = n / 2 - 1; i <  n - 35; i++)
	{
		if (SS[i] - SS[i + 35] > 16)
		{
			if (x2 <= 0)
				x2 = i + 35;
		}
		if (SS[i] - SS[i + 35] < -16)
		{
			if (x1 <= 0)
				x1 = i + 35;
		}
		if ((x1 > 0) & (x2 > 0))
			break;
	}
	/*求水平投影*/
	out(img);

	for (int i = 0; i < n; i++)
	{
		S[i] = 0;
		for (int j = 0; j < m; j++)
		{
			S[i] += ((uchar*)(img->imageData + img->widthStep*i))[j];
		}
	}
	fun(m, S, SS);
	int y1 = 0, y2 = 0;
	for (int i = 0; i < m - 40; i++)
	{
		if (SS[i] - SS[i + 23] > 22)
		{
			if (y2 <= 0)
				y2 = i + 23;
		}
		if (SS[i] - SS[i + 23] < -22)
		{
			if (y2 <= 0)
			{
				y1 = i + 23;
			}
		}
		if ((y1 > 0) & (y2 > 0))
			break;
	}
	x1 = x1 - 35;
	x2 = x1 + 300;
	y1 = y1 - 23;
	y2 = y2 + 23;

	if (y1 < 0)	y1 = 0;



	
	CvSize size = cvSize(y2-y1 + 1, x2-x1+2);
	IplImage *outimg = cvCreateImage(size, IPL_DEPTH_8U, 1);
	for (int r = 0; y1 <= y2; y1++, r++)
	{
		int  c = 0, tmp = x1;
		for (x1 = tmp; x1 <= x2; x1++, c++)
		{
			((uchar*)(outimg->imageData + outimg->widthStep*r))[c] = ((uchar*)(img->imageData + img->widthStep*y1))[x1];

		}
	}
	cvSaveImage("out.jpg", outimg);	
	cvNamedWindow("blue", 1);
	cvShowImage("blue", img);
	cvWaitKey(0);
	cvReleaseImage(&img);
	cvDestroyWindow("blue");

}
/*
IplImage *Image1;

Image1 = cvCreateImage(ImageSize1, IPL_DEPTH_8U, 3);

out(Image1);

uchar Blue[240][320];
uchar Green[240][320];
uchar Red[240][320];


cvNamedWindow("Red", 1);
cvShowImage("Red", Image1);
cvWaitKey(0);

cvReleaseImage(&Image1);*/
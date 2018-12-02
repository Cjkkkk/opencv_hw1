#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main(){
    // Create a VideoCapture object and open the input file
    // If the input is the web camera, pass 0 instead of the video file name
    VideoCapture cap("1.mp4");
    // Check if camera opened successfully
    if(!cap.isOpened()){
        cout << "Error opening video stream or file" << endl;
        return -1;
    }
    //获得高度和宽度
    int width = (int)cap.get(CV_CAP_PROP_FRAME_WIDTH);
    int height = (int)cap.get(CV_CAP_PROP_FRAME_HEIGHT);
    double frame_rate = cap.get(CV_CAP_PROP_FPS);
    double fourcc = cap.get(CV_CAP_PROP_FOURCC);
    Mat name=imread("7.png",IMREAD_UNCHANGED);
    cout << width << height << endl;
    // 创建videowriter
    VideoWriter writer("output.mp4", fourcc, frame_rate, Size(width, height), true);
    CvFont font;
    cvInitFont(&font,CV_FONT_HERSHEY_COMPLEX, 0.5, 0.5, 1, 2, 8);
    while(1){
        Mat frame;
        // Capture frame-by-frame
        cap >> frame;
        // If the frame is empty, break immediately
        if (frame.empty())
            break;
        // Display the resulting frame

        putText(frame, "3160104210", cvPoint(30,height - 30),
                FONT_HERSHEY_TRIPLEX, 1, cvScalar(200,200,250), 1, CV_AA);
        name.copyTo(frame(cv::Rect(10,10,name.cols, name.rows)));
        imshow( "Frame", frame );
        writer << frame;
        // Press  ESC on keyboard to exit
        char c=(char)waitKey(25);
        if(c==27)
            break;
    }
    // When everything done, release the video capture object
    cap.release();
    writer.release();
    // Closes all the frames
    destroyAllWindows();
    return 0;
}
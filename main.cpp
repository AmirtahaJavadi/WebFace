#include <opencv2/opencv.hpp>
using namespace cv;

int main() {
    // Load face cascade classifier
    CascadeClassifier faceCascade;
    if(!faceCascade.load("/usr/share/opencv4/haarcascades/haarcascade_frontalface_default.xml")) {
        printf("Error loading face cascade\n");
        return -1;
    }

    VideoCapture cap(0);
    if(!cap.isOpened()) return -1;

    Mat frame, gray;
    std::vector<Rect> faces;

    while(true) {
        cap >> frame;
        cvtColor(frame, gray, COLOR_BGR2GRAY);
        equalizeHist(gray, gray);

        // Detect faces
        faceCascade.detectMultiScale(gray, faces, 1.1, 3, 0, Size(30, 30));

        // Draw rectangles around faces
        for(const auto& face : faces) {
            rectangle(frame, face, Scalar(0, 255, 0), 2);
        }

        imshow("Face Detection", frame);
        if(waitKey(30) >= 0) break;
    }
    
    return 0;
}
#include <iostream>
#include <vector>
#include <opencv2/core.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/core/persistence.hpp>
#include <opencv2/core/affine.hpp>
#include <opencv2/ccalib/omnidir.hpp>

using namespace std;
 
 /* @brief Perform omnidirectional camera calibration, the default depth of outputs is CV_64F.
    @param objectPoints Vector of vector of Vec3f object points in world (pattern) coordinate.
    It also can be vector of Mat with size 1xN/Nx1 and type CV_32FC3. Data with depth of 64_F is also acceptable.
    @param imagePoints Vector of vector of Vec2f corresponding image points of objectPoints. It must be the same
    size and the same type with objectPoints.
    @param size Image size of calibration images.
    @param K Output calibrated camera matrix.
    @param xi Output parameter xi for CMei's model
    @param D Output distortion parameters \f$(k_1, k_2, p_1, p_2)\f$
    @param rvecs Output rotations for each calibration images
    @param tvecs Output translation for each calibration images
    @param flags The flags that control calibrate
    @param criteria Termination criteria for optimization
    @param idx Indices of images that pass initialization, which are really used in calibration. So the size of rvecs is the
    same as idx.total().
    */


int main()
{
  // Load data
  cv::FileStorage fs("/home/joel/repo/hello_calibration/omni_calib_data.xml", cv::FileStorage::READ);
  std::vector<cv::Mat_<double>>  objectPoints, imagePoints;
  cv::Size imgSize;
  fs["objectPoints"] >> objectPoints;
  fs["imagePoints"] >> imagePoints;
    fs["imageSize"] >> imgSize;
for (int i=0; i < 16; i++)
{
  std::cout << "objectPoint.size() : " << objectPoints[i].size() << "imagePoint.size() : " << imagePoints[i].size() << std::endl; 
}
  
  // Run calibration and store data

  cv::Mat K, xi, D, idx;
  int flags = 0;
  cv::TermCriteria criteria(cv::TermCriteria::COUNT + cv::TermCriteria::EPS, 200, 0.0001);

 /* std::vector<cv::Mat> rvecs, tvecs;
  double rms = cv::omnidir::calibrate(objectPoints, imagePoints, imgSize, K, xi, D, rvecs, tvecs, flags, criteria, idx);

  
  // Store to file
  std::cout << "----------------------------------------------------------------" << std::endl;
  std::cout << "K-value     : " << K << std::endl;
  std::cout << "xi-value    : " << xi << std::endl;
  std::cout << "D-value     : " << D << std::endl;
  //std::cout << rvecs << std::endl;
  //std::cout << tvecs << std::endl;
  std::cout << "idx-value   : " << idx << std::endl;
  std::cout << "----------------------------------------------------------------" << std::endl;
*/
  return 0;
  
}

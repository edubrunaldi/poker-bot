//
// Created by xima on 31/07/19.
//

#include "../../includes/BaseClasses/BaseImageCompare.hpp"

/**
 * Compara se uma imagem esta contindo na outra
 * @Params largestImage Imagem original a se comparar
 * @Params smallerImage Imagem recortada para ver se tem na largestImage
 * @Params threshold % de garantia que o smallerImage esta dentro do largestImage (de 0.0 a 1.0)
 */
bool BaseImageCompare::compare(cv::Mat *largestImage, std::unique_ptr<cv::Mat>& smallerImage, double threshold) {
  cv::Mat result;
  cv::Mat fixedImgs = cv::Mat(*largestImage);
  cv::Mat cropImg = cv::Mat(*smallerImage);

  //deixa cinza as duas imagens
//  cv::cvtColor(*largestImage, *largestImage, cv::ColorConversionCodes::COLOR_BGR2GRAY);
//  cv::cvtColor(*smallerImage, *smallerImage, cv::ColorConversionCodes::COLOR_BGR2GRAY);
  cv::cvtColor(fixedImgs, fixedImgs, cv::ColorConversionCodes::COLOR_BGR2GRAY);
  cv::cvtColor(cropImg, cropImg, cv::ColorConversionCodes::COLOR_BGR2GRAY);

  // Create the result matrix
//  int result_cols = (*largestImage).cols - (*smallerImage).cols + 1;
//  int result_rows = (*largestImage).rows - (*smallerImage).rows + 1;
//  result.create(result_rows, result_cols, CV_32FC1);

  // Do the matcing and normalize
  cv::matchTemplate(fixedImgs, cropImg, result, cv::TM_CCOEFF_NORMED);

  // Localizing the best match with minmaxLoc
  double minVal, maxVal;
  cv::Point minLoc, maxLoc;
  cv::minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc, cv::Mat());

  return maxVal >= threshold;
}

bool BaseImageCompare::compare(std::unique_ptr<cv::Mat>& largestImage, std::unique_ptr<cv::Mat>& smallerImage, double threshold) {
  cv::Mat result;
  cv::Mat fixedImgs = cv::Mat(*largestImage);
  cv::Mat cropImg = cv::Mat(*smallerImage);

  //deixa cinza as duas imagens
//  cv::cvtColor(*largestImage, *largestImage, cv::ColorConversionCodes::COLOR_BGR2GRAY);
//  cv::cvtColor(*smallerImage, *smallerImage, cv::ColorConversionCodes::COLOR_BGR2GRAY);
  cv::cvtColor(fixedImgs, fixedImgs, cv::ColorConversionCodes::COLOR_BGR2GRAY);
  cv::cvtColor(cropImg, cropImg, cv::ColorConversionCodes::COLOR_BGR2GRAY);

  // Create the result matrix
//  int result_cols = (*largestImage).cols - (*smallerImage).cols + 1;
//  int result_rows = (*largestImage).rows - (*smallerImage).rows + 1;
//  result.create(result_rows, result_cols, CV_32FC1);

  // Do the matcing and normalize
  cv::matchTemplate(fixedImgs, cropImg, result, cv::TM_CCOEFF_NORMED);

  // Localizing the best match with minmaxLoc
  double minVal, maxVal;
  cv::Point minLoc, maxLoc;
  cv::minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc, cv::Mat());

  return maxVal >= threshold;
}
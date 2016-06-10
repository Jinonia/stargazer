//
// Created by bandera on 28.03.16.
//

#pragma once

#include "CoordinateTransformations.h"
#include "StargazerConfig.h"
#include "StargazerTypes.h"
#include "internal/CostFunction.h"
#include <string>

namespace stargazer {

class Localizer {

public:
  Localizer(std::string cfgfile);

  ~Localizer(){};

  void UpdatePose(std::vector<Landmark> img_landmarks);

  const pose_t &getPose() const { return ego_pose; };

private:
  std::map<int, Landmark> landmarks;
  camera_params_t camera_intrinsics;
  pose_t ego_pose;
  ceres::Problem problem;

  bool is_initialized;

  void ClearResidualBlocks();
  void AddResidualBlocks(std::vector<Landmark> img_landmarks);
  void SetCameraParamsConstant();
  void Optimize();
};

} // namespace stargazer

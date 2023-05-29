// Copyright 2021 ros2_control Development Team
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef DIFFDRIVE_STM32F446RE__DIFFBOT_SYSTEM_HPP_
#define DIFFDRIVE_STM32F446RE__DIFFBOT_SYSTEM_HPP_

#include <memory>
#include <string>
#include <vector>

#include "hardware_interface/base_interface.hpp"
#include "hardware_interface/handle.hpp"
#include "hardware_interface/hardware_info.hpp"
#include "hardware_interface/system_interface.hpp"
#include "hardware_interface/types/hardware_interface_return_values.hpp"
#include "hardware_interface/types/hardware_interface_status_values.hpp"
#include "rclcpp/macros.hpp"
#include "diffdrive_stm32f446re/visibility_control.h"

namespace diffdrive_stm32f446re_hardware
{
class DiffBotSystemHardware
: public hardware_interface::BaseInterface<hardware_interface::SystemInterface>
{

struct Config
{
  std::string left_wheel_name ="";
  std::string right_wheel_name = "";
  float loop_rate = 0.0;
  int enc_counts_per_rev = 0;
  // I think those are for Arduino
  // int baud_rate = 0;
  // std::string device = "";
  // int timeout_ms = 0; 
};

public:
  RCLCPP_SHARED_PTR_DEFINITIONS(DiffBotSystemHardware);

  DIFFDRIVE_STM32F446RE_PUBLIC
  hardware_interface::return_type configure(const hardware_interface::HardwareInfo & info) override;

  DIFFDRIVE_STM32F446RE_PUBLIC
  std::vector<hardware_interface::StateInterface> export_state_interfaces() override;

  DIFFDRIVE_STM32F446RE_PUBLIC
  std::vector<hardware_interface::CommandInterface> export_command_interfaces() override;

  DIFFDRIVE_STM32F446RE_PUBLIC
  hardware_interface::return_type start() override;

  DIFFDRIVE_STM32F446RE_PUBLIC
  hardware_interface::return_type stop() override;

  DIFFDRIVE_STM32F446RE_PUBLIC
  hardware_interface::return_type read() override;

  DIFFDRIVE_STM32F446RE_PUBLIC
  hardware_interface::return_type write() override;

private:
  Config cfg_;
};

}  // namespace diffdrive_stm32f446re_hardware

#endif  // DIFFDRIVE_STM32F446RE__DIFFBOT_SYSTEM_HPP_

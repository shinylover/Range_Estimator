# 简要介绍
* 本项目是基于模型开发的思想，做一个距离测量系统。使用的技术栈为：Simulink+Gtest+Trampoline
* A1_Project 文件夹是Simulink项目
* A2_C_code  是基于Simulink模型自动生成的C代码
* A3_Gtest   是基于生成的C代码写的测试文件，有生成Coverage Report，有Gtest和Simulink_Test两部分
* A4_tramponline  在linux虚拟平台上测试代码，代码有问题，并未通过
* A5_Arduino  使用Simulink+Arduino Uno硬件进行仿真测试，信号源由Simulink提供，控制算法由Simulink提供，输出为Aruduino Uno的Pin13针脚。还未完成，正在开发。
* A6_Report   一个课程报告
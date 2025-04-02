# VHIT Motor Control Platform
----
## Introduction
This is the repository that includes the motor control algorithm for the Electric Oil Pump (ELOP). The control strategy adopted is Field Oriented Control (FOC).

## Variants
This repository majorly has three variants:
- Sensor-based
- Sensor-less
- Hybrid, i.e., both Sensor-based and Sensor-less variants switchable in run-time

## Dependency
This repository has three dependencies:
- [motor_ctrl_library](https://github.com/vhit-spa/motor_ctrl_library)
- [simulation_model](https://github.com/vhit-spa/simulation_model)

## Modification Record
- AST组件增加关管标志位单元，测试验证
- 修改产线标定单元，使其输出标定扭矩取代标定电流，更改2个斜率标定参数及数值
- 高频任务：调制转子位置角计算单元按照计划实施
- 低频任务：电机控制状态机单元删除Align状态等；目标扭矩选择&目标电流计算单元增加选择逻辑等
- 中频任务：转子位置角修改；park变换增加选择逻辑；dq轴电流控制删除选择逻辑

%20240311
- 新增和优化脚本文件及文件夹架构
- 优化脚本

%20240401
- 版本信息： V1.*.*——有感平台；V2.*.*——无感平台

%20240701
-版本信息：Platform_Standard_Model_2023a_V1.0，包含成熟的标幺化有感和无感模型。

## Platform_Standard_Model_2023a_V1.1 更新记录
%20240702
- 将SigIn组件的通讯命令/通讯故障/有感位置标定使能位分解出去，进入各自的应用组件中。
- OBD组件输出关管标志位删除，通过输出的故障等级在AST组件中设计故障关管标志位。
- 重整文件夹架构，文件夹架构将单元进行拆分和releases文件一起移植到组件文件夹中。
-数据管理整合，删除不需要变量和.sldd，重新生成配置文件。


## Platform_Standard_Model_2023a_V1.2 更新记录
%20240705
-优化标幺化平台的PI模块，使其在任何工况均不会发生数据溢出，且能保证精度；同时规定PI参数的数据类型定义方法。
- 统一更改变量名和模块名。
- 将系统状态机PreSleep状态删除，通过睡眠标志位决定目标转速和关管标志位
%20240723
- 更新OBD

%20240813
- 更新PI，增加Kp*err的32位处理；
***************************************************************************************************************************
V2.1版本记录
- 增加混合模式平台;
-修复L冷启动时候的过流保护输入源头（转速和PCB温度）未接入问题；
-变更AST组件中目标转速判断为零的逻辑，删除与跛行标志位
****************************************************************************************************************************
V2.2_2 版本记录
- 增加PLL解码方案；                                                                                                                               //完成//
- 将磁链定标由2^-22改成2^-20；                                                                                                          //完成//
- 增加限额模块效率表；                                                                                                                         //完成//
- 堵转功能将递进式扭矩改为固定最大电流；                                                                                           //不更改//
- 设置在初始化状态不进行故障诊断                                                                                                        //已完成//
- 更新测试无感堵转功能                                                                                                                      //暂不更改//  
- 将库状态机的代码生成函数打包由“自动”改成“内联”                                                                    //已完成//（待考究）
- 修改状态机中local量的属性为uint8或uint16；否则会造成bug                                                               //已完成//
- 更新堵转功能确诊和恢复时间数值类型由uint8改至uint16,将循环确诊库的内部参数由uint8改成uint16        //已完成//
- 将SigIn组件的电压系数的定标由磁链类型改至2^-22；                                                                           //已完成//
- 将PI库更新，删除无用限制接口，并删除对应转速和电流的限制值                                                           //已完成//
- 将PLL的PI改成正式版，并修改了PLL的Ki系数；                                                                                    //已完成//
- -将磁链观测器高通滤波系数最大值改为0.1                                                                                          //已完成//
- 更改最大磁链变量数值由0.1改至0.05；
- 将磁链滤波系数/电压积分/磁链改成变量名                                                                                         //完成//
-磁链定标改成2^-20，将最大磁链改成0.02                                                                                          //完成// 
- 将组件内单元外的接口移动到单元内部                                                                                                //完成//                     
- 将工程文件夹中的多余单元模型删除                                                                                                  //完成//

V2.2_3 版本记录
- 磁链/电阻/电感标幺化处理                                                                                                              //完成//

V2.2_4 版本记录
- 无感PI调节，使其能够在-4500rpm—4500rpm正常仿真运行                                                               //完成//
- 修改s16_uADActPhCurr/s16_uADActPhCurrOfs为u16_uADActPhCurr/u16_uADActPhCurrOfs          //完成//

V2.2_7 版本记录
-增加故障信息存储的BUS输出
-修改部分组件不能生成代码的bug
-统一初始化函数的命名规范和标准

V2.2_8 版本记录
-增加进入睡眠的条件，即故障存储完成标志位；

V2.2_9 版本记录
-优化修改模型规范和参数设计不合理问题：
1.OBD组件内控制板电压过压一级阈值Gu16_uCtlBrdVltgHiLvl1ConfTrs_C由0.15258789改为0.2890625；
2.OBD组件内过流阈值Gs16_iPhCurrHiLvl1ConfTrs_C由0.9改为0.273；过流恢复阈值Gs16_iPhCurrHiLvl1RcvyTrs_C由0.8改为0.246；
3.将OBD组件内的s16_ampActPhCurrAmp输入单元时的下限由-0.45改成0，包括rss_NoLdDia单元和rss_PhCurrHiLvl1Dia单元；
4.将OBD组件内rss_MotoSpdHiLvl1Dia单元的转速输入增加绝对值处理，将Gu16_nMotoSpdHiLvl1ConfTrs_C改为0.703；将Gu16_nMotoSpdHiLvl1RcvyTrs_C改为0.65194；
5.将OBD组件内 rss_PwrTubPCBTempHiLvl1Dia/rss_PwrTubPCBTempHiLvl2Dia/rss_PwrTubPCBTempSensFaltDia/rss_MotoTempSensFaltDia四个模块的bol_enFaltRcvEnFlg取元素的索引由从1开始改为从0开始；
6.OBD组件内控制板电压过压一级阈值Gu16_uGDVltgHiLvl1ConfTrs_C由0.15258789改为0.2890625；
-PhVltgGen组件内将转速滤波用于有感无感转速共同滤波；
-OBD组件修改故障存储和OBD_SlwTaskIn成员信号的数据类型，4个；
-将功率标幺Peak值增大，防止溢出；

V2.2_10 版本记录
-AST组件：增加LIN吉利的系统状态机变体，AST组件增加睡眠使能标志位输入，同步更新AST组件中的目标转速计算单元和关管单元；
-OBD组件：增加通讯故障诊断逻辑的变体，实现CRC/通讯丢失/RC通讯故障的合并，同步，将通讯类故障转速处理逻辑增加变体；
-OBD组件：增加CRASH故障单元，同步更新故障处理单元/故障使能单元/故障信息管理单元，同时增加OBD组件输入信号；
-OBD组件：删除预驱电压的输入，增加过压和欠压标志位，预驱电压过压和欠压故障由输入的过压和欠压标志位决定；（预驱电压输入）
-OBD组件：修改PCB功率管温度传感器故障方案，引入MCU温度输入，重新定义传感器开路故障和短路故障策略；
-OBD组件：变体不使能故障信息管理单元的故障存储功能；

V2.2_11 版本记录
- AST组件产线标定状态机“==”“~=”运算符中使用浮点数强制转换成定点值；
-AST组件将Gs16_facRefSpdOpnLpRiseSlwRate_C改为Gs16_facRefSpdOLRiseSlwRate_C，将Gs16_facRefSpdOpnLpFallSlwRate_C改为Gs16_facRefSpdOLFallSlwRate_C；
-OBD组件：更新库模块，将故障确诊和恢复阈值由uint8改为uint16；
-完成规则扫描的修改，除了几个无法修改项，其他均修改完成；
-SigIn组件：增加MCU温度和故障信号输入，输出增加tPCBSubs，NTC开路故障需要引入替代PCB温度tPCBSubs，AST组件使用该温度值；
-增加CAN的和LIN的项目变体一键选择按键。
-增加预驱故障的变体，Lin方案选用预驱故障标志位进行判断，CAN方案选用预驱电压进行判断。
-更改OBD组件内部Deb库新增的Crash故障和预驱故障排号；

V2.2_12 版本记录

-将OBD组件三个库模块的生成代码配置成自动；
-将母线电压欠压1级2级的使能需要引入的斜坡目标转速改为通讯目标转速；
-通讯诊断使能条件增加变体以区分LIN平台；
-增加空吸故障诊断转速阈值
-更改PCB和功率管温度传感器开路/短路故障逻辑
-将CRC/RC/通讯丢失故障消抖后的bit位区分，由OBD组件输出；

V2.2_13 版本记录
-ASW_PhVltgGen组件：在“rss_ClarkeTrasf”单元增加相电压相位延迟补偿功能； //已完成
-ASW_PhVltgGen组件：
	1）“vrs_ActElecAgElecSpdCmpt”单元的“lib_FlxObs_0”库封装的“Bits number for internal calculations”改成16-bit；（暂时维持32-bit）
	2）“vrs_ActElecAgElecSpdCmpt”单元的“lib_FlxObs_0”库封装内部的lib_DiscreteTimeIntegrator_1库封装“Accumulator data type mode”改成Same of output；（暂时维持32-bit）
	3）“vrs_ActElecAgElecSpdCmpt”单元的“lib_FlxObs_0”库封装内部的lib_IirFilter_1库封装“Bits number for internal calculations”改成16-bit；（维持32-bit，否则会出现突然失控停机）
-ASW_PhVltgGen组件：“vrs_ActElecAgElecSpdCmpt”单元内部的PLL PI参数由固定标定量改为由PCB温度和实际转速查表的标定量；
-ASW_PhVltgGen/ASW_AST/ASW_SigIn组件：
    1）ASW_PhVltgGen组件增加“rss_RefVltgLimCalc”单元，并同步更新该组件输入输出接口；
    2）删除ASW_AST组件的“rss_RefVltgLimCalc”单元，并同步更新该组件输入输出接口；
    3）ASW_SigIn组件中母线电压采样处理组件从低频任务搬至中频任务，并通过更新该组件输入输出接口。
-ASW_PhCurrGen组件：
	1）vrs_StrtUpRefTqCalc单元增加扭矩主动降低的条件和动作；
	2）vrs_MotoSTM单元修改内部逻辑和信号输入，满足开环切换闭环后的转速平滑。
-ASW_AST组件：
	1）vrs_SensAgCalib单元增加传感器电角度误差输出，将产线标定状态由2次增多为3次；
	2）增加rss_ComSpdFlt单元，用于通讯上报。
-ASW_SigIn组件：
	1）vrs_ElecAgCalc单元增加角度误差和产线标定使能标志位输入，用于该单元判断位置偏差叠加与否；
-ASW_OBD组件：
	1）增加rss_MosOpnCirFaltDia单元，并同步更新rss_FaltInfoMng单元和vrs_FaltEnFlgConf单元中关于新增单元的附带内容；
	2）修改lib_FaltDefd_0库内部逻辑，涉及到循环确诊跳出条件的窗口；
	3）增加暂时故障位，并通过BUS输出到OBD组件的输出。
-ASW_OBD组件：在“rss_PhCurrHiLvl1Dia”单元增加PCB替代温度，用于选择高温和低温工况不同相电流过流阈值； 
-ASW_AST组件：在“rss_RefTqLimCalc”单元内的母线电压对母线电流限额数据，由5个增多到7个；
-ASW_OBD组件：将“rss_NoLdDia”单元/“vrs_MotoStallDia”单元的调度周期使能由bol_flgSlwSdlEn改成bol_flgFstSdlEn；
-ASW_OBD组件：将“rss_MotoStallDiaHybr”单元内堵转判断目标转速条件改为目标转速>0，将“rss_FaltResp”单元内的堵转扭矩由递增改成固定标定量，并新增堵转扭矩上限标定量；
-ASW_PhVltgGen组件：删除电流环前馈解耦；将转速滤波由32位改为16位；将sss_PredActElecSpdCmpt内部改为16位

V2.2_13_1 版本记录
-ASW_OBD组件：vrs_FaltEnFlgConf单元中的供电电压欠压一级/二级使能中，删除目标转速不为0的条件，使其上电即可使能欠压故障。

V2.2_13_2 版本记录
-ASW_OBD组件：根据故障优先级前提条件，重新定义故障优先级。

V2.2_13_3 版本记录
-ASW_PhCurrGen组件：修改模型的PI参数重新定标，修改模型PI精度，dt_SpdCtrlIntgGain_u16p9b0斜率改成2^0。

V2.2_13_4 版本记录
-ASW_OBD组件：修改模型的Chip故障中中间变量的名称，由于Chip故障时通过CRASH故障修改的，所以有些变量名字没有修改。
-ASW_OBD组件：通讯丢失故障做到模型中，RC与CRC故障连续5次确诊，参考53水泵模型修改；

V2.2_13_5 版本记录
-ASW_OBD组件：优化_4版本设计冗余和命名不规范问题；
-ASW_OBD组件：更改通讯故障替代转速默认使能置1；

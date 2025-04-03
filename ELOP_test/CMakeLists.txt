cmake_minimum_required(VERSION 3.18)

# 添加这行指定生成器
set(CMAKE_GENERATOR "MinGW Makefiles" CACHE INTERNAL "")

project(C)


add_executable(main ASW_par/motor_control_param.c ASW_par/motor_param.c ASW_share/const_params.c ASW_share/mul_ssu32_hiSR.c ASW_share/look1_iu8lu32n16ts16Ds32_binlcs.c
               ASW_share/mul_wide_su32.c ASW_share/look1_iu16lu32n16ts16D_2s4GBl96.c ASW_share/mul_ssu32_loSR.c ASW_share/div_nde_s32_floor.c
               ASW_share/look2_is16lu32n16tu16_binlcse.c ASW_share/look1_is16lu32n32ys16n_eAC3J1UD.c ASW_share/look2_iu8s16lu32n16tu16_binlcse.c ASW_share/look1_iu16lu32n16tu8_binlcse.c
               ASW_AST/ASW_AST.c ASW_DcycGen/ASW_DcycGen.c ASW_OBD/ASW_OBD.c ASW_PhCurrGen/ASW_PhCurrGen.c 
               ASW_PhVltgGen/ASW_PhVltgGen.c ASW_SigIn/ASW_SigIn.c BSW/PWM.c BSW/ADC.c
               FOC.c main.c)

target_compile_features(main PRIVATE cxx_std_11)
clc
%*********** Delete contents of src folder and src_Temp folder **********%
delete('releases\src\ASW_AST_CodeGen\*')
delete('releases\src\ASW_DcycGen_CodeGen\*')
delete('releases\src\ASW_PhCurrGen_CodeGen\*')
delete('releases\src\ASW_PhVltgGen_CodeGen\*')
delete('releases\src\ASW_OBD_CodeGen\*')
delete('releases\src\ASW_SigIn_CodeGen\*')
delete('releases\src\shared_CodeGen\*')

delete('releases\src_Temp\cache\*')
rmdir('releases\src_Temp\cache\slprj','s')
rmdir('releases\src_Temp\code\ASW_AST_ert_rtw','s')
rmdir('releases\src_Temp\code\ASW_DcycGen_ert_rtw','s')
rmdir('releases\src_Temp\code\ASW_PhCurrGen_ert_rtw','s')
rmdir('releases\src_Temp\code\ASW_PhVltgGen_ert_rtw','s')
rmdir('releases\src_Temp\code\ASW_OBD_ert_rtw','s')
rmdir('releases\src_Temp\code\ASW_SigIn_ert_rtw','s')
rmdir('releases\src_Temp\code\slprj','s')

%******************* Generate C code files *******************%
% open_system("rmd_AST");
rtwbuild('ASW_AST');
% coder.asap2.export('rmd_AST',FileName='rmd_AST',Folder='releases\A2L_Temp');
% open_system("rmd_MotCtl");
rtwbuild('ASW_DcycGen');
rtwbuild('ASW_PhCurrGen');
rtwbuild('ASW_PhVltgGen');
% coder.asap2.export('rmd_MotCtl',FileName='rmd_MotCtl',Folder='releases\A2L_Temp');
% open_system("rmd_OBD");
rtwbuild('ASW_OBD');
% coder.asap2.export('rmd_OBD',FileName='rmd_OBD',Folder='releases\A2L_Temp');
% open_system("rmd_SigIn");
rtwbuild('ASW_SigIn');
% coder.asap2.export('rmd_SigIn',FileName='rmd_SigIn',Folder='releases\A2L_Temp');

%******************** Copy C code to src folder *********************%
copyfile('releases\src_Temp\code\ASW_AST_ert_rtw\*.c','releases\src\ASW_AST_CodeGen')
copyfile('releases\src_Temp\code\ASW_AST_ert_rtw\*.h','releases\src\ASW_AST_CodeGen')

copyfile('releases\src_Temp\code\ASW_DcycGen_ert_rtw\*.c','releases\src\ASW_DcycGen_CodeGen')
copyfile('releases\src_Temp\code\ASW_DcycGen_ert_rtw\*.h','releases\src\ASW_DcycGen_CodeGen')

copyfile('releases\src_Temp\code\ASW_PhCurrGen_ert_rtw\*.c','releases\src\ASW_PhCurrGen_CodeGen')
copyfile('releases\src_Temp\code\ASW_PhCurrGen_ert_rtw\*.h','releases\src\ASW_PhCurrGen_CodeGen')

copyfile('releases\src_Temp\code\ASW_PhVltgGen_ert_rtw\*.c','releases\src\ASW_PhVltgGen_CodeGen')
copyfile('releases\src_Temp\code\ASW_PhVltgGen_ert_rtw\*.h','releases\src\ASW_PhVltgGen_CodeGen')

copyfile('releases\src_Temp\code\ASW_OBD_ert_rtw\*.c','releases\src\ASW_OBD_CodeGen')
copyfile('releases\src_Temp\code\ASW_OBD_ert_rtw\*.h','releases\src\ASW_OBD_CodeGen')

copyfile('releases\src_Temp\code\ASW_SigIn_ert_rtw\*.c','releases\src\ASW_SigIn_CodeGen')
copyfile('releases\src_Temp\code\ASW_SigIn_ert_rtw\*.h','releases\src\ASW_SigIn_CodeGen')

copyfile('releases\src_Temp\code\slprj\ert\_sharedutils\*.c','releases\src\shared_CodeGen')
copyfile('releases\src_Temp\code\slprj\ert\_sharedutils\*.h','releases\src\shared_CodeGen')

%******************* Open code folders **********************%
winopen('releases\src\ASW_AST_CodeGen')
winopen('releases\src\ASW_DcycGen_CodeGen')
winopen('releases\src\ASW_PhCurrGen_CodeGen')
winopen('releases\src\ASW_PhVltgGen_CodeGen')
winopen('releases\src\ASW_OBD_CodeGen')
winopen('releases\src\ASW_SigIn_CodeGen')
winopen('releases\src\shared_CodeGen')
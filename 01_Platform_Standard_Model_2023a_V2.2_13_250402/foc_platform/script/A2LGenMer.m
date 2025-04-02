clc
%******************** Delete contents of A2L_Temp folder ********************%
delete('releases\A2L_Temp\*.a2l')

%******************** Generate asap2 files ********************%
open_system("rmd_AST");
coder.asap2.export('rmd_AST',FileName='rmd_AST',Folder='releases\A2L_Temp');
open_system("rmd_MotCtl");
coder.asap2.export('rmd_MotCtl',FileName='rmd_MotCtl',Folder='releases\A2L_Temp');
open_system("rmd_OBD");
coder.asap2.export('rmd_OBD',FileName='rmd_OBD',Folder='releases\A2L_Temp');
open_system("rmd_SigIn");
coder.asap2.export('rmd_SigIn',FileName='rmd_SigIn',Folder='releases\A2L_Temp');

%******************** Merge ASAP2 Files and address********************%
mergeObj = coder.asap2.merge("rmd_SigIn",{"releases\A2L_Temp\rmd_AST.a2l","releases\A2L_Temp\rmd_MotCtl.a2l","releases\A2L_Temp\rmd_OBD.a2l","releases\A2L_Temp\rmd_SigIn.a2l"},FileName='rmd',Folder='releases\A2L_Temp',MapFile='releases\A2L_Temp\rmd.elf');
coder.asap2.export("rmd_SigIn",CustomEcuDescriptions=mergeObj);

%******************** Merge header file *********************%
%Open
fidz=fopen("releases\A2L_Temp\rmd.a2l","r+");
fidx=fopen("releases\A2L_Temp\header.c","r+");
fidw=fopen("releases\A2L\rmd_header.a2l","w+");
%Clear rmd_header.a2l
for i=1
    fgetl(fidw)
end
while ~feof(fidw)
    fprintf(fidw,'%s\n','');
end
% Add Header code
for k=1:1234
    tline1=fgetl(fidx);
    if k>0
        fprintf(fidw,'%s\n',tline1);
    end
end
%Add model content
for m=1:43
    fgetl(fidz)
end
while ~feof(fidz)
    tline2=fgetl(fidz);
    fprintf(fidw,'%s\n',tline2);
end
disp('合并完成');

%******************** Open A2L folder **********************%
winopen('releases\A2L');
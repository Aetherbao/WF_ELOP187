function blkStruct = slblocks
blkStruct.Name = 'MSERef_powerelectronics';
blkStruct.OpenFcn = 'MSERef_powerelectronics';
blkStruct.MaskDisplay = '';

Browser(1).Library = 'MSERef_powerelectronics';
Browser(1).Name    = 'MSERef_powerelectronics';
Browser(1).IsFlat  = 0; % Is this library "flat" (i.e. no subsystems)?
Browser(1).Children = {'Power stages','Control of Power Electronics', ...
                       'Energy storage','Auxiliary Blocks'};

blkStruct.Browser = Browser;




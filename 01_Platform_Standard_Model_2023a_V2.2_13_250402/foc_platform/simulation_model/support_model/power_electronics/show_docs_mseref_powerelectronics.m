function show_docs_mseref_powerelectronics( modelname )
% `show_docs_mseref_powerelectronics` opens the details documentation of `modelname`.
% The path to this documentation is determined from the path to the related 
% `MSEREF_powerelectronics.slx` library.
%
% Input:
% - `modelname`: model name as string, e.g. 'PEPS101MSEREF'

winopen(fullfile(fileparts(which('MSEREF_powerelectronics.slx')), '..', 'doc', modelname, [modelname '_details.pdf']));

end
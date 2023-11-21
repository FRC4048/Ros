function msg = nav_msgs_OccupancyGridStruct
% Message struct definition for nav_msgs/OccupancyGrid
coder.inline("never")
msg = struct(...
    'MessageType','nav_msgs/OccupancyGrid',...
    'Header',std_msgs_HeaderStruct,...
    'Info',nav_msgs_MapMetaDataStruct,...
    'Data',ros.internal.ros.messages.ros.default_type('int8',NaN));
coder.cstructname(msg,'nav_msgs_OccupancyGridStruct_T');
coder.varsize('msg.Data',[1000000000 1],[1 0]);
if ~isempty(coder.target)
    coder.ceval('//',coder.rref(msg));
end
end

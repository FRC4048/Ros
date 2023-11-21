function msg = geometry_msgs_PointStampedStruct
% Message struct definition for geometry_msgs/PointStamped
coder.inline("never")
msg = struct(...
    'MessageType','geometry_msgs/PointStamped',...
    'Header',std_msgs_HeaderStruct,...
    'Point',geometry_msgs_PointStruct);
coder.cstructname(msg,'geometry_msgs_PointStampedStruct_T');
if ~isempty(coder.target)
    coder.ceval('//',coder.rref(msg));
end
end

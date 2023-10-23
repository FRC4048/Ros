function msg = geometry_msgs_TransformStampedStruct
% Message struct definition for geometry_msgs/TransformStamped
coder.inline("never")
msg = struct(...
    'MessageType','geometry_msgs/TransformStamped',...
    'Header',std_msgs_HeaderStruct,...
    'ChildFrameId',ros.internal.ros.messages.ros.char('string',0),...
    'Transform',geometry_msgs_TransformStruct);
coder.cstructname(msg,'geometry_msgs_TransformStampedStruct_T');
coder.varsize('msg.ChildFrameId',[1 1000000000],[0 1]);
if ~isempty(coder.target)
    coder.ceval('//',coder.rref(msg));
end
end

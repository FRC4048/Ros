function msg = geometry_msgs_TwistStruct
% Message struct definition for geometry_msgs/Twist
coder.inline("never")
msg = struct(...
    'MessageType','geometry_msgs/Twist',...
    'Linear',geometry_msgs_Vector3Struct,...
    'Angular',geometry_msgs_Vector3Struct);
coder.cstructname(msg,'geometry_msgs_TwistStruct_T');
if ~isempty(coder.target)
    coder.ceval('//',coder.rref(msg));
end
end

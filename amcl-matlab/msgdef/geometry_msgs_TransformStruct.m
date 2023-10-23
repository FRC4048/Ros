function msg = geometry_msgs_TransformStruct
% Message struct definition for geometry_msgs/Transform
coder.inline("never")
msg = struct(...
    'MessageType','geometry_msgs/Transform',...
    'Translation',geometry_msgs_Vector3Struct,...
    'Rotation',geometry_msgs_QuaternionStruct);
coder.cstructname(msg,'geometry_msgs_TransformStruct_T');
if ~isempty(coder.target)
    coder.ceval('//',coder.rref(msg));
end
end

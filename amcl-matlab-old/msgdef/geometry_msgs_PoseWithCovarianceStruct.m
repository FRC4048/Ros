function msg = geometry_msgs_PoseWithCovarianceStruct
% Message struct definition for geometry_msgs/PoseWithCovariance
coder.inline("never")
msg = struct(...
    'MessageType','geometry_msgs/PoseWithCovariance',...
    'Pose',geometry_msgs_PoseStruct,...
    'Covariance',ros.internal.ros.messages.ros.default_type('double',36));
coder.cstructname(msg,'geometry_msgs_PoseWithCovarianceStruct_T');
if ~isempty(coder.target)
    coder.ceval('//',coder.rref(msg));
end
end

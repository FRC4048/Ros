function msg = geometry_msgs_TwistWithCovarianceStruct
% Message struct definition for geometry_msgs/TwistWithCovariance
coder.inline("never")
msg = struct(...
    'MessageType','geometry_msgs/TwistWithCovariance',...
    'Twist',geometry_msgs_TwistStruct,...
    'Covariance',ros.internal.ros.messages.ros.default_type('double',36));
coder.cstructname(msg,'geometry_msgs_TwistWithCovarianceStruct_T');
if ~isempty(coder.target)
    coder.ceval('//',coder.rref(msg));
end
end

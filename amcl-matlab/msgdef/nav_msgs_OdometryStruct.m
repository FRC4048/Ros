function msg = nav_msgs_OdometryStruct
% Message struct definition for nav_msgs/Odometry
coder.inline("never")
msg = struct(...
    'MessageType','nav_msgs/Odometry',...
    'Header',std_msgs_HeaderStruct,...
    'ChildFrameId',ros.internal.ros.messages.ros.char('string',0),...
    'Pose',geometry_msgs_PoseWithCovarianceStruct,...
    'Twist',geometry_msgs_TwistWithCovarianceStruct);
coder.cstructname(msg,'nav_msgs_OdometryStruct_T');
coder.varsize('msg.ChildFrameId',[1 1000000000],[0 1]);
if ~isempty(coder.target)
    coder.ceval('//',coder.rref(msg));
end
end

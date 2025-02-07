import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/nguyen-anh-dung/ros2_ws/install/roverc_client'

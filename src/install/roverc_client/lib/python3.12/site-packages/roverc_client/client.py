import socket
import signal
import json
import rclpy
import time
import errno
from rclpy.node import Node
from std_msgs.msg import String
from roverc.msg import RGB
from roverc.msg import WheelSpeed
from std_msgs.msg import UInt16MultiArray
from std_msgs.msg import Float32
from std_msgs.msg import Bool
from std_msgs.msg import Int8
from std_msgs.msg import UInt8
from std_msgs.msg import MultiArrayDimension
from sensor_msgs.msg import BatteryState
from sensor_msgs.msg import Imu





class RoverCClient(Node):
    def __init__(self):
        super().__init__('roverc_client')

        self.ssid = ""
        self.w0 = 0
        self.w1 = 0
        self.w2 = 0
        self.w3 = 0
        self.servo1 = 0
        self.servo2 = 0
        self.wheel_flag = 0
        self.servo_flag = 0
        self.sensor_flag = 0

        self.battery_pub = 0 #self.create_publisher(BatteryState, 'RoverC/battery', 1)
        self.distance_pub = 0 #self.create_publisher(Float32, 'RoverC/distance', 1)
        self.distance_pub2 = 0 #self.create_publisher(Float32, 'RoverC/distance2', 1)
        self.imu_pub = 0 #self.create_publisher(Imu, 'RoverC/imu', 1)
        self.rgb_pub = 0 #self.create_publisher(RGB, 'RoverC/rgb', 1)
        self.rgbc_pub = 0 #self.create_publisher(UInt16MultiArray, 'RoverC/rgbc', 1)
        self.rgb_pub2 = 0 #self.create_publisher(RGB, 'RoverC/rgb2', 1)
        self.rgbc_pub2 = 0 #self.create_publisher(UInt16MultiArray, 'RoverC/rgbc2', 1)
        self.buttonA_pub = 0 #self.create_publisher(Bool, 'RoverC/buttonA', 1)
        self.buttonB_pub = 0 #self.create_publisher(Bool, 'RoverC/buttonB', 1)

        self.w0_sub = 0 #self.create_subscription(Int8, 'RoverC/w0', self.w0_cb, 1)
        self.w1_sub = 0 #self.create_subscription(Int8, 'RoverC/w1', self.w1_cb, 1)
        self.w2_sub = 0 #self.create_subscription(Int8, 'RoverC/w2', self.w2_cb, 1)
        self.w3_sub = 0 #self.create_subscription(Int8, 'RoverC/w3', self.w3_cb, 1)
        self.servo1_sub = 0 #self.create_subscription(UInt8, 'RoverC/servo1', self.servo1_cb, 1)
        self.servo2_sub = 0 #self.create_subscription(UInt8, 'RoverC/servo2', self.servo2_cb, 1)
        self.wheels_sub = 0 #self.create_subscription(WheelSpeed, 'RoverC/wheels', self.wheels_cb, 1)

        self.w0_sub  # prevent unused variable warning
        self.w1_sub  # prevent unused variable warning
        self.w2_sub  # prevent unused variable warning
        self.w3_sub  # prevent unused variable warning
        self.servo1_sub  # prevent unused variable warning
        self.servo2_sub  # prevent unused variable warning
        self.wheels_sub  # prevent unused variable warning

    def w0_cb(self, msg):
        if self.wheel_flag & 0x01 == 0x00:
            self.w0 = msg.data
            self.wheel_flag |= 0x01

    def w1_cb(self, msg):
        if self.wheel_flag & 0x02 == 0x00:
            self.w1 = msg.data
            self.wheel_flag |= 0x02

    def w2_cb(self, msg):
        if self.wheel_flag & 0x04 == 0x00:
            self.w2 = msg.data
            self.wheel_flag |= 0x04

    def w3_cb(self, msg):
        if self.wheel_flag & 0x08 == 0x00:
            self.w3 = msg.data
            self.wheel_flag |= 0x08

    def servo1_cb(self, msg):
        if self.servo_flag & 0x01 == 0x00:
            self.servo1 = msg.data
            self.servo_flag |= 0x01

    def servo2_cb(self, msg):
        if self.servo_flag & 0x02 == 0x00:
            self.servo2 = msg.data
            self.servo_flag |= 0x02

    def wheels_cb(self, msg):
        if self.wheel_flag & 0x0F == 0x00:
            self.w0 = msg.front_right
            self.w1 = msg.front_left
            self.w2 = msg.rear_right
            self.w3 = msg.rear_left
            self.wheel_flag |= 0x0F      

    def createJSONData(self):
        s = ""
        create_json_flag = False
        d = {}
        if self.wheel_flag != 0x00:
            if self.wheel_flag & 0x01 != 0x00:
                d["w0"] = self.w0
                self.wheel_flag &= ~0x01
                create_json_flag = True
            if self.wheel_flag & 0x02 != 0x00:
                d["w1"] = self.w1
                self.wheel_flag &= ~0x02
                create_json_flag = True
            if self.wheel_flag & 0x04 != 0x00:
                d["w2"] = self.w2
                self.wheel_flag &= ~0x04
                create_json_flag = True
            if self.wheel_flag & 0x08 != 0x00:
                d["w3"] = self.w3
                self.wheel_flag &= ~0x08
                create_json_flag = True
        if self.servo_flag & 0x01 != 0x00:
            d["s1"] = self.servo1
            self.servo_flag &= ~0x01
            create_json_flag = True
        if self.servo_flag & 0x02 != 0x00:
            d["s2"] = self.servo2
            self.servo_flag &= ~0x02
            create_json_flag = True
        if create_json_flag:
            s = json.dumps(d)
        return s

                
    def publishBattery(self, current, voltage):
        msg = BatteryState()
        msg.current = current
        msg.voltage = voltage
        msg.header.frame_id = 'roverc'
        msg.header.stamp = self.get_clock().now().to_msg()
        self.battery_pub.publish(msg)

    def publishDistance(self, distance):
        msg = Float32()
        msg.data = distance
        self.distance_pub.publish(msg)  

    def publishDistance2(self, distance):
        msg = Float32()
        msg.data = distance
        self.distance_pub2.publish(msg) 

    def publishImu(self, accX, accY, accZ, gyroX, gyroY, gyroZ):
        msg = Imu()
        msg.angular_velocity.x = gyroX
        msg.angular_velocity.y = gyroY
        msg.angular_velocity.z = gyroZ
        msg.linear_acceleration.x = accX
        msg.linear_acceleration.y = accY
        msg.linear_acceleration.z = accZ
        msg.header.frame_id = 'roverc'
        msg.header.stamp = self.get_clock().now().to_msg()
        self.imu_pub.publish(msg) 

    def publishRGBC(self, r,g,b,c):
        msg = RGB()
        if(c!=0):
            msg.red = r/c
            msg.green = g/c
            msg.blue = b/c
        else:
            msg.red = 0.0
            msg.green = 0.0
            msg.blue = 0.0
        self.rgb_pub.publish(msg)

        msg2 = UInt16MultiArray()
        msg2.data.append(r)
        msg2.data.append(g)
        msg2.data.append(b)
        msg2.data.append(c)
        msg2.layout.data_offset = 0
        dim = MultiArrayDimension()
        dim.label = "rgbc"
        dim.size = 4
        dim.stride = 4
        msg2.layout.dim.append(dim)
        self.rgbc_pub.publish(msg2)

    def publishRGBC2(self, r,g,b,c):
        msg = RGB()
        if(c!=0):
            msg.red = r/c
            msg.green = g/c
            msg.blue = b/c
        else:
            msg.red = 0.0
            msg.green = 0.0
            msg.blue = 0.0
        self.rgb_pub2.publish(msg)

        msg2 = UInt16MultiArray()
        msg2.data.append(r)
        msg2.data.append(g)
        msg2.data.append(b)
        msg2.data.append(c)
        msg2.layout.data_offset = 0
        dim = MultiArrayDimension()
        dim.label = "rgbc"
        dim.size = 4
        dim.stride = 4
        msg2.layout.dim.append(dim)
        self.rgbc_pub2.publish(msg2)

    def publishButtonA(self, button):
        msg = Bool()
        msg.data = button
        self.buttonA_pub.publish(msg) 

    def publishButtonB(self, button):
        msg = Bool()
        msg.data = button
        self.buttonB_pub.publish(msg) 

    def publishCamera(self, camera):
        msg = String()
        msg.data = camera
        self.camera_pub.publish(msg) 

    

            
def handler(signum, frame):
    #res = input("\nCtrl-c was pressed. Do you really want to exit? y/n ")
    #if res == 'y':
    exit()

def processJSON(node, jsonStr):
    out = json.loads(jsonStr)


    if node.ssid == "" and "s" in out:
        node.ssid = "RoverC"##out['s']
        node.w0_sub = node.create_subscription(Int8, node.ssid + '/w0', node.w0_cb, 1)
        node.w1_sub = node.create_subscription(Int8, node.ssid + '/w1', node.w1_cb, 1)
        node.w2_sub = node.create_subscription(Int8, node.ssid + '/w2', node.w2_cb, 1)
        node.w3_sub = node.create_subscription(Int8, node.ssid + '/w3', node.w3_cb, 1)
        node.servo1_sub = node.create_subscription(UInt8, node.ssid + '/servo1', node.servo1_cb, 1)
        node.servo2_sub = node.create_subscription(UInt8, node.ssid + '/servo2', node.servo2_cb, 1)
        node.wheels_sub = node.create_subscription(WheelSpeed, node.ssid + '/wheels', node.wheels_cb, 1)
        node.battery_pub = node.create_publisher(BatteryState, node.ssid + '/battery', 1)
        node.imu_pub = node.create_publisher(Imu, node.ssid + '/imu', 1)
        node.buttonA_pub = node.create_publisher(Bool, node.ssid + '/buttonA', 1)
        node.buttonB_pub = node.create_publisher(Bool, node.ssid + '/buttonB', 1)



    if node.ssid != "":
        if "f" in out:
            if node.sensor_flag != out['f']:
                if (node.sensor_flag & 0x01) == 0 and  (out['f'] & 0x01) == 0x01:
                    node.distance_pub = node.create_publisher(Float32, node.ssid + '/distance', 1)
                if (node.sensor_flag & 0x02) == 0 and  (out['f'] & 0x02) == 0x02:
                    node.distance_pub2 = node.create_publisher(Float32, node.ssid + '/distance2', 1)
                if (node.sensor_flag & 0x04) == 0 and  (out['f'] & 0x04) == 0x04:
                    node.rgb_pub = node.create_publisher(RGB, node.ssid + '/rgb', 1)
                    node.rgbc_pub = node.create_publisher(UInt16MultiArray, node.ssid + '/rgbc', 1)
                if (node.sensor_flag & 0x08) == 0 and  (out['f'] & 0x08) == 0x08:
                    node.rgb_pub2 = node.create_publisher(RGB, node.ssid + '/rgb2', 1)
                    node.rgbc_pub2 = node.create_publisher(UInt16MultiArray, node.ssid + '/rgbc2', 1)   
                if (node.sensor_flag & 0x10) == 0 and  (out['f'] & 0x10) == 0x10:
                    node.camera_pub = node.create_publisher(String, node.ssid + '/camera', 1)
                node.sensor_flag = out['f'] 

        if "d" in out and hasattr(out['d'], "__len__") and len(out['d']) == 2:
            if node.sensor_flag & 0x01 == 0x01:
                node.publishDistance(float(out['d'][0])/1000.0)
            if node.sensor_flag & 0x02 == 0x02:
                node.publishDistance2(float(out['d'][1])/1000.0)

        if ("c" in out and 
        hasattr(out['c'], "__len__") and len(out['c']) == 2 and
        hasattr(out['c'][0], "__len__") and len(out['c'][0]) == 4 and 
        hasattr(out['c'][1], "__len__") and len(out['c'][1]) == 4):
            if node.sensor_flag & 0x04 == 0x04:
                node.publishRGBC(out['c'][0][0], out['c'][0][1], out['c'][0][2], out['c'][0][3])
            if node.sensor_flag & 0x08 == 0x08:
                node.publishRGBC2(out['c'][1][0], out['c'][1][1], out['c'][1][2], out['c'][1][3])
        
        if "i" in out and hasattr(out['i'], "__len__") and len(out['i']) == 6:
            node.publishImu(out['i'][0], out['i'][1], out['i'][2], out['i'][3], out['i'][4], out['i'][5])

        if "b" in out and hasattr(out['b'], "__len__") and len(out['b']) == 2:
            node.publishButtonA(out['b'][0] != 0)
            node.publishButtonB(out['b'][1] != 0)

        if "B" in out and hasattr(out['B'], "__len__") and len(out['B']) == 2:
            node.publishBattery(out['B'][0], out['B'][1])

        if "C" in out:
            if node.sensor_flag & 0x10 == 0x10:
                node.publishCamera(out['C'])  

        
 


def main(args=None):
    period = 40000000
    rclpy.init(args=args)
    signal.signal(signal.SIGINT, handler)
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    jsonString = ""
    # Connect the socket to the port where the server is listening
    server_address = ('192.168.4.1', 8888)
    print('connecting to {} port {}'.format(*server_address))
    sock.connect(server_address)
    jsonString=""
    print('connected')
    startTS = 0

    node = RoverCClient()
    now = time.monotonic_ns()
    sock.setblocking(0)
    nbrecv = 0
    nbsent = 0
    displayNow = now
    try:
        while 1:
            rclpy.spin_once(node, timeout_sec=0)
            t = time.monotonic_ns() - displayNow
            if t > 1000000000:
                displayNow = time.monotonic_ns()
                print(node.ssid, end=' | ')
                print("Sensors: ", end='')
                if (node.sensor_flag & 0x01) == 0x01:
                    print("D1 ", end='')
                if (node.sensor_flag & 0x02) == 0x02:
                    print("D2 ", end='')
                if (node.sensor_flag & 0x04) == 0x04:
                    print("C1 ", end='')
                if (node.sensor_flag & 0x08) == 0x08:
                    print("C2 ", end='')
                if (node.sensor_flag & 0x10) == 0x10:
                    print("Cam ", end='')
                print("| Received: ", nbrecv, "\tSent:", nbsent, "    ", sep='', end='\r')
                nbrecv = 0
                nbsent = 0
            t = time.monotonic_ns() - now
            if t >= period:
                if t > (2 * period):
                    now += t 
                else :
                    now += period
                s = node.createJSONData()
                if len(s) > 2:
                    s += '\n'
                    # print(s)
                    sock.send(s.encode())
                    nbsent = nbsent + 1
            try:
                data = sock.recv(50)
                #print(data)
            except socket.error:
                #err = e.args[0]
                #if err == errno.EAGAIN or err == errno.EWOULDBLOCK:
                    time.sleep(0.01)
                    continue
            else:
                for c in data:
                    # print(chr(c))
                    if chr(c) == '\n':
                        # print("found json : " + jsonString)
                        if jsonString[0] == '{':
                            processJSON(node, jsonString)
                            nbrecv = nbrecv + 1 
                        jsonString=""
                    else:
                        jsonString+=chr(c) #.decode("utf-8")
    finally:
        print('\nclosing socket')
        sock.close()
        print('shutting down ROS Node')
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()

# Create a TCP/IP socket

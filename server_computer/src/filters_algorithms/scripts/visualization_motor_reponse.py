import matplotlib.pyplot as plt
import numpy as np
import rospy
from actuators.msg import Vector4
import tf
import time
encoder_t=[]
encoder_omega=[]
setpoint_t=[]
setpoint_omega=[]
plt.ion()
figure, ax = plt.subplots()
ax.set_title('motor_response')
ax.axis([0,10000,-50,50])
class motor_response:
    def __init__(self):
        rospy.init_node('motor_response', anonymous=True)
        rospy.Subscriber("encoder_base_omega",Vector4, self.input_callback)
        rospy.Subscriber("setpoint_base_omega",Vector4, self.setpoint_callback)
        self.prevTime=rospy.Time().now()
        self.sdt=0
        self.idt=0
    def input_callback(self,data):
            encoder_omega.append(data.quad[0])
            self.idt=self.idt+(rospy.Time().now()-self.prevTime).to_sec()
            encoder_t.append(self.idt)
    def setpoint_callback(self,data):
            #rospy.loginfo("%lf",self.curr.data)
            setpoint_omega.append(data.quad[0])
            self.sdt=self.sdt+(rospy.Time().now()-self.prevTime).to_sec()
            setpoint_t.append(self.sdt)
    def run(self):
        while not rospy.is_shutdown():
            #plt.plot([self.curr.x,self.prev.x],[self.curr.y,self.prev.y],'r',linewidth=1)
            plt.plot(encoder_t,encoder_omega,'-r',linewidth=0.9)
            plt.plot(setpoint_t,setpoint_omega,'-b',linewidth=0.9)
            figure.canvas.draw()
            figure.canvas.flush_events()
            time.sleep(0.01)

if __name__=="__main__":
    try:
        motor_response_=motor_response()
        motor_response_.run()
    except rospy.ROSInterruptException:
        pass
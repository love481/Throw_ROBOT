import matplotlib.pyplot as plt
import numpy as np
import rospy
from geometry_msgs.msg import Pose2D
import tf
import time
x=[]
y=[]
xr=[]
yr=[]
plt.ion()
figure, ax = plt.subplots()
ax.set_title('Robot_trajectory')
plt.xlabel("x_coordinate")
plt.ylabel("y_coordinate")
#ax.axis([-0.5,12.5,-0.5,6.5])
ax.axis([-0.5,7.5,-0.5,2.200])
# ax.axis([-0.5,7.5,0.5,-2.500])
# ax.axis([-7.5,0.5,-0.50,2.500])
class gamefield:
    def __init__(self):
        self.prev=Pose2D()
        self.curr=Pose2D()
        self.resol=1
        rospy.init_node('listener', anonymous=True)
        rospy.Subscriber("path_planning",Pose2D, self.callback)
        rospy.Subscriber("robot_pose",Pose2D, self.posecallback)
    def draw_gamefield(self):
        plt.plot([-0.2,-0.2,-0.2,7,7,7,7,-0.2],[-0.2,2.050,2.050,2.050,2.050,-0.2,-0.2,-0.2],'b',linewidth=1.25)
        # plt.plot([0,0,0,7,7,7,7,0],[0,-2.050,-2.050,-2.050,-2.050,0,0,0],'b',linewidth=1.25)
        #  plt.plot([-7,-7,-7,0,0,0,0,-7],[0,2.050,2.050,2.050,2.050,0,0,0],'b',linewidth=1.25)
        # plt.plot([0,12,0,0,12,0,12,12],[0,0,0,6,6,6,6,0],'b',linewidth=1.25)
        # plt.plot([2,2,2,4.025,4.025,5],[6,4,4,2,2,2],'b',linewidth=1.25)
        # plt.plot([6,7.975,7.975,10,10,10],[2,2,2,4,4,6],'b',linewidth=1.25)
        # plt.plot([6,6],[2,6],'b',linewidth=1.25)
    def callback(self,data):
        # rospy.loginfo("%lf  %lf   %lf",data.x*self.resol,data.y*self.resol,data.theta)
        x.append(data.x)
        y.append(data.y)
    def posecallback(self,data):
        # rospy.loginfo("%lf  %lf   %lf",data.x*self.resol,data.y*self.resol,data.theta)
        xr.append(data.x)
        yr.append(data.y)
    def run(self):
        while not rospy.is_shutdown():
            plt.plot(x,y,'-g',linewidth=1)
            plt.plot(xr,yr,'-r',linewidth=1)
            plt.legend(["boundary","Setpoint","input"],loc ="upper right")
            
            figure.canvas.draw()
            figure.canvas.flush_events()
            time.sleep(0.25)

if __name__=="__main__":
    try:
        gamefield_=gamefield()
        gamefield_.draw_gamefield()
        gamefield_.run()
    except rospy.ROSInterruptException:
        pass

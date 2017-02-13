#include <gazebo/gazebo.hh>
#include <boost/bind.hpp>
#include <gazebo/physics/physics.hh>
#include <gazebo/common/common.hh>
#include <gazebo/common/Plugin.hh>

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

namespace gazebo {
	
	class RoverControl : public ModelPlugin {

		public: RoverControl();
		public: void Load(physics::ModelPtr, sdf::ElementPtr);
		public: void LoadThread();
		public: void RoverStateCallback(const geometry_msgs::Twist::ConstPtr&);
		public: void OnUpdate(const common::UpdateInfo&);

		// Global pointer declarations
		private: physics::ModelPtr rover;
		private: physics::WorldPtr world;
		private: sdf::ElementPtr sdf;
		private: event::ConnectionPtr _updateConnection;
		private: boost::thread _spinnerThread;

		private: physics::JointPtr front_left_drive;
		private: physics::JointPtr front_right_drive;
		private: physics::JointPtr mid_left_drive;
		private: physics::JointPtr mid_right_drive;
		private: physics::JointPtr back_left_drive;
		private: physics::JointPtr back_right_drive;

		//private: physics::JointPtr front_left_steer;
		//private: physics::JointPtr front_right_steer;
		//private: physics::JointPtr back_left_steer;
		//private: physics::JointPtr back_right_steer;

		private: float front_left_vel;
		private: float front_right_vel;
		private: float mid_left_vel;
		private: float mid_right_vel;
		private: float back_left_vel;
		private: float back_right_vel;

		private: float front_left_ang;
		private: float front_right_ang;
		private: float back_left_ang;
		private: float back_right_ang;

		private: float lin_vel;
		private: float ang_vel;

		private: std::string topic;

		private: ros::Subscriber subscriber;
	};

	GZ_REGISTER_MODEL_PLUGIN(RoverControl);
}

#include <gazebo/gazebo.hh>
#include <boost/bind.hpp>
#include <gazebo/physics/physics.hh>
#include <gazebo/common/common.hh>
#include <gazebo/common/Plugin.hh>

#include <ros/ros.h>
#include <std_msgs/Float64MultiArray.h>

namespace gazebo
{
	class MoveHusky : public ModelPlugin
	{
		public: MoveHusky();
		public: void Load(physics::ModelPtr, sdf::ElementPtr);
		public: void LoadThread();
		public: void HuskyStateCallback(const std_msgs::Float64MultiArray::ConstPtr&);
		public: void OnUpdate(const common::UpdateInfo&);

		// Global pointer declarations
		private: physics::ModelPtr husky;
		private: physics::WorldPtr world;
		private: sdf::ElementPtr sdf;
		private: event::ConnectionPtr _updateConnection;
		private: boost::thread _spinnerThread;

		private: physics::JointPtr front_left_joint;
		private: physics::JointPtr front_right_joint;
		private: physics::JointPtr back_left_joint;
		private: physics::JointPtr back_right_joint;
		private: float front_left_wrench;
		private: float front_right_wrench;
		private: float back_left_wrench;
		private: float back_right_wrench;

		private: ros::Subscriber subscriber;

	};

	GZ_REGISTER_MODEL_PLUGIN(MoveHusky);
}
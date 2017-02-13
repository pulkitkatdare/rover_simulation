#include <rover_sim_plugin.hh>

namespace gazebo {

	RoverControl::RoverControl() : ModelPlugin() {
		ROS_INFO("Rover added to world.\n");
	}

	void RoverControl::Load(physics::ModelPtr _model, sdf::ElementPtr _sdf) {

		if (!ros::isInitialized()) {
			
			ROS_FATAL_STREAM("A ROS node for Gazebo has not been initialized, unable to load plugin.\n");
			return;
	
	    	this->rover = _model;
			this->sdf   = _sdf;
			this->world = rover->GetWorld();

			if (!_sdf->HasElement("topicName")) {
				ROS_WARN("Missing parameter <topicName> in rover_gazebo, default to /cmd_vel.");
				this->topic = "/cmd_vel";
			}
			else this->topic = _sdf->GetElement("topicName")->GetValueString();

			this->front_left_drive  = rover->GetJoint("front_L_wheel");
			this->front_right_drive = rover->GetJoint("front_R_wheel");
			this->mid_left_drive    = rover->GetJoint("center_L_wheel");
			this->mid_right_drive   = rover->GetJoint("center_R_wheel");
			this->back_left_drive   = rover->GetJoint("rear_L_wheel");
			this->back_right_drive  = rover->GetJoint("rear_R_wheel");

			// this->front_left_steer  = rover->GetJoint("front_left_steer");
			// this->front_right_steer = rover->GetJoint("front_right_steer");
			// this->back_left_steer   = rover->GetJoint("back_left_steer");
			// this->back_right_steer  = rover->GetJoint("back_right_steer");

			this->front_left_vel  = 0;
			this->front_right_vel = 0;
			this->mid_left_vel    = 0;
			this->mid_right_vel   = 0;
			this->back_left_vel   = 0;
			this->back_right_vel  = 0;

			this->front_left_ang  = 0;
			this->front_right_ang = 0;
			this->back_left_ang   = 0;
			this->back_right_ang  = 0;

			this->lin_vel = 0;
			this->ang_vel = 0;

			this->_spinnerThread = boost::thread(boost::bind(&RoverControl::LoadThread, this));

		}
	}

	void RoverControl::LoadThread() {

		if(!this->rover){
			ROS_FATAL_STREAM("Rover plugin requires a rover as its parent.\n");
			return;
		}

		ros::NodeHandle _nh("rover_sim_plugin");

		subscriber = _nh.subscribe(topic, 1000, &RoverControl::RoverStateCallback, this);
		this->_updateConnection = event::Events::ConnectWorldUpdateBegin(boost::bind(&RoverControl::OnUpdate, this, _1));

		ROS_INFO("Rover plugin for ROS successfully loaded.\n");

		while(ros::ok()){
			ros::spinOnce();
		}
	}

	void RoverControl::RoverStateCallback(const geometry_msgs::Twist::ConstPtr& rx_msg) {
		
		this->lin_vel = rx_msg->linear.x;
		this->ang_vel = rx_msg->angular.z;

		// Calculate all velocities/angles here
		// front_left_vel  = rx_msg->data[0];
		// front_right_vel = rx_msg->data[1];
		// back_left_vel   = rx_msg->data[2];
		// back_right_vel  = rx_msg->data[3];
	}

	void RoverControl::OnUpdate(const common::UpdateInfo &) {
		// if ( subscriber.getNumPublishers() != 0 ) {
		//     this->front_left_joint->SetVelocity(0,front_left_vel);
		//     this->front_right_joint->SetVelocity(0,front_right_vel);
		//     this->back_left_joint->SetVelocity(0,back_left_vel);
		//     this->back_right_joint->SetVelocity(0,back_right_vel);
		//   }
		//   else {
		//     this->front_left_joint->SetVelocity(0,0);
		//     this->front_right_joint->SetVelocity(0,0);
		//     this->back_left_joint->SetVelocity(0,0);
		//     this->back_right_joint->SetVelocity(0,0);
		// }
	}

}

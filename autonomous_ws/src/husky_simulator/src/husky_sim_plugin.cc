#include <husky_simulator/husky_sim_plugin.hh>

namespace gazebo {

	MoveHusky::MoveHusky() : ModelPlugin() {
		ROS_INFO("Husky with Hokuyo added to world.\n");
	}

	void MoveHusky::Load(physics::ModelPtr _model, sdf::ElementPtr _sdf) {

		if (!ros::isInitialized()) {
			
			ROS_FATAL_STREAM("A ROS node for Gazebo has not been initialized, unable to load plugin.\n");
			return;
	
	    	this->husky = _model;
			this->sdf   = _sdf;
			this->world = husky->GetWorld();

			this->front_left_joint  = husky->GetJoint("front_left_joint");
			this->front_right_joint = husky->GetJoint("front_right_joint");
			this->back_left_joint   = husky->GetJoint("back_left_joint");
			this->back_right_joint  = husky->GetJoint("back_right_joint");

			this->front_left_wrench  = 0;
			this->front_right_wrench = 0;
			this->back_left_wrench   = 0;
			this->back_right_wrench	 = 0;

			this->_spinnerThread = boost::thread(boost::bind(&MoveHusky::LoadThread, this));

		}

	}

	void MoveHusky::LoadThread() {

		if(!this->husky){
			ROS_FATAL_STREAM("Husky plugin requires a husky as its parent.\n");
			return;
		}

		ros::NodeHandle _nh("husky_sim_plugin");
		subscriber = _nh.subscribe("husky_directives", 1000, &MoveHusky::HuskyStateCallback, this);
		this->_updateConnection = event::Events::ConnectWorldUpdateBegin(boost::bind(&MoveHusky::OnUpdate, this, _1));

		ROS_INFO("Husky plugin for ROS successfully loaded.\n");

		// Check for new messages
		//      ros::spin();
		while(ros::ok()){
			ros::spinOnce();
		}
	}

	void MoveHusky::HuskyStateCallback(const std_msgs::Float64MultiArray::ConstPtr& rx_msg) {
		front_left_wrench  = rx_msg->data[0];
		front_right_wrench = rx_msg->data[1];
		back_left_wrench   = rx_msg->data[2];
		back_right_wrench  = rx_msg->data[3];
	}

	void MoveHusky::OnUpdate(const common::UpdateInfo &) {
		if ( subscriber.getNumPublishers() != 0 ) {
		    this->front_left_joint->SetForce(0,front_left_wrench);
		    this->front_right_joint->SetForce(0,front_right_wrench);
		    this->back_left_joint->SetForce(0,back_left_wrench);
		    this->back_right_joint->SetForce(0,back_right_wrench);
		  }
		  else {
		    this->front_left_joint->SetForce(0,0);
		    this->front_right_joint->SetForce(0,0);
		    this->back_left_joint->SetForce(0,0);
		    this->back_right_joint->SetForce(0,0);
		}
	}

}
#pragma once

class Networking {
public:
	void KeepCommunication( );
	void PushCommand( int command_number );
	bool ShouldProcessPacketStart( int command_number );
private:
	std::vector< int > m_command_list;
};

inline Networking g_networking;
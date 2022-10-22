#include "includes.h"

void Networking::KeepCommunication( ) {
	if( !g_cl.m_processing )
		return;

	const auto net_channel = g_csgo.m_cl->m_net_channel;
	if( !net_channel )
		return;

	const auto current_choke = net_channel->m_choked_packets;

	net_channel->m_choked_packets = 0;
	net_channel->SendDatagram( );

	--net_channel->m_out_seq;
	net_channel->m_choked_packets = current_choke;
}

void Networking::PushCommand( int command_number ) {
	if( m_command_list.size( ) > 32 )
		m_command_list.clear( );

	m_command_list.emplace_back( command_number );
}

bool Networking::ShouldProcessPacketStart( int command_number ) {
	if( !g_cl.m_processing || !g_csgo.m_engine->IsInGame( ) )
		return false;

	for( auto m_cmd = m_command_list.begin( ); m_cmd != m_command_list.end( ); m_cmd++ ) {
		if( *m_cmd != command_number )
			continue;

		m_command_list.erase( m_cmd );
		return true;
	}

	return false;
}
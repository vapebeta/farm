#pragma once

class AimPlayer;

class LagCompensation {
public:
	enum LagType : size_t {
		INVALID = 0,
		CONSTANT,
		ADAPTIVE,
		RANDOM,

	};

	/*struct SequenceObject_t
	{
		SequenceObject_t(int iInReliableState, int iOutReliableState, int iSequenceNr, float flCurrentTime)
			: iInReliableState(iInReliableState), iOutReliableState(iOutReliableState), iSequenceNr(iSequenceNr), flCurrentTime(flCurrentTime) { }

		int iInReliableState;
		int iOutReliableState;
		int iSequenceNr;
		float flCurrentTime;
	};*/

	//Values
	//std::deque<SequenceObject_t> vecSequences = { };

public:
	bool StartPrediction( AimPlayer* player );
	void PlayerMove( LagRecord* record );
	void AirAccelerate( LagRecord* record, ang_t angle, float fmove, float smove );
	void PredictAnimations( CCSGOPlayerAnimState* state, LagRecord* record );
	//void LagCompensation::AddLatencyToNetChannel(INetChannel* pNetChannel, float flLatency)
};

extern LagCompensation g_lagcomp;
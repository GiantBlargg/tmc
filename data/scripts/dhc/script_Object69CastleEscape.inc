@ DHC OBJECT_69 trying to escape the collapsing castle
SCRIPT_START script_Object69CastleEscape
	_0807E864
	Call sub_0807F9A4
	Call sub_0807DF28
	StartPlayerScript script_PlayerCastleEscape
	WaitForSyncFlagAndClear 0x00000001
	WaitForSyncFlagAndClear 0x00000002
	_0807EB28 0x1647
	WaitUntilTextboxCloses
	SetLocalFlag 0x007a
	Call sub_0807DF50
	_0807E878
	DoPostScriptAction 0x0006
SCRIPT_END
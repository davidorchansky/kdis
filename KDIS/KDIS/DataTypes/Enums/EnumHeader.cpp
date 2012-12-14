/*********************************************************************
KDIS is free software; you can redistribute it and/or modify it under the
terms of the GNU Lesser General Public License as published by the Free Software
Foundation; either version 2 of the License, or (at your option)
any later version.

KDIS is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along
with this library; if not, write to the Free Software Foundation, Inc.,
59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.

For Further Information Please Contact me at
Karljj1@yahoo.com
http://p.sf.net/kdis/UserGuide
*********************************************************************/

#include "./EnumHeader.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

// Implementation of string values for ProtocolVersion

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor ProtocolVersionDescriptor[] =
{
    { 0 , "Other_PV" },
    { 1 , "DIS_PDU_Version_1" },
    { 2 , "IEEE_1278_1993" },
    { 3 , "DIS_PDU_Version_2_Third_Draft" },
    { 4 , "DIS_PDU_Version_2_Fourth_Draft" },
    { 5 , "IEEE_1278_1_1995" },
    { 6 , "IEEE_1278_1A_1998" },
    { 7 , "IEEE_1278_1_200x" }
};

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringProtocolVersion( KINT32 Value )
{
    return GetEnumAsString( ProtocolVersionDescriptor, sizeof( ProtocolVersionDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringProtocolVersion( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( ProtocolVersionDescriptor, sizeof( ProtocolVersionDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringProtocolVersion( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
};

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringProtocolVersion( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for PDUType

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor PDUTypeDescriptor[] =
{
    { 0 , "Other_PDU_Type" },
    { 1 , "Entity_State_PDU_Type" },
    { 2 , "Fire_PDU_Type" },
    { 3 , "Detonation_PDU_Type" },
    { 4 , "Collision_PDU_Type" },
    { 5 , "Service_Request_PDU_Type" },
    { 6 , "Resupply_Offer_PDU_Type" },
    { 7 , "Resupply_Received_PDU_Type" },
    { 8 , "Resupply_Cancel_PDU_Type" },
    { 9 , "Repair_Complete_PDU_Type" },
    { 10 , "Repair_Response_PDU_Type" },
    { 11 , "Create_Entity_PDU_Type" },
    { 12 , "Remove_Entity_PDU_Type" },
    { 13 , "Start_Resume_PDU_Type" },
    { 14 , "Stop_Freeze_PDU_Type" },
    { 15 , "Acknowledge_PDU_Type" },
    { 16 , "Action_Request_PDU_Type" },
    { 17 , "Action_Response_PDU_Type" },
    { 18 , "Data_Query_PDU_Type" },
    { 19 , "Set_Data_PDU_Type" },
    { 20 , "Data_PDU_Type" },
    { 21 , "Event_Report_PDU_Type" },
    { 22 , "Message_PDU_Type" },
    { 23 , "Electromagnetic_Emission_PDU_Type" },
    { 24 , "Designator_PDU_Type" },
    { 25 , "Transmitter_PDU_Type" },
    { 26 , "Signal_PDU_Type" },
    { 27 , "Receiver_PDU_Type" },
    { 28 , "IFF_ATC_NAVAIDS_PDU_Type" },
    { 29 , "UnderwaterAcoustic_PDU_Type" },
    { 30 , "SupplementalEmission_EntityState_PDU_Type" },
    { 31 , "IntercomSignal_PDU_Type" },
    { 32 , "IntercomControl_PDU_Type" },
    { 33 , "AggregateState_PDU_Type" },
    { 34 , "IsGroupOf_PDU_Type" },
    { 35 , "TransferControl_PDU_Type" },
    { 36 , "IsPartOf_PDU_Type" },
    { 37 , "MinefieldState_PDU_Type" },
    { 38 , "MinefieldQuery_PDU_Type" },
    { 39 , "MinefieldData_PDU_Type" },
    { 40 , "MinefieldResponseNAK_PDU_Type" },
    { 41 , "EnvironmentalProcess_PDU_Type" },
    { 42 , "GriddedData_PDU_Type" },
    { 43 , "PointObjectState_PDU_Type" },
    { 44 , "LinearObjectState_PDU_Type" },
    { 45 , "ArealObjectState_PDU_Type" },
    { 46 , "TSPI_PDU_Type" },
    { 47 , "Appearance_PDU_Type" },
    { 48 , "ArticulatedParts_PDU_Type" },
    { 49 , "LEFire_PDU_Type" },
    { 50 , "LEDetonation_PDU_Type" },
    { 51 , "CreateEntity_R_PDU_Type" },
    { 52 , "RemoveEntity_R_PDU_Type" },
    { 53 , "Start_Resume_R_PDU_Type" },
    { 54 , "Stop_Freeze_R_PDU_Type" },
    { 55 , "Acknowledge_R_PDU_Type" },
    { 56 , "ActionRequest_R_PDU_Type" },
    { 57 , "ActionResponse_R_PDU_Type" },
    { 58 , "DataQuery_R_PDU_Type" },
    { 59 , "SetData_R_PDU_Type" },
    { 60 , "Data_R_PDU_Type" },
    { 61 , "EventReport_R_PDU_Type" },
    { 62 , "Comment_R_PDU_Type" },
    { 63 , "Record_R_PDU_Type" },
    { 64 , "SetRecord_R_PDU_Type" },
    { 65 , "RecordQuery_R_PDU_Type" },
    { 66 , "Collision_Elastic_PDU_Type" },
    { 67 , "EntityStateUpdate_PDU_Type" },
    { 68 , "DirectedEnergyFire_PDU_Type" },
    { 69 , "EntityDamageStatus_PDU_Type" },
    { 70 , "IO_Action_PDU_Type" },
    { 71 , "IO_Report_PDU_Type" },
    { 72 , "Attribute_PDU_Type" },
    { 129 , "Announce_Object_PDU_Type" },
    { 130 , "Delete_Object_PDU_Type" },
    { 132 , "Describe_Event_PDU_Type" },
    { 133 , "Describe_Object_PDU_Type" },
    { 134 , "Request_Event_PDU_Type" },
    { 135 , "Request_Object_PDU_Type" }
};

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringPDUType( KINT32 Value )
{
    return GetEnumAsString( PDUTypeDescriptor, sizeof( PDUTypeDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringPDUType( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( PDUTypeDescriptor, sizeof( PDUTypeDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringPDUType( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
};

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringPDUType( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for ProtocolFamily

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor ProtocolFamilyDescriptor[] =
{
    { 0 , "Other_PFF" },
    { 1 , "Entity_Information_Interaction" },
    { 2 , "Warfare" },
    { 3 , "Logistics" },
    { 4 , "Radio_Communications" },
    { 5 , "Simulation_Management" },
    { 6 , "Distributed_Emission_Regeneration" },
    { 7 , "EntityManagement" },
    { 8 , "Minefield" },
    { 9 , "SyntheticEnvironment" },
    { 10 , "SimulationManagementwithReliability" },
    { 11 , "LiveEntity" },
    { 12 , "Non_RealTime" },
    { 13 , "Information_Operations" },
    { 129 , "Experimental_CGF" },
    { 130 , "Experimental_Entity_Infomation_Field_Instrumentation" },
    { 131 , "Experimental_Warfare_Field_Instrumentation" },
    { 132 , "Experimental_Enviroment_Object_Infomation_Interaction" },
    { 133 , "Experimental_Entity_Management" }
};

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringProtocolFamily( KINT32 Value )
{
    return GetEnumAsString( ProtocolFamilyDescriptor, sizeof( ProtocolFamilyDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringProtocolFamily( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( ProtocolFamilyDescriptor, sizeof( ProtocolFamilyDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringProtocolFamily( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
};

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringProtocolFamily( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for TimeStampType

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor TimeStampTypeDescriptor[] =
{
    { 0 , "RelativeTime" },
    { 1, "AbsoluteTime" }
};

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringTimeStampType( KINT32 Value )
{
    return GetEnumAsString( TimeStampTypeDescriptor, sizeof( TimeStampTypeDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringTimeStampType( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( TimeStampTypeDescriptor, sizeof( TimeStampTypeDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringTimeStampType( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
};

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringTimeStampType( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif

//////////////////////////////////////////////////////////////////////////

// Implementation of string values for LVCIndicator

#if DIS_VERSION > 6
#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor LVCIndicatorDescriptor[] =
{
    { 0 , "No Statement LVC" },
    { 1 , "Live LVC" },
    { 2 , "Virtual LVC" },
    { 3 , "Constructive LVC" }
};

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringLVCIndicator( KINT32 Value )
{
    return GetEnumAsString( LVCIndicatorDescriptor, sizeof( LVCIndicatorDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringLVCIndicator( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( LVCIndicatorDescriptor, sizeof( LVCIndicatorDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringLVCIndicator( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
};

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringLVCIndicator( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif
#endif
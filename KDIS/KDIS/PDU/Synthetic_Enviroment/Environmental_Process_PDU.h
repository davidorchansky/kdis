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

/********************************************************************
    class:      Environmental_Process_PDU
    DIS:        (6) 1278.1a - 1998 & (7) 1278.1 - 200x draft 14
    created:    10/08/2009
    author:     Karl Jones

    purpose:    Used to communicate information about environmental effects and processes.

    size:       256 bits / 32 octets - Min size
*********************************************************************/

#pragma once

#include "./../Header.h"
#include "./../../DataTypes/EntityIdentifier.h"
#include "./../../DataTypes/EnvironmentType.h"
#include "./../../DataTypes/EnvironmentRecord.h"
#include "./../../Extras/KRef_Ptr.h"
#include <vector>

// Geometry records available
#include "./../../DataTypes/PointRecord1.h"
#include "./../../DataTypes/PointRecord2.h"
#include "./../../DataTypes/LineRecord1.h"
#include "./../../DataTypes/LineRecord2.h"
#include "./../../DataTypes/BoundingSphereRecord.h"
#include "./../../DataTypes/SphereRecord1.h"
#include "./../../DataTypes/SphereRecord2.h"
#include "./../../DataTypes/EllipsoidRecord1.h"
#include "./../../DataTypes/EllipsoidRecord2.h"
#include "./../../DataTypes/ConeRecord1.h"
#include "./../../DataTypes/ConeRecord2.h"
#include "./../../DataTypes/RectangularVolumeRecord1.h"
#include "./../../DataTypes/RectangularVolumeRecord2.h"
#include "./../../DataTypes/RectangularVolumeRecord3.h"
#include "./../../DataTypes/GaussianPlumeRecord.h"
#include "./../../DataTypes/GaussianPuffRecord.h"

// State records available
#include  "./../../DataTypes/COMBICState.h"
#include  "./../../DataTypes/FlareState.h"

namespace KDIS {
namespace PDU {

using KDIS::DATA_TYPE::EntityIdentifier;
using KDIS::DATA_TYPE::EnvironmentType;
using KDIS::DATA_TYPE::PointRecord1;
using KDIS::DATA_TYPE::PointRecord2;
using KDIS::DATA_TYPE::LineRecord1;
using KDIS::DATA_TYPE::LineRecord2;
using KDIS::DATA_TYPE::BoundingSphereRecord;
using KDIS::DATA_TYPE::SphereRecord1;
using KDIS::DATA_TYPE::SphereRecord2;
using KDIS::DATA_TYPE::EllipsoidRecord1;
using KDIS::DATA_TYPE::EllipsoidRecord2;
using KDIS::DATA_TYPE::ConeRecord1;
using KDIS::DATA_TYPE::ConeRecord2;
using KDIS::DATA_TYPE::RectangularVolumeRecord1;
using KDIS::DATA_TYPE::RectangularVolumeRecord2;
using KDIS::DATA_TYPE::RectangularVolumeRecord3;
using KDIS::DATA_TYPE::GaussianPlumeRecord;
using KDIS::DATA_TYPE::GaussianPuffRecord;
using KDIS::DATA_TYPE::EnvironmentRecord;
using KDIS::DATA_TYPE::COMBICState;
using KDIS::DATA_TYPE::FlareState;
using KDIS::DATA_TYPE::EnvironmentRecord;
using KDIS::DATA_TYPE::EnviromentRecordPtr;

class KDIS_EXPORT Environmental_Process_PDU : public Header
{
protected:

    EntityIdentifier m_EnvProcID;

    EnvironmentType m_EnvType;

    KUINT8 m_ui8ModelType;

    union
    {
        struct
        {
            KUINT8 m_ui8EnvStatusBit0   : 1;
            KUINT8 m_ui8EnvStatusBit1   : 1;
            KUINT8 m_ui8EnvStatusUnused : 6;
        };

        KUINT8 m_ui8EnvStatus;
    };

    KUINT16 m_ui16NumEnvRec;

    KUINT16 m_ui16SeqNum;

    vector<EnviromentRecordPtr> m_vEnvRecords;

public:

    static const KUINT16 ENVIROMENTAL_PROCESS_PDU_SIZE = 32; // Min size

    Environmental_Process_PDU( void );

    Environmental_Process_PDU( KDataStream & stream ) throw( KException );

    Environmental_Process_PDU( const EntityIdentifier & EnvironmentalProcessID, const EnvironmentType & ET,
                               KUINT8 ModelType, KBOOL EnvironmentStatusLast, KBOOL EnvironmentStatusOn,
                               KUINT16 SequenceNumber );

    Environmental_Process_PDU( const EntityIdentifier & EnvironmentalProcessID, const EnvironmentType & ET,
                               KUINT8 ModelType, KBOOL EnvironmentStatusLast, KBOOL EnvironmentStatusOn,
                               KUINT16 SequenceNumber, const vector<EnviromentRecordPtr> & ERL );

    virtual ~Environmental_Process_PDU( void );

    //************************************
    // FullName:    KDIS::PDU::Environmental_Process_PDU::SetEnvironmentalProcessID
    //              KDIS::PDU::Environmental_Process_PDU::GetEnvironmentalProcessID
    // Description: Identifies the environmental process issuing the Environmental Process PDU.
    // Parameter:   const EntityIdentifier & ID, void
    //************************************
    void SetEnvironmentalProcessID( const EntityIdentifier & ID );
    const EntityIdentifier & GetEnvironmentalProcessID() const;
    EntityIdentifier & GetEnvironmentalProcessID();

    //************************************
    // FullName:    KDIS::PDU::Environmental_Process_PDU::SetEnvironmentType
    //              KDIS::PDU::Environmental_Process_PDU::GetEnvironmentType
    // Description: DIS enumeration identifying the type of environmental effect being described.
    // Parameter:   const EnvironmentType & ET, void
    //************************************
    void SetEnvironmentType( const EnvironmentType & ET );
    const EnvironmentType & GetEnvironmentType() const;
    EnvironmentType & GetEnvironmentType();

    //************************************
    // FullName:    KDIS::PDU::Environmental_Process_PDU::SetModelType
    //              KDIS::PDU::Environmental_Process_PDU::GetModelType
    // Description: Specifies the particular model being used to generate this
    //              environmental condition or entity.
    //              values for this enumeration shall be defined by the
    //              Exercise Manager prior to a simulation exercise.
    // Parameter:   const EnvironmentType & ET, void
    //************************************
    void SetModelType( KUINT8 MT );
    KUINT8 GetModelType() const;

    //************************************
    // FullName:    KDIS::PDU::Environmental_Process_PDU::SetEnvironmentStatus
    //              KDIS::PDU::Environmental_Process_PDU::SetEnvironmentStatus
    //              KDIS::PDU::Environmental_Process_PDU::SetEnvironmentStatusLast
    //              KDIS::PDU::Environmental_Process_PDU::SetEnvironmentStatusOn
    //              KDIS::PDU::Environmental_Process_PDU::GetEnvironmentStatus
    //              KDIS::PDU::Environmental_Process_PDU::IsEnvironmentStatusLast
    //              KDIS::PDU::Environmental_Process_PDU::IsEnvironmentStatusOn
    // Description: Identifies the status of the environmental condition or entity.
    //              Represented as a 8 bit boolean array where:
    //              bit 0 (Last) = Indicates that the current PDU shall be the last PDU for the specified process.
    //              bit 1 (On)   = Indicates that the specified environmental process is active.
    //              bits 2 - 7   = Unused.
    // Parameter:   KUINT8 ES, KBOOL Last, void
    // Parameter:   KBOOL On
    //************************************
    void SetEnvironmentStatus( KUINT8 ES );
    void SetEnvironmentStatus( KBOOL Last, KBOOL On );
    void SetEnvironmentStatusLast( KBOOL L );
    void SetEnvironmentStatusOn( KBOOL O );
    KUINT8 GetEnvironmentStatus() const;
    KBOOL IsEnvironmentStatusLast() const;
    KBOOL IsEnvironmentStatusOn() const;

    //************************************
    // FullName:    KDIS::PDU::Environmental_Process_PDU::GetNumberOfEnvironmentRecords
    // Description: Returns the number of environment records stored in the PDU.
    //************************************
    KUINT16 GetNumberOfEnvironmentRecords() const;

    //************************************
    // FullName:    KDIS::PDU::Environmental_Process_PDU::SetSequenceNumber
    // FullName:    KDIS::PDU::Environmental_Process_PDU::GetSequenceNumber
    // Description: Indicates the PDU sequence number for the environmental process if PDU sequencing is required.
    //              If PDU sequencing is not required, then this field shall contain EP_NO_SEQUENCE.
    //              If PDU sequencing is required, this field shall be set to zero for each exercise and sequentially
    //              incremented by one each time a PDU is issued by an environmental process.
    //              When all possible values are exhausted, the numbers shall be reused beginning at one.
    // Parameter:   KKUINT16 SN, void
    //************************************
    void SetSequenceNumber( KUINT16 SN );
    KUINT16 GetSequenceNumber() const;

    //************************************
    // FullName:    KDIS::PDU::Environmental_Process_PDU::SetEnvironmentRecords
    //              KDIS::PDU::Environmental_Process_PDU::GetEnvironmentRecords
    //              KDIS::PDU::Environmental_Process_PDU::AddEnviromentRecord
	//				KDIS::PDU::Environmental_Process_PDU::ClearEnviromentRecords
    // Description: Contains specific geometry, state, or bounding volume information.
    //              EnviromentRecordLst is a vector of safe pointers(referenced) to EnviromentRecord base classes.
    //
    //              - Geometry Records -
    //              These records describe a geometry within the engagement space. They may also describe the method by
    //              which that geometry shall be dead reckoned and the parameters used in that dead reckoning.
    //              If there are multiple geometry records in an Environmental Process PDU, then the first environmental
    //              record attached to the PDU shall be a bounding volume geometry record. The bounding volume is a
    //              sphere that encloses all the geometries described by this environmental process. The bounding volume shall
    //              not be dead reckoned. The bounding volume record is intended to be used for filtering by receiving applications.
    //              The following geometry records are available in KDIS. You can also create custom ones. See FactoryDecoder example.:
    //              -   PointRecord1
    //              -   PointRecord2
    //              -   LineRecord1
    //              -   LineRecord2
    //              -   BoundingSphereRecord
    //              -   SphereRecord1
    //              -   SphereRecord2
    //              -   EllipsoidRecord1
    //              -   EllipsoidRecord2
    //              -   ConeRecord1
    //              -   ConeRecord2
    //              -   RectangularVolumeRecord1
    //              -   RectangularVolumeRecord2
    //              -   RectangularVolumeRecord3
    //              -   GaussianPlumeRecord
    //              -   GaussianPuffRecord
    //
    //              - State Records -
    //              State records specify the value of environmental parameters within the specified volume or volumes. Each
    //              state record shall follow the geometry record that describes the region of influence for the parameters contained
    //              in that state record. They may also describe the method by which that parameter shall be dead reckoned
    //              and the parameters used in that dead reckoning. If an environmental process is associated with a
    //              particular entity within the simulation, then the associated Entity Identifier may be included within a state
    //              record. The state record may also contain the update rate for the environmental model it represents.
    //              The following state records are available:
    //              -   COMBICState
    //              -   FlareState
    //
    // Parameter:   const EnviromentRecordLst & ER, void, const EnviromentRecordPtr & ER
    //************************************
    void SetEnvironmentRecords( const vector<EnviromentRecordPtr> & ER );
    const vector<EnviromentRecordPtr> & GetEnvironmentRecords() const;
    void AddEnviromentRecord( EnviromentRecordPtr ER );
	void ClearEnviromentRecords();

    //************************************
    // FullName:    KDIS::PDU::Environmental_Process_PDU::GetAsString
    // Description: Returns a string representation of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Environmental_Process_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Environmental_Process_PDU::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Environmental_Process_PDU & Value ) const;
    KBOOL operator != ( const Environmental_Process_PDU & Value ) const;
};

}; // END namespace PDU
}; // END namespace KDIS
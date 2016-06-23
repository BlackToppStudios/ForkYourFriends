// © Copyright 2010 - 2016 BlackTopp Studios Inc.
/* This file is part of ForkYourFriends.

    The Mezzanine Engine is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    The Mezzanine Engine is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with The Mezzanine Engine.  If not, see <http://www.gnu.org/licenses/>.
*/
/* The original authors have included a copy of the license specified above in the
   'Docs' folder. See 'gpl.txt'
*/
/* We welcome the use of the Mezzanine engine to anyone, including companies who wish to
   Build professional software and charge for their product.

   However there are some practical restrictions, so if your project involves
   any of the following you should contact us and we will try to work something
   out:
    - DRM or Copy Protection of any kind(except Copyrights)
    - Software Patents You Do Not Wish to Freely License
    - Any Kind of Linking to Non-GPL licensed Works
    - Are Currently In Violation of Another Copyright Holder's GPL License
    - If You want to change our code and not add a few hundred MB of stuff to
        your distribution

   These and other limitations could cause serious legal problems if you ignore
   them, so it is best to simply contact us or the Free Software Foundation, if
   you have any questions.

   Joseph Toppi - toppij@gmail.com
   John Blackwood - makoenergy02@gmail.com
*/
#ifndef ForkYourFriends_forklift_cpp
#define ForkYourFriends_forklift_cpp

#include "forklift.h"

#include "Graphics/entityproxy.h"

#include "Physics/rigidproxy.h"
#include "Physics/hingeconstraint.h"
#include "Physics/hinge2constraint.h"
#include "Physics/sliderconstraint.h"

Forklift::Forklift(World* TheWorld) :
    Debris(TheWorld)
    { this->CreateForklift(); }

Forklift::Forklift(const String& Name, World* TheWorld) :
    Debris(Name,TheWorld)
    { this->CreateForklift(); }

Forklift::Forklift(const XML::Node& SelfRoot, World* TheWorld) :
    Debris(TheWorld)
    { this->ProtoDeSerialize(SelfRoot); }

Forklift::~Forklift()
    { this->DestroyForklift(); }

void Forklift::CreateForklift()
{

}

void Forklift::DestroyForklift()
{

}

///////////////////////////////////////////////////////////////////////////////
// Member Access

const ForkliftChassis& Forklift::GetChassis() const
    { return this->Chassis; }

const ForkliftSteering& Forklift::GetSteering() const
    { return this->Steering; }

const ForkliftLift& Forklift::GetLift() const
    { return this->Lift; }

const ForkliftWheel& Forklift::GetWheel(const Whole Index) const
    { return this->Wheels[Index]; }

///////////////////////////////////////////////////////////////////////////////
// Utility and Configuration

WorldObjectType Forklift::GetType() const
{
    return Mezzanine::WO_VehiclePlaceHolder1;
}

Boole Forklift::IsInWorld() const
{
    return false;
}

Boole Forklift::IsStatic() const
    { return this->Chassis.PhysicalChassis->IsStatic(); }

Boole Forklift::IsKinematic() const
    { return this->Chassis.PhysicalChassis->IsKinematic(); }

void Forklift::GetProxies(ProxyContainer& Proxies)
{

}

void Forklift::GetProxies(const UInt32 Types, ProxyContainer& Proxies)
{

}

///////////////////////////////////////////////////////////////////////////////
// Working with the World

void Forklift::AddToWorld()
{

}

void Forklift::RemoveFromWorld()
{

}

///////////////////////////////////////////////////////////////////////////////
// Transform Methods

void Forklift::SetLocation(const Vector3& Loc)
{

}

void Forklift::SetLocation(const Real X, const Real Y, const Real Z)
{

}

Vector3 Forklift::GetLocation() const
{
    return Vector3(1,1,1);
}

void Forklift::SetOrientation(const Quaternion& Ori)
{

}

void Forklift::SetOrientation(const Real X, const Real Y, const Real Z, const Real W)
{

}

Quaternion Forklift::GetOrientation() const
{
    return Quaternion(0,0,0,1);
}

void Forklift::SetScale(const Vector3& Sc)
{

}

void Forklift::SetScale(const Real X, const Real Y, const Real Z)
{

}

Vector3 Forklift::GetScale() const
{
    return Vector3(1,1,1);
}

void Forklift::Translate(const Vector3& Trans)
{

}

void Forklift::Translate(const Real X, const Real Y, const Real Z)
{

}

void Forklift::Yaw(const Real Angle)
{

}

void Forklift::Pitch(const Real Angle)
{

}

void Forklift::Roll(const Real Angle)
{

}

void Forklift::Rotate(const Vector3& Axis, const Real Angle)
{

}

void Forklift::Rotate(const Quaternion& Rotation)
{

}

void Forklift::Scale(const Vector3& Scale)
{

}

void Forklift::Scale(const Real X, const Real Y, const Real Z)
{

}

///////////////////////////////////////////////////////////////////////////////
// Serialization

void Forklift::ProtoSerializeProperties(XML::Node& SelfRoot) const
{

}

void Forklift::ProtoSerializeProxies(XML::Node& SelfRoot) const
{

}

void Forklift::ProtoDeSerializeProperties(const XML::Node& SelfRoot)
{

}

void Forklift::ProtoDeSerializeProxies(const XML::Node& SelfRoot)
{

}

String Forklift::GetDerivedSerializableName() const
    { return Forklift::GetSerializableName(); }

String Forklift::GetSerializableName()
    { return "Forklift"; }

///////////////////////////////////////////////////////////////////////////////
// Internal Methods

void Forklift::_Update()
{

}

void Forklift::_NotifyProxyDestroyed(WorldProxy* ToBeDestroyed)
{

}

#endif

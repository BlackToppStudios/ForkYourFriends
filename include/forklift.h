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

#ifndef ForkYourFriends_forklift_h
#define ForkYourFriends_forklift_h

#include "debris.h"

using namespace Mezzanine;

namespace Mezzanine
{
    namespace Graphics
    {
        class EntityProxy;      // For the visible bodies.
    }
    namespace Physics
    {
        class RigidProxy;       // For all of the physical bodies.
        class HingeConstraint;  // For the steering wheel.
        class Hinge2Constraint; // For the wheels (non-steering).
        class SliderConstraint; // For the lift.
    }
}

///////////////////////////////////////////////////////////////////////////////
/// @brief A struct storing the necessary data related to the chassis of a forklift.
///////////////////////////////////////
struct ForkliftChassis
{
    /// @brief A pointer to the graphics representation of the chassis.
    Graphics::EntityProxy* VisibleChassis;
    /// @brief A pointer to the physical representation of the chassis.
    Physics::RigidProxy* PhysicalChassis;
};//ForkliftChassis

///////////////////////////////////////////////////////////////////////////////
/// @brief A struct storing the necessary data related to the steering wheel of a forklift.
///////////////////////////////////////
struct ForkliftSteering
{
    /// @brief A pointer to the graphics representation of the steering wheel.
    Graphics::EntityProxy* VisibleSteering;
    /// @brief A pointer to the physical representation of the steering wheel.
    Physics::RigidProxy* PhysicalSteering;
    /// @brief A pointer to the constraint binding the steering wheel to the chassis.
    Physics::HingeConstraint* SteeringConstraint;
};//ForkliftSteeringWheel

///////////////////////////////////////////////////////////////////////////////
/// @brief A struct storing the necessary data related to the wheels of a forklift.
///////////////////////////////////////
struct ForkliftWheel
{
    /// @brief A pointer to the graphics representation of the wheel.
    Graphics::EntityProxy* VisibleWheel;
    /// @brief A pointer to the physical representation of the wheel.
    Physics::RigidProxy* PhysicalWheel;
    /// @brief A pointer to the constraint binding the wheel to the chassis.
    Physics::Hinge2Constraint* WheelConstraint;
};//ForkliftWheel

///////////////////////////////////////////////////////////////////////////////
/// @brief A struct storing the necessary data related to the lift of a forklift.
///////////////////////////////////////
struct ForkliftLift
{
    /// @brief A pointer to the graphics representation of the lift.
    Graphics::EntityProxy* VisibleLift;
    /// @brief A pointer to the physical representation of the lift.
    Physics::RigidProxy* PhysicalLift;
    /// @brief A pointer to the constraint binding the lift to the chassis.
    Physics::SliderConstraint* LiftConstraint;
};//ForkliftLift

///////////////////////////////////////////////////////////////////////////////
/// @brief The basic controllable object in ForkYourFriends.
///////////////////////////////////////
class Forklift : public Debris
{
public:
    /// @brief A simple enum using to simply track indexes to wheels.
    enum WheelIndex
    {
        Front_Left  = 0,
        Front_Right = 1,
        Back_Left   = 2,
        Back_Right  = 3
    };
protected:
    /// @brief Data storage for the chassis.
    ForkliftChassis Chassis;
    /// @brief Data storage for the steering wheel.
    ForkliftSteering Steering;
    /// @brief Data storage for the lift.
    ForkliftLift Lift;
    /// @brief A simple array to the wheels of the forklift.
    ForkliftWheel Wheels[4];

    /// @brief Common construction method for Forklift.
    void CreateForklift();
    /// @brief Destruction method for Forklift.
    void DestroyForklift();
public:
    /// @brief Blank constructor.
    /// @param TheWorld A pointer to the world this Forklift belongs to.
    Forklift(World* TheWorld);
    /// @brief Class constructor.
    /// @param Name The name to be given to this Forklift.
    /// @param TheWorld A pointer to the world this Forklift belongs to.
    Forklift(const String& Name, World* TheWorld);
    /// @brief XML constructor.
    /// @param SelfRoot An XML::Node containing the data to populate this class with.
    /// @param TheWorld A pointer to the world this Forklift belongs to.
    Forklift(const XML::Node& SelfRoot, World* TheWorld);
    /// @brief Class destructor.
    ~Forklift();

    ///////////////////////////////////////////////////////////////////////////////
    // Member Access

    /// @brief Gets the struct holding information about the chassis.
    /// @return Returns a const reference to the chassis data.
    const ForkliftChassis& GetChassis() const;
    /// @brief Gets the struct holding information about the steering wheel.
    /// @return Returns a const reference to the steering wheel data.
    const ForkliftSteering& GetSteering() const;
    /// @brief Gets the struct holding information about the lift.
    /// @return Returns a const reference to the lift data.
    const ForkliftLift& GetLift() const;
    /// @brief Gets the struct holding information about the wheel at the specified index.
    /// @param Index The index of the wheel to retrieve.
    /// @return Returns a const reference to the wheel at the specified index.
    const ForkliftWheel& GetWheel(const Whole Index) const;

    ///////////////////////////////////////////////////////////////////////////////
    // Utility and Configuration

    /// @copydoc Mezzanine::WorldObject::GetType() const
    WorldObjectType GetType() const;

    /// @copydoc Mezzanine::WorldObject::IsInWorld() const
    Boole IsInWorld() const;

    /// @copydoc Mezzanine::WorldObject::IsStatic() const
    Boole IsStatic() const;
    /// @copydoc Mezzanine::WorldObject::IsKinematic() const
    Boole IsKinematic() const;

    /// @copydoc Mezzanine::WorldObject::GetProxies(ProxyContainer&)
    void GetProxies(ProxyContainer& Proxies);
    /// @copydoc Mezzanine::WorldObject::GetProxies(const UInt32, ProxyContainer&)
    void GetProxies(const UInt32 Types, ProxyContainer& Proxies);

    ///////////////////////////////////////////////////////////////////////////////
    // Working with the World

    /// @copydoc Mezzanine::WorldObject::AddToWorld()
    void AddToWorld();
    /// @copydoc Mezzanine::WorldObject::RemoveFromWorld()
    void RemoveFromWorld();

    ///////////////////////////////////////////////////////////////////////////////
    // Transform Methods

    /// @copydoc TransformableObject::SetLocation(const Vector3&)
    void SetLocation(const Vector3& Loc);
    /// @copydoc TransformableObject::SetLocation(const Real, const Real, const Real)
    void SetLocation(const Real X, const Real Y, const Real Z);
    /// @copydoc TransformableObject::GetLocation() const
    Vector3 GetLocation() const;
    /// @copydoc TransformableObject::SetOrientation(const Quaternion&)
    void SetOrientation(const Quaternion& Ori);
    /// @copydoc TransformableObject::SetOrientation(const Real, const Real, const Real, const Real)
    void SetOrientation(const Real X, const Real Y, const Real Z, const Real W);
    /// @copydoc TransformableObject::GetOrientation() const
    Quaternion GetOrientation() const;
    /// @copydoc TransformableObject::SetScale(const Vector3&)
    void SetScale(const Vector3& Sc);
    /// @copydoc TransformableObject::SetScale(const Real, const Real, const Real)
    void SetScale(const Real X, const Real Y, const Real Z);
    /// @copydoc TransformableObject::GetScale() const
    Vector3 GetScale() const;

    /// @copydoc TransformableObject::Translate(const Vector3&)
    void Translate(const Vector3& Trans);
    /// @copydoc TransformableObject::Translate(const Real, const Real, const Real)
    void Translate(const Real X, const Real Y, const Real Z);
    /// @copydoc TransformableObject::Yaw(const Real)
    void Yaw(const Real Angle);
    /// @copydoc TransformableObject::Pitch(const Real)
    void Pitch(const Real Angle);
    /// @copydoc TransformableObject::Roll(const Real)
    void Roll(const Real Angle);
    /// @copydoc TransformableObject::Rotate(const Vector3&, const Real)
    void Rotate(const Vector3& Axis, const Real Angle);
    /// @copydoc TransformableObject::Rotate(const Quaternion&)
    void Rotate(const Quaternion& Rotation);
    /// @copydoc TransformableObject::Scale(const Vector3&)
    void Scale(const Vector3& Scale);
    /// @copydoc TransformableObject::Scale(const Real, const Real, const Real)
    void Scale(const Real X, const Real Y, const Real Z);

    ///////////////////////////////////////////////////////////////////////////////
    // Serialization

    /// @copydoc Mezzanine::WorldObject::ProtoSerializeProperties(XML::Node&) const
    void ProtoSerializeProperties(XML::Node& SelfRoot) const;
    /// @copydoc Mezzanine::WorldObject::ProtoSerializeProxies(XML::Node&) const
    void ProtoSerializeProxies(XML::Node& SelfRoot) const;

    /// @copydoc Mezzanine::WorldObject::ProtoDeSerializeProperties(const XML::Node&)
    void ProtoDeSerializeProperties(const XML::Node& SelfRoot);
    /// @copydoc Mezzanine::WorldObject::ProtoDeSerializeProxies(const XML::Node&)
    void ProtoDeSerializeProxies(const XML::Node& SelfRoot);

    /// @copydoc Mezzanine::WorldObject::GetDerivedSerializableName() const
    String GetDerivedSerializableName() const;
    /// @copydoc Mezzanine::WorldObject::GetSerializableName()
    static String GetSerializableName();

    ///////////////////////////////////////////////////////////////////////////////
    // Internal Methods

    /// @copydoc Mezzanine::WorldObject::_Update()
    void _Update();
    /// @copydoc Mezzanine::WorldObject::_NotifyProxyDestroyed(WorldProxy*)
    void _NotifyProxyDestroyed(WorldProxy* ToBeDestroyed);
};//Forklift

///////////////////////////////////////////////////////////////////////////////
/// @brief The factory for the basic controllable object in ForkYourFriends.
///////////////////////////////////////
class ForkliftFactory : public DebrisFactory
{
protected:
public:
    /// @brief Class constructor.
    ForkliftFactory();
    /// @brief Class destructor.
    ~ForkliftFactory();

    /// @copydoc DebrisFactory::GetTypeName() const
    virtual String GetTypeName() const;

    /// @copydoc DebrisFactory::CreateDebris(const String&, World*, const NameValuePairMap&)
    virtual Debris* CreateDebris(const String& Name, World* TheWorld, const NameValuePairMap& Params);
    /// @copydoc DebrisFactory::CreateDebris(const XML::Node&, World*)
    virtual Debris* CreateDebris(const XML::Node& XMLNode, World* TheWorld);
    /// @copydoc DebrisFactory::DestroyDebris(Debris* ToBeDestroyed)
    virtual void DestroyDebris(Debris* ToBeDestroyed);
};//Forklift

#endif

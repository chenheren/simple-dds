#pragma once

#include <memory>

namespace simple_dds
{
namespace dds
{
/**
 * DomainEntity is the abstract base class for all DCPS entities, except for the DomainParticipant.
 * Its sole purpose is to express that DomainParticipant is a special kind of Entity,
 * which acts as a container of all other Entity, but itself cannot contain other DomainParticipant
 */
class DomainEntity
{
public:
    virtual ~DomainEntity() = default;
};
}
}
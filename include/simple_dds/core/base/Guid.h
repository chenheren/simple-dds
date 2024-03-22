#pragma once

#include <cstring>
#include <arpa/inet.h>
#include <simple_dds/common/Type.h>

namespace simple_dds
{
/**
 * The GUID is an attribute present in all RTPS Entities
 * that uniquely identifies them within the DDS domain.
 */
class GuidPrefix
{
public:
    GuidPrefix()
    {
        std::memset(value, 0, size);
    }

    explicit GuidPrefix(octet prefix[])
    {
        std::memcpy(value, prefix, size);
    }

    explicit GuidPrefix(const GuidPrefix& prefix)
    {
        std::memcpy(value, prefix.value, size);
    }

    explicit GuidPrefix(GuidPrefix&& prefix)
    {
        std::memmove(value, prefix.value, size);
    }

    /**
     * GUIDPREFIX_UNKNOWN
     * all bit is0
     */
    static GuidPrefix unknown()
    {
        return GuidPrefix();
    }

    GuidPrefix& operator=(const GuidPrefix& prefix)
    {
        std::memcpy(value, prefix.value, size);
        return *this;
    }

    GuidPrefix& operator=(GuidPrefix&& prefix)
    {
        std::memmove(value, prefix.value, size);
        return *this;
    }

    bool operator==(const GuidPrefix& prefix)
    {
        return std::memcpy(value, prefix.value, size) == 0;
    }

    bool operator!=(const GuidPrefix& prefix)
    {
        return std::memcpy(value, prefix.value, size) != 0;
    }

public:
    static const int32_t size = 12;
    octet value[size];
};

class EntityId
{
public:
    EntityId()
    {
        memset(value, 0, size);
    }

    explicit EntityId(uint32_t id)
    {
        initFromNum(id);
    }

    explicit EntityId(const EntityId& id)
    {
        std::memcpy(value, id.value, size);
    }

    EntityId& operator=(const EntityId& id)
    {
        if (&id != this)
        {
            std::memcpy(value, id.value, size);
        }
        return *this;
    }

    EntityId& operator=(EntityId&& id) noexcept
    {
        std::memmove(value, id.value, size);
        return *this;
    }

    EntityId& operator=(std::uint32_t id)
    {
        initFromNum(id);
    }

    /**
     * ENTITYID_UNKNOWN
     * all bit is0
     */
    static EntityId unknown()
    {
        return EntityId();
    }

private:
    inline void initFromNum(std::uint32_t id)
    {
#ifdef BIG_ENDIAN
        *((std::uint32_t*)value) = htonl(id);
#elif
        *((std::uint32_t*)value) = id;
#endif
    }

public:
    static const int32_t size = 4;
    octet value[size];
};

class Guid
{
public:
    Guid()
    {
    }

    Guid(const Guid& guid)
    : guidPrefix_(guid.guidPrefix_)
    , entityId_(guid.entityId_)
    {

    }

    Guid(Guid&& guid)
    : guidPrefix_(std::move(guid.guidPrefix_))
    , entityId_(std::move(guid.entityId_))
    {

    }

    Guid(const GuidPrefix& prefix, std::uint32_t id)
    : guidPrefix_(prefix)
    , entityId_(id)
    {

    }

    Guid(const GuidPrefix& prefix, const EntityId& id)
    : guidPrefix_(prefix)
    , entityId_(id)
    {

    }

    Guid& operator=(const Guid& guid)
    {
        if (&guid != this)
        {
            guidPrefix_ = guid.guidPrefix_;
            entityId_ = guid.entityId_;
        }
        return *this;
    }

    Guid& operator=(Guid&& guid) noexcept
    {
        guidPrefix_ = std::move(guid.guidPrefix_);
        entityId_ = std::move(guid.entityId_);
        return *this;
    }

    static Guid unknown()
    {
        return Guid{};
    }

public:
    GuidPrefix guidPrefix_;
    EntityId entityId_;
};
}
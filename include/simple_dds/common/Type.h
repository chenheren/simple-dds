#pragma once

#include <cstdint>

namespace simple_dds
{
enum class ReturnCode_t: std::uint8_t
{
    OK,
    ERROR,
    BAD_PARAMETER,
    UNSUPPORTED,
    ALREADY_DEFINED,
    OUT_OF_RESOURCE,
    NOT_ENABLE,
    IMMUTABLE_POLICY,
    INCONSISTENT_POLICY,
    PRECONDITION_NOT_MET,
    TIMEOUT,
    ILLEGAL_OPERATION,
    NO_DATA
};

using DomainId_t = std::uint32_t;

struct Time_t
{
    long sec;
    unsigned long nanosec;
};

}
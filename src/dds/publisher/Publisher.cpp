#include <simple_dds/dds/publisher/Publisher.h>

namespace simple_dds
{
namespace dds
{
DataWriter* Publisher::create_datawriter(
    Topic* topic,
    const std::vector<QosPolicy>& qos,
    DataWriterListener* listener,
    const std::vector<Status>& mask)
{

}
}
}

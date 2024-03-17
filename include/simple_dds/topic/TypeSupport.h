#pragma once

#include <string>
#include <simple_dds/common/Type.h>
#include <simple_dds/domain/DomainParticipant.h>

namespace simple_dds
{
/**
 * The TypeSupport interface is an abstract interface that has to be specialized
 * for each concrete type that will be used by the application
 */
class TypeSupport
{
public:
    /**
     * This operation allows an application to communicate to the Service the existence of a data type. The generated implementation
     * of that operation embeds all the knowledge that has to be communicated to the middleware in order to make it able to manage
     * the contents of data of that data type. This includes in particular the key definition that will allow the Service to distinguish
     * different instances of the same type.
     * It is a pre-condition error to use the same type_name to register two different TypeSupport with the same DomainParticipant.
     * If an application attempts this, the operation will fail and return PRECONDITION_NOT_MET. However, it is allowed to
     * register the same TypeSupport multiple times with a DomainParticipant using the same or different values for the type_name.
     * If register_type is called multiple times on the same TypeSupport with the same DomainParticipant and type_name the
     * second (and subsequent) registrations are ignored but the operation returns OK.
     * The application may pass nil as the value for the type_name. In this case the default type-name as defined by the TypeSupport
     * (i.e., the value returned by the get_type_name operation) will be used.
     * Possible error codes returned in addition to the standard ones: PRECONDITION_NOT_MET and OUT_OF_RESOURCES.
     * @param participant
     * @param type_name
     * @return
     */
    ReturnCode_t register_type(DomainParticipant* participant, const std::string& type_name);

    /**
     * This operation returns the default name for the data-type represented by the TypeSupport.
     * @return
     */
    std::string get_type_name();

};
}
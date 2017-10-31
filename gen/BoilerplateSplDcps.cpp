#include "BoilerplateSplDcps.h"
#include "ccpp_Boilerplate.h"

#include <v_copyIn.h>
#include <v_topic.h>
#include <os_stdlib.h>
#include <string.h>
#include <os_report.h>

v_copyin_result
__Template__copyIn(
    c_base base,
    const struct Template *from,
    struct _Template *to)
{
    v_copyin_result result = V_COPYIN_RESULT_OK;
    (void) base;

    to->userID = (c_long)from->userID;
#ifdef OSPL_BOUNDS_CHECK
    if(from->message){
        to->message = c_stringNew_s(base, from->message);
        if(to->message == NULL) {
            result = V_COPYIN_RESULT_OUT_OF_MEMORY;
        }
    } else {
        OS_REPORT (OS_ERROR, "copyIn", 0,"Member 'Template.message' of type 'c_string' is NULL.");
        result = V_COPYIN_RESULT_INVALID;
    }
#else
    to->message = c_stringNew_s(base, from->message);
    if(to->message == NULL) {
        result = V_COPYIN_RESULT_OUT_OF_MEMORY;
    }
#endif
    return result;
}

v_copyin_result
__Sensor__copyIn(
    c_base base,
    const struct Sensor *from,
    struct _Sensor *to)
{
    v_copyin_result result = V_COPYIN_RESULT_OK;
    (void) base;

    to->userID = (c_long)from->userID;
#ifdef OSPL_BOUNDS_CHECK
    if(from->message){
        to->message = c_stringNew_s(base, from->message);
        if(to->message == NULL) {
            result = V_COPYIN_RESULT_OUT_OF_MEMORY;
        }
    } else {
        OS_REPORT (OS_ERROR, "copyIn", 0,"Member 'Sensor.message' of type 'c_string' is NULL.");
        result = V_COPYIN_RESULT_INVALID;
    }
#else
    to->message = c_stringNew_s(base, from->message);
    if(to->message == NULL) {
        result = V_COPYIN_RESULT_OUT_OF_MEMORY;
    }
#endif
    return result;
}

void
__Template__copyOut(
    const void *_from,
    void *_to)
{
    const struct _Template *from = (const struct _Template *)_from;
    struct Template *to = (struct Template *)_to;
    to->userID = (::DDS::Long)from->userID;
    to->message = DDS::string_dup(from->message ? from->message : "");
}

void
__Sensor__copyOut(
    const void *_from,
    void *_to)
{
    const struct _Sensor *from = (const struct _Sensor *)_from;
    struct Sensor *to = (struct Sensor *)_to;
    to->userID = (::DDS::Long)from->userID;
    to->message = DDS::string_dup(from->message ? from->message : "");
}


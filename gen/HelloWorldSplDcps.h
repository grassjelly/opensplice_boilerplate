#ifndef HELLOWORLDSPLTYPES_H
#define HELLOWORLDSPLTYPES_H

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>
#include <v_copyIn.h>

#include "ccpp_HelloWorld.h"


extern const char *Msg_metaDescriptor[];
extern const int Msg_metaDescriptorArrLength;
extern const int Msg_metaDescriptorLength;
extern c_metaObject __Msg__load (c_base base);
struct _Msg ;
extern  v_copyin_result __Msg__copyIn(c_base base, const struct Msg *from, struct _Msg *to);
extern  void __Msg__copyOut(const void *_from, void *_to);
struct _Msg {
    c_long userID;
    c_string message;
};

extern const char *Sensor_metaDescriptor[];
extern const int Sensor_metaDescriptorArrLength;
extern const int Sensor_metaDescriptorLength;
extern c_metaObject __Sensor__load (c_base base);
struct _Sensor ;
extern  v_copyin_result __Sensor__copyIn(c_base base, const struct Sensor *from, struct _Sensor *to);
extern  void __Sensor__copyOut(const void *_from, void *_to);
struct _Sensor {
    c_long userID;
    c_string message;
};

#undef OS_API
#endif

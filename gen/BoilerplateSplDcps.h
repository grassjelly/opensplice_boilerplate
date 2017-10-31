#ifndef BOILERPLATESPLTYPES_H
#define BOILERPLATESPLTYPES_H

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>
#include <v_copyIn.h>

#include "ccpp_Boilerplate.h"


extern const char *Template_metaDescriptor[];
extern const int Template_metaDescriptorArrLength;
extern const int Template_metaDescriptorLength;
extern c_metaObject __Template__load (c_base base);
struct _Template ;
extern  v_copyin_result __Template__copyIn(c_base base, const struct Template *from, struct _Template *to);
extern  void __Template__copyOut(const void *_from, void *_to);
struct _Template {
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

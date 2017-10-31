//******************************************************************
// 
//  Generated by IDL to C++ Translator
//  
//  File name: BoilerplateDcps.cpp
//  Source: gen/BoilerplateDcps.idl
//  Generated: Wed Nov  1 02:24:33 2017
//  OpenSplice 6.7.170912OSS
//  
//******************************************************************

#include "BoilerplateDcps.h"

#if DDS_USE_EXPLICIT_TEMPLATES
template class DDS_DCPSUVLSeq < Sensor, struct SensorSeq_uniq_>;
#endif
#if DDS_USE_EXPLICIT_TEMPLATES
template class DDS_DCPSUVLSeq < Template, struct TemplateSeq_uniq_>;
#endif

const char * TemplateTypeSupportInterface::_local_id = "IDL:TemplateTypeSupportInterface:1.0";

TemplateTypeSupportInterface_ptr TemplateTypeSupportInterface::_duplicate (TemplateTypeSupportInterface_ptr p)
{
   if (p) p->m_count++;
   return p;
}

DDS::Boolean TemplateTypeSupportInterface::_local_is_a (const char * _id)
{
   if (strcmp (_id, TemplateTypeSupportInterface::_local_id) == 0)
   {
      return true;
   }

   typedef DDS::TypeSupport NestedBase_1;

   if (NestedBase_1::_local_is_a (_id))
   {
      return true;
   }

   return false;
}

TemplateTypeSupportInterface_ptr TemplateTypeSupportInterface::_narrow (DDS::Object_ptr p)
{
   TemplateTypeSupportInterface_ptr result = NULL;
   if (p && p->_is_a (TemplateTypeSupportInterface::_local_id))
   {
      result = dynamic_cast < TemplateTypeSupportInterface_ptr> (p);
      if (result) result->m_count++;
   }
   return result;
}

TemplateTypeSupportInterface_ptr TemplateTypeSupportInterface::_unchecked_narrow (DDS::Object_ptr p)
{
   TemplateTypeSupportInterface_ptr result;
   result = dynamic_cast < TemplateTypeSupportInterface_ptr> (p);
   if (result) result->m_count++;
   return result;
}

const char * TemplateDataWriter::_local_id = "IDL:TemplateDataWriter:1.0";

TemplateDataWriter_ptr TemplateDataWriter::_duplicate (TemplateDataWriter_ptr p)
{
   if (p) p->m_count++;
   return p;
}

DDS::Boolean TemplateDataWriter::_local_is_a (const char * _id)
{
   if (strcmp (_id, TemplateDataWriter::_local_id) == 0)
   {
      return true;
   }

   typedef DDS::DataWriter NestedBase_1;

   if (NestedBase_1::_local_is_a (_id))
   {
      return true;
   }

   return false;
}

TemplateDataWriter_ptr TemplateDataWriter::_narrow (DDS::Object_ptr p)
{
   TemplateDataWriter_ptr result = NULL;
   if (p && p->_is_a (TemplateDataWriter::_local_id))
   {
      result = dynamic_cast < TemplateDataWriter_ptr> (p);
      if (result) result->m_count++;
   }
   return result;
}

TemplateDataWriter_ptr TemplateDataWriter::_unchecked_narrow (DDS::Object_ptr p)
{
   TemplateDataWriter_ptr result;
   result = dynamic_cast < TemplateDataWriter_ptr> (p);
   if (result) result->m_count++;
   return result;
}

const char * TemplateDataReader::_local_id = "IDL:TemplateDataReader:1.0";

TemplateDataReader_ptr TemplateDataReader::_duplicate (TemplateDataReader_ptr p)
{
   if (p) p->m_count++;
   return p;
}

DDS::Boolean TemplateDataReader::_local_is_a (const char * _id)
{
   if (strcmp (_id, TemplateDataReader::_local_id) == 0)
   {
      return true;
   }

   typedef DDS::DataReader NestedBase_1;

   if (NestedBase_1::_local_is_a (_id))
   {
      return true;
   }

   return false;
}

TemplateDataReader_ptr TemplateDataReader::_narrow (DDS::Object_ptr p)
{
   TemplateDataReader_ptr result = NULL;
   if (p && p->_is_a (TemplateDataReader::_local_id))
   {
      result = dynamic_cast < TemplateDataReader_ptr> (p);
      if (result) result->m_count++;
   }
   return result;
}

TemplateDataReader_ptr TemplateDataReader::_unchecked_narrow (DDS::Object_ptr p)
{
   TemplateDataReader_ptr result;
   result = dynamic_cast < TemplateDataReader_ptr> (p);
   if (result) result->m_count++;
   return result;
}

const char * TemplateDataReaderView::_local_id = "IDL:TemplateDataReaderView:1.0";

TemplateDataReaderView_ptr TemplateDataReaderView::_duplicate (TemplateDataReaderView_ptr p)
{
   if (p) p->m_count++;
   return p;
}

DDS::Boolean TemplateDataReaderView::_local_is_a (const char * _id)
{
   if (strcmp (_id, TemplateDataReaderView::_local_id) == 0)
   {
      return true;
   }

   typedef DDS::DataReaderView NestedBase_1;

   if (NestedBase_1::_local_is_a (_id))
   {
      return true;
   }

   return false;
}

TemplateDataReaderView_ptr TemplateDataReaderView::_narrow (DDS::Object_ptr p)
{
   TemplateDataReaderView_ptr result = NULL;
   if (p && p->_is_a (TemplateDataReaderView::_local_id))
   {
      result = dynamic_cast < TemplateDataReaderView_ptr> (p);
      if (result) result->m_count++;
   }
   return result;
}

TemplateDataReaderView_ptr TemplateDataReaderView::_unchecked_narrow (DDS::Object_ptr p)
{
   TemplateDataReaderView_ptr result;
   result = dynamic_cast < TemplateDataReaderView_ptr> (p);
   if (result) result->m_count++;
   return result;
}

const char * SensorTypeSupportInterface::_local_id = "IDL:SensorTypeSupportInterface:1.0";

SensorTypeSupportInterface_ptr SensorTypeSupportInterface::_duplicate (SensorTypeSupportInterface_ptr p)
{
   if (p) p->m_count++;
   return p;
}

DDS::Boolean SensorTypeSupportInterface::_local_is_a (const char * _id)
{
   if (strcmp (_id, SensorTypeSupportInterface::_local_id) == 0)
   {
      return true;
   }

   typedef DDS::TypeSupport NestedBase_1;

   if (NestedBase_1::_local_is_a (_id))
   {
      return true;
   }

   return false;
}

SensorTypeSupportInterface_ptr SensorTypeSupportInterface::_narrow (DDS::Object_ptr p)
{
   SensorTypeSupportInterface_ptr result = NULL;
   if (p && p->_is_a (SensorTypeSupportInterface::_local_id))
   {
      result = dynamic_cast < SensorTypeSupportInterface_ptr> (p);
      if (result) result->m_count++;
   }
   return result;
}

SensorTypeSupportInterface_ptr SensorTypeSupportInterface::_unchecked_narrow (DDS::Object_ptr p)
{
   SensorTypeSupportInterface_ptr result;
   result = dynamic_cast < SensorTypeSupportInterface_ptr> (p);
   if (result) result->m_count++;
   return result;
}

const char * SensorDataWriter::_local_id = "IDL:SensorDataWriter:1.0";

SensorDataWriter_ptr SensorDataWriter::_duplicate (SensorDataWriter_ptr p)
{
   if (p) p->m_count++;
   return p;
}

DDS::Boolean SensorDataWriter::_local_is_a (const char * _id)
{
   if (strcmp (_id, SensorDataWriter::_local_id) == 0)
   {
      return true;
   }

   typedef DDS::DataWriter NestedBase_1;

   if (NestedBase_1::_local_is_a (_id))
   {
      return true;
   }

   return false;
}

SensorDataWriter_ptr SensorDataWriter::_narrow (DDS::Object_ptr p)
{
   SensorDataWriter_ptr result = NULL;
   if (p && p->_is_a (SensorDataWriter::_local_id))
   {
      result = dynamic_cast < SensorDataWriter_ptr> (p);
      if (result) result->m_count++;
   }
   return result;
}

SensorDataWriter_ptr SensorDataWriter::_unchecked_narrow (DDS::Object_ptr p)
{
   SensorDataWriter_ptr result;
   result = dynamic_cast < SensorDataWriter_ptr> (p);
   if (result) result->m_count++;
   return result;
}

const char * SensorDataReader::_local_id = "IDL:SensorDataReader:1.0";

SensorDataReader_ptr SensorDataReader::_duplicate (SensorDataReader_ptr p)
{
   if (p) p->m_count++;
   return p;
}

DDS::Boolean SensorDataReader::_local_is_a (const char * _id)
{
   if (strcmp (_id, SensorDataReader::_local_id) == 0)
   {
      return true;
   }

   typedef DDS::DataReader NestedBase_1;

   if (NestedBase_1::_local_is_a (_id))
   {
      return true;
   }

   return false;
}

SensorDataReader_ptr SensorDataReader::_narrow (DDS::Object_ptr p)
{
   SensorDataReader_ptr result = NULL;
   if (p && p->_is_a (SensorDataReader::_local_id))
   {
      result = dynamic_cast < SensorDataReader_ptr> (p);
      if (result) result->m_count++;
   }
   return result;
}

SensorDataReader_ptr SensorDataReader::_unchecked_narrow (DDS::Object_ptr p)
{
   SensorDataReader_ptr result;
   result = dynamic_cast < SensorDataReader_ptr> (p);
   if (result) result->m_count++;
   return result;
}

const char * SensorDataReaderView::_local_id = "IDL:SensorDataReaderView:1.0";

SensorDataReaderView_ptr SensorDataReaderView::_duplicate (SensorDataReaderView_ptr p)
{
   if (p) p->m_count++;
   return p;
}

DDS::Boolean SensorDataReaderView::_local_is_a (const char * _id)
{
   if (strcmp (_id, SensorDataReaderView::_local_id) == 0)
   {
      return true;
   }

   typedef DDS::DataReaderView NestedBase_1;

   if (NestedBase_1::_local_is_a (_id))
   {
      return true;
   }

   return false;
}

SensorDataReaderView_ptr SensorDataReaderView::_narrow (DDS::Object_ptr p)
{
   SensorDataReaderView_ptr result = NULL;
   if (p && p->_is_a (SensorDataReaderView::_local_id))
   {
      result = dynamic_cast < SensorDataReaderView_ptr> (p);
      if (result) result->m_count++;
   }
   return result;
}

SensorDataReaderView_ptr SensorDataReaderView::_unchecked_narrow (DDS::Object_ptr p)
{
   SensorDataReaderView_ptr result;
   result = dynamic_cast < SensorDataReaderView_ptr> (p);
   if (result) result->m_count++;
   return result;
}



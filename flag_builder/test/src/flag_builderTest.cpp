// -*- C++ -*-
/*!
 * @file  flag_builderTest.cpp
 * @brief ModuleDescription
 * @date $Date$
 *
 * $Id$
 */

#include "flag_builderTest.h"

// Module specification
// <rtc-template block="module_spec">
static const char* flag_builder_spec[] =
  {
    "implementation_id", "flag_builderTest",
    "type_name",         "flag_builderTest",
    "description",       "ModuleDescription",
    "version",           "1.0.0",
    "vendor",            "shirai",
    "category",          "Category",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    // Configuration variables
    "conf.default.Denominator", "10000",
    "conf.default.Flag", "5000",

    // Widget
    "conf.__widget__.Denominator", "text",
    "conf.__widget__.Flag", "text",
    // Constraints

    "conf.__type__.Denominator", "double",
    "conf.__type__.Flag", "double",

    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
flag_builderTest::flag_builderTest(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_DataInIn("DataIn", m_DataIn),
    m_DataOutOut("DataOut", m_DataOut)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
flag_builderTest::~flag_builderTest()
{
}



RTC::ReturnCode_t flag_builderTest::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("DataOut", m_DataOutIn);
  
  // Set OutPort buffer
  addOutPort("DataIn", m_DataInOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  bindParameter("Denominator", m_Denominator, "10000");
  bindParameter("Flag", m_Flag, "5000");
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t flag_builderTest::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t flag_builderTest::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t flag_builderTest::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t flag_builderTest::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t flag_builderTest::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t flag_builderTest::onExecute(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t flag_builderTest::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t flag_builderTest::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t flag_builderTest::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t flag_builderTest::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t flag_builderTest::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void flag_builderTestInit(RTC::Manager* manager)
  {
    coil::Properties profile(flag_builder_spec);
    manager->registerFactory(profile,
                             RTC::Create<flag_builderTest>,
                             RTC::Delete<flag_builderTest>);
  }
  
};



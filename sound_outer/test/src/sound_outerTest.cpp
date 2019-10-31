// -*- C++ -*-
/*!
 * @file  sound_outerTest.cpp
 * @brief ModuleDescription
 * @date $Date$
 *
 * $Id$
 */

#include "sound_outerTest.h"

// Module specification
// <rtc-template block="module_spec">
static const char* sound_outer_spec[] =
  {
    "implementation_id", "sound_outerTest",
    "type_name",         "sound_outerTest",
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
    "conf.default.Sound_File", "hirate_uti.mp3",

    // Widget
    "conf.__widget__.Sound_File", "text",
    // Constraints

    "conf.__type__.Sound_File", "string",

    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
sound_outerTest::sound_outerTest(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_volume_percentageIn("volume_percentage", m_volume_percentage)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
sound_outerTest::~sound_outerTest()
{
}



RTC::ReturnCode_t sound_outerTest::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  
  // Set OutPort buffer
  addOutPort("volume_percentage", m_volume_percentageOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  bindParameter("Sound_File", m_Sound_File, "hirate_uti.mp3");
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t sound_outerTest::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t sound_outerTest::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t sound_outerTest::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t sound_outerTest::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t sound_outerTest::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t sound_outerTest::onExecute(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t sound_outerTest::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t sound_outerTest::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t sound_outerTest::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t sound_outerTest::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t sound_outerTest::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void sound_outerTestInit(RTC::Manager* manager)
  {
    coil::Properties profile(sound_outer_spec);
    manager->registerFactory(profile,
                             RTC::Create<sound_outerTest>,
                             RTC::Delete<sound_outerTest>);
  }
  
};



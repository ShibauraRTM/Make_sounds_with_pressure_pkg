// -*- C++ -*-
/*!
 * @file  flag_builder.cpp
 * @brief ModuleDescription
 * @date $Date$
 *
 * $Id$
 */

#include "flag_builder.h"

// Module specification
// <rtc-template block="module_spec">
static const char* flag_builder_spec[] =
  {
    "implementation_id", "flag_builder",
    "type_name",         "flag_builder",
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
flag_builder::flag_builder(RTC::Manager* manager)
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
flag_builder::~flag_builder()
{
}



RTC::ReturnCode_t flag_builder::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("DataIn", m_DataInIn);
  
  // Set OutPort buffer
  addOutPort("DataOut", m_DataOutOut);
  
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
RTC::ReturnCode_t flag_builder::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t flag_builder::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t flag_builder::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t flag_builder::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t flag_builder::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t flag_builder::onExecute(RTC::UniqueId ec_id)
{


	if (m_DataInIn.isNew()) {
		m_DataInIn.read();
		if (m_DataIn.data > m_Flag) {
			if (flag == 0) {
				m_DataOut.data = m_DataIn.data/m_Denominator;
				m_DataOutOut.write();
				flag = 1;
			}
		}
		else {
			flag = 0;
		}
	}
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t flag_builder::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t flag_builder::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t flag_builder::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t flag_builder::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t flag_builder::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void flag_builderInit(RTC::Manager* manager)
  {
    coil::Properties profile(flag_builder_spec);
    manager->registerFactory(profile,
                             RTC::Create<flag_builder>,
                             RTC::Delete<flag_builder>);
  }
  
};


